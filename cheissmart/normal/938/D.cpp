#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e18 + 7;

int d[200005];
vector<pi> G[200005];

int32_t main()
{
	IO_OP;
	
	int n, m;
	cin >> n >> m;
	for(int i=0;i<m;i++) {
		int u, v, w;
		cin >> u >> v >> w;
		G[u].EB(v, w*2);
		G[v].EB(u, w*2);
	}
	for(int i=1;i<=n;i++) {
		int a;
		cin >> a;
		G[0].EB(i, a);
		G[i].EB(0, a);
	}
	priority_queue<pi, vector<pi>, greater<pi>> pq;
	pq.push({0, 0});
	fill(d+1, d+n+1, INF);
	while(pq.size()) {
		pi p = pq.top(); pq.pop();
		if(p.F > d[p.S]) continue;
		for(pi u:G[p.S]) {
			if(p.F + u.S < d[u.F]) {
				d[u.F] = p.F + u.S;
				pq.push({d[u.F], u.F});
			} 
		}
	}
	for(int i=1;i<=n;i++)
		cout << d[i] << " ";
}