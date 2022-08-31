#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, w[200005];
vector<PII> G[200005];
bool del[200005];
int dep[200005], siz[200005];
double tot[200005];

void gen_siz(int v, int par)
{
	siz[v] = 1;
	rep(i, G[v].size()) {
		int u = G[v][i].first;
		if(del[u] || u == par) continue;
		gen_siz(u, v);
		siz[v] += siz[u];
	}
}

int gen_cent(int v, int par, int csz)
{
	rep(i, G[v].size()) {
		int u = G[v][i].first;
		if(del[u] || u == par) continue;
		if(siz[u] * 2 > csz) return gen_cent(u, v, csz);
	}
	return v;
}

double gen_info(int v, int par, int cdep)
{
	dep[v] = cdep;
	tot[v] = sqrt(dep[v]) * w[v];
	double ret = dep[v] * tot[v];
	rep(i, G[v].size()) {
		int u = G[v][i].first;
		if(u == par) continue;
		ret += gen_info(u, v, cdep + G[v][i].second);
		tot[v] += tot[u];
	}
	return ret;
}

pair<double, int> solve(int rt)
{
	gen_siz(rt, -1);
	rt = gen_cent(rt, -1, siz[rt]);
	pair<double, int> ret = MP(gen_info(rt, -1, 0), rt);
	del[rt] = true;
	int cu = -1;
	rep(i, G[rt].size()) {
		int u = G[rt][i].first;
		if(del[u]) continue;
		if(cu == -1 || tot[u] > tot[cu]) cu = u;
	}
	if(cu != -1) ret = min(ret, solve(cu));
	return ret;
}

int main()
{
	scanf("%d", &n);
	rep1(i, n) scanf("%d", &w[i]);
	rep(i, n - 1) {
		int u, v, l;
		scanf("%d%d%d", &u, &v, &l);
		G[u].push_back(MP(v, l));
		G[v].push_back(MP(u, l));
	}
	
	pair<double, int> ans = solve(1);
	printf("%d %.8lf\n", ans.second, ans.first);
	return 0;
}