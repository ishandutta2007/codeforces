#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 200005;

vi G[N], rG[N], pre[N];
int p[N], vis[N], d[N], n, m;

void BFS(int t) {
	vi q({t});
	vis[t] = 1, d[t] = 0;
	for(int i=0;i<q.size();i++) {
		int u = q[i];
		for(int v:rG[u]) {
			if(!vis[v]) {
				vis[v] = 1;
				d[v] = d[u] + 1;
				q.PB(v);
				pre[v].PB(u);
			} else {
				if(d[v] == d[u] + 1) {
					pre[v].PB(u);
					vis[v]++;
				}
			}
		}
	}
}

signed main()
{
	IO_OP;
	
	cin >> n >> m;
	for(int i=0;i<m;i++) {
		int u, v;
		cin >> u >> v;
		G[u].PB(v);
		rG[v].PB(u);
	}	
	int k;
	cin >> k;
	for(int i=0;i<k;i++)
		cin >> p[i];
	int t = p[k-1];
	BFS(t);
	int mx = 0, mn = 0;
	for(int i=0;i<k-1;i++) {
		int u = p[i];
		bool yes = false, no = false;
		for(int v:pre[u]) {
			if(v != p[i+1]) no = true;
			else yes = true;
		}
		if(!yes) mn++;
		if(no) mx++;
	}
	cout << mn << " " << mx << endl;
}