#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(c) c.begin(),c.end()
#define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e18;

int e[300005][3];
vi G[300005];
int d[300005], in[300005];
bool done[300005];

signed main()
{
	IO_OP;

	int n, m, k;
	cin >> n >> m >> k;
	for(int i=0;i<m;i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		e[i][0] = u, e[i][1] = v, e[i][2] = w;
		G[u].PB(i);
		G[v].PB(i);
	}
	for(int i=1;i<n;i++)
		d[i] = INF;
	priority_queue<pi, vector<pi>, greater<pi>> pq;
	pq.push({0, 0});
	int cnt=0;
	while (pq.size() && cnt < k+1) {
		pi p = pq.top(); pq.pop();
		if(p.F > d[p.S]) continue;
		cnt++;
		done[p.S] = true;
		for(int i:G[p.S]) {
			if( p.F+e[i][2] < d[p.S^e[i][0]^e[i][1]]) {
				pq.push({ p.F+e[i][2],p.S^e[i][0]^e[i][1]});
				d[p.S^e[i][0]^e[i][1]] = p.F+e[i][2];
				in[p.S^e[i][0]^e[i][1]] = i;
			}
		}
	}
	cout << cnt-1 << endl;
	for(int i=1;i<n;i++) {
		if(done[i])
			cout << in[i] + 1 << ' ';
	}
}