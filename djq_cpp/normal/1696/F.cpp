#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, dis[105][105];
vector<PII> E;
vector<int> T[105];
char buf[105];
bool con[105][105][105];

bool vis[105];
void dfs(int v, int p)
{
	vis[v] = true;
	rep(i, n) if(con[v][p][i] && !vis[i]) {
		E.push_back(MP(i, v));
		T[i].push_back(v); T[v].push_back(i);
		dfs(i, v);
	}
}
void dfs1(int v, int ret[], int p)
{
	rep(i, T[v].size()) {
		int u = T[v][i];
		if(u == p) continue;
		ret[u] = ret[v] + 1;
		dfs1(u, ret, v);
	}
}
bool check(int u, int v)
{
	E.clear();
	rep(i, n) T[i].clear();
	rep(i, n) vis[i] = false;
	dfs(u, v);
	rep(i, n) if(!vis[i]) return false;
	rep(i, n) {
		rep(j, n) vis[j] = false;
		dfs1(i, dis[i], -1);
	}
	rep(i, n) rep(j, n) rep(k, j) if((dis[i][j] == dis[i][k]) != con[i][j][k]) return false;
	return true;
}

void solve()
{
	scanf("%d", &n);
	rep(i, n) for(int j = i + 1; j < n; j ++) {
		scanf("%s", buf);
		rep(k, n) con[k][i][j] = con[k][j][i] = buf[k] & 1;
	}
	rep(i, n) rep(j, n) con[i][j][j] = true;
	rep1(i, n - 1) if(check(0, i)) {
		printf("Yes\n");
		rep(j, E.size()) printf("%d %d\n", E[j].first + 1, E[j].second + 1);
		return;
	}
	printf("No\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}