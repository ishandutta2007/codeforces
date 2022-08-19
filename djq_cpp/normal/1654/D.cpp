#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int inv[200005];
vector<PII> ps[200005];
int n;
vector<pair<int, PII> > G[200005];
int cc[200005], mn[200005], ans;
void dfs(int v, int p, int coef)
{
	ans = (ans + coef) % MOD;
	rep(i, G[v].size()) {
		int u = G[v][i].first;
		if(u == p) continue;
		int y = G[v][i].second.first, x = G[v][i].second.second;
		rep(j, ps[y].size()) cc[ps[y][j].first] -= ps[y][j].second;
		rep(j, ps[x].size()) mn[ps[x][j].first] = max(mn[ps[x][j].first], cc[ps[x][j].first] += ps[x][j].second);
		dfs(u, v, 1LL * coef * y % MOD * inv[x] % MOD);
		rep(j, ps[y].size()) cc[ps[y][j].first] += ps[y][j].second;
		rep(j, ps[x].size()) cc[ps[x][j].first] -= ps[x][j].second;
	}
}
void solve()
{
	scanf("%d", &n);
	rep1(i, n) G[i].clear();
	rep(i, n - 1) {
		int u, v, x, y;
		scanf("%d%d%d%d", &u, &v, &x, &y);
		G[u].push_back(MP(v, MP(y, x)));
		G[v].push_back(MP(u, MP(x, y)));
	}
	
	rep1(i, n) mn[i] = 0;
	ans = 0;
	dfs(1, 0, 1);
	rep1(i, n) rep(j, mn[i]) ans = 1LL * ans * i % MOD;
	printf("%d\n", ans);
}

int main()
{
	rep1(i, 200000) inv[i] = i == 1 ? 1 : MOD - 1LL * inv[MOD % i] * (MOD / i) % MOD;
	for(int i = 2; i <= 200000; i ++) if(ps[i].empty())
	for(int j = i; j <= 200000; j += i) {
		ps[j].push_back(MP(i, 0));
		int cj = j;
		do {
			cj /= i; ps[j].back().second ++;
		} while(cj % i == 0);
	}
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}