#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, m;
vector<int> G[100005];
bool vis[100005];
void dfs(int v)
{
	vis[v] = true;
	rep(i, G[v].size()) if(!vis[G[v][i]]) dfs(G[v][i]);
}
void solve()
{
	scanf("%d%d", &n, &m);
	rep1(i, n) G[i].clear();
	
	int ans = -n;
	rep(i, m) {
		int u, v;
		scanf("%d%d", &u, &v);
		if(u == v) continue;
		ans += 2;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	rep1(i, n) vis[i] = false;
	
	rep1(i, n) if(!vis[i]) {
		dfs(i); ans ++;
	}
	
	printf("%d\n", ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}