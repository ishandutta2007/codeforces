#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define ALL(c) c.begin(),c.end()
#define INF int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int N = 5005;

vi G[N], G2[N], vs;
int vis[N], vis1[N], cc[N], id[N];

void dfs(int u) {
	vis[u]=1;
	for(auto& v : G[u]) {
		if(vis[v]==0) {
			dfs(v);
		}
	}
	vs.PB(u);
}

void dfs(int u, int k) {
	vis1[u] = 1;
	cc[u] = k;
	for(auto& v : G2[u]) {
		if(vis1[v]==0) {
			dfs(v, k);
		}
	}
}

int main()
{
	IO_OP;

	int n, m, s;
	cin >> n >> m >> s;
	s--;
	for(int i=0;i<m;i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		G[u].PB(v);
		G2[v].PB(u);
	}
	for(int i=0;i<n;i++)
		if(vis[i] == 0)
			dfs(i);
	int k = 0;
	for(int i=n-1;i>=0;i--)
		if(vis1[vs[i]] == 0)
			dfs(vs[i], k++);
	for(int u=0;u<n;u++)
		for(int v:G[u])
			if(cc[u] != cc[v])
				id[cc[v]]++;
	int ans = 0;
	for(int i=0;i<k;i++)
		ans += id[i] == 0;
	ans -= id[cc[s]] == 0;
	cout << ans << endl;
}