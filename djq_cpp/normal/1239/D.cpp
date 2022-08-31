#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
 
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;
 
int n, m;
vector<int> G[1000005];
int grp[1000005], gcnt;
 
bool vis[1000005];
vector<int> rG[1000005];
vector<int> postv;
 
void dfs0(int v)
{
	vis[v] = true;
	rep(i, G[v].size()) if(!vis[G[v][i]]) dfs0(G[v][i]);
	postv.push_back(v);
}
 
void dfs1(int v, int col)
{
	grp[v] = col;
	vis[v] = true;
	rep(i, rG[v].size()) if(!vis[rG[v][i]]) dfs1(rG[v][i], col);
}
 
void korasaju()
{
	rep1(i, n) vis[i] = false;
	postv.clear();
	rep1(i, n) if(!vis[i]) dfs0(i);
	
	rep1(i, n) rG[i].clear();
	rep1(i, n) rep(j, G[i].size()) rG[G[i][j]].push_back(i);
	gcnt = 0;
	reverse(postv.begin(), postv.end());
	rep1(i, n) vis[i] = false;
	rep(i, postv.size()) if(!vis[postv[i]]) dfs1(postv[i], gcnt ++);
}
 
void solve()
{
	scanf("%d%d", &n, &m);
	rep1(i, n) G[i].clear();
	rep(i, m) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
	}
	korasaju();
	if(gcnt == 1) {
		printf("No\n");
		return;
	}
	printf("Yes\n");
	vector<int> a0, a1;
	rep1(i, n) if(grp[i] == 0) a1.push_back(i);
	else a0.push_back(i);
	printf("%d %d\n", (int)a0.size(), (int)a1.size());
	rep(i, a0.size()) printf("%d ", a0[i]); printf("\n");
	rep(i, a1.size()) printf("%d ", a1[i]); printf("\n");
}
 
int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}