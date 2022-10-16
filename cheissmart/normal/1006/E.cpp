#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(c) c.begin(),c.end()
#define INF int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

int vis[200005], pos[200005], sub[200005];
vi G[200005], vs;

void dfs(int u) {
	vis[u] = 1;
	sub[u] = 1;
	vs.PB(u);
	for(auto& v : G[u]) {
		if(vis[v]==0) {
			dfs(v);
			sub[u] += sub[v];
		}
	}
}

int main()
{
	IO_OP;

	int n, q;
    cin >> n >> q;
  	for(int i=1;i<n;i++) {
		int v;
		cin >> v;
		v--;
		G[v].PB(i);
	}
	for(int i=0;i<n;i++)
		sort(G[i].begin(), G[i].end());
	dfs(0);
	for(int i=0;i<n;i++)
		pos[vs[i]] = i;
	while (q--) {
		int u, k;
		cin >> u >> k;
		u--;
		if(k > sub[u])  {
			cout << -1 << endl;
			continue;
		}
		cout << vs[pos[u]+k-1] + 1 << endl;
	}
}