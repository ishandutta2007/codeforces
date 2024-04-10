#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, m, cnt;
pair<int, PII> E[200005];

int rt[400005];
int root(int x)
{
	return rt[x] == x ? x : rt[x] = root(rt[x]);
}
int T[400005][2], par[400005], cw[400005], cw2[400005], siz[400005], mr[400005];
int lca(int u, int v)
{
	while(mr[u] != mr[v]) {
		if(mr[u] > mr[v]) swap(u, v);
		u = par[mr[u]];
	}
	return u > v ? u : v;
}

int del[400005]; 
vector<PII> fe[400005];
vector<int> gr[400005], fet[400005];

PII F[200005];
void solve()
{
	scanf("%d%d", &n, &m);
	rep(i, m) {
		scanf("%d%d%d", &E[i].second.first, &E[i].second.second, &E[i].first); F[i] = E[i].second;
	}
	sort(E, E + m);
	
	cnt = n;
	rep1(i, n * 2 - 1) rt[i] = i;
	rep(i, m) {
		int u = root(E[i].second.first), v = root(E[i].second.second);
		if(u == v) continue;
		cnt ++;
		par[u] = par[v] = rt[u] = rt[v] = cnt; par[cnt] = 0;
		T[cnt][0] = u; T[cnt][1] = v; cw[cnt] = i;
	}
	
	rep1(i, cnt) {
		siz[i] = i <= n ? 1 : siz[T[i][0]] + siz[T[i][1]]; mr[i] = i;
	}
	for(int i = cnt; i > n; i --) mr[siz[T[i][0]] > siz[T[i][1]] ? T[i][0] : T[i][1]] = mr[i];
	
	for(int i = n + 1; i <= cnt; i ++) fe[i].clear();
	rep(i, m) fe[lca(E[i].second.first, E[i].second.second)].push_back(E[i].second);
	
	cnt = n;
	rep1(i, n * 2 - 1) rt[i] = i;
	rep1(i, n * 2 - 1) gr[i].clear();
	rep1(i, n) gr[i].push_back(i);
	for(int i = n + 1; i <= 2 * n - 1; i ++) {
		int u = T[i][0], v = T[i][1];
		rep(j, gr[v].size()) fet[gr[v][j]].clear();
		rep(j, fe[i].size()) {
			int cu = root(fe[i][j].first), cv = root(fe[i][j].second);
			fet[cu].push_back(cv); fet[cv].push_back(cu);
		}
		rep(j, gr[v].size()) {
			int cv = gr[v][j], nv = cv;
			rep(k, gr[u].size()) del[gr[u][k]] = 0;
			rep(k, fet[cv].size()) del[root(fet[cv][k])] ++;
			rep(k, gr[u].size()) {
				int cu = gr[u][k];
				if(del[cu] == 1LL * siz[cv] * siz[cu]) continue;
				par[cu] = par[nv] = rt[cu] = rt[nv] = ++ cnt; par[cnt] = 0;
				cw2[cnt] = cw[i]; siz[cnt] = siz[cu] + (nv == cv ? 0 : siz[nv]); nv = cnt;
			}
			int len = 0;
			rep(k, gr[u].size()) {
				int cu = gr[u][k];
				if(root(cu) != nv) gr[u][len ++] = cu;
			}
			gr[u].resize(len);
			if(nv != cv) gr[u].push_back(nv);
			else gr[i].push_back(cv);
		}
		rep(j, gr[v].size()) {
			int cv = gr[v][j];
			if(cv != root(cv)) siz[root(cv)] += siz[cv];
		}
		rep(j, gr[u].size()) gr[i].push_back(gr[u][j]);
	}
	
	rep1(i, cnt) mr[i] = i;
	for(int i = n + 1; i <= cnt; i ++) siz[i] = 0;
	rep1(i, cnt - 1) siz[par[i]] += siz[i];
	for(int i = cnt - 1; i >= 1; i --) if(siz[i] * 2 > siz[par[i]]) mr[i] = mr[par[i]];
	
	rep(i, m) printf("%d%c", E[cw2[lca(F[i].first, F[i].second)]].first, " \n"[i == m - 1]);
}

int main()
{
	int N;
	scanf("%d", &N);
	while(N --) solve();
	return 0;
}