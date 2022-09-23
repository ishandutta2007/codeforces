#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N, M;
vector<int> adj[303030];
int dfn[303030];
int ed[303030];
int id;

int st[20][303030];
int dep[303030];
int th[303030];

int cntP[303030];
vector<int> cnt[303030];
int point[303030];
vector<pii> ps[303030];

struct FWT {
	int T[303030] = {0, };

	void upd(int x, int v) {
		for(int i = x; i <= N; i += i&-i) T[i] += v;
	}
	int get(int x) {
		int ret = 0;
		for(int i = x; i; i -= i&-i) ret += T[i];
		return ret;
	}
	int query(int l, int r) {
		return get(r) - get(l - 1);
	}
}fwt;

void dfs(int v, int p) {
	dfn[v] = ++id;
	st[0][v] = p;
	dep[v] = dep[p] + 1;
	int c = 0;
	for(int i : adj[v]) {
		if(i != p) {
			th[i] = c++;
			dfs(i, v);
		}
	}
	cnt[v].resize(c);
	ed[v] = id;
}

int lca(int a, int b) {
	if(dep[a] < dep[b]) swap(a, b);
	for(int i = 19; i >= 0; i--) {
		if(dep[st[i][a]] < dep[b]) continue;
		a = st[i][a];
	}
	if(a == b) return a;
	for(int i = 19; i >= 0; i--) {
		if(st[i][a] == st[i][b]) continue;
		a = st[i][a]; b = st[i][b];
	}
	return st[0][a];
}

int up(int v, int u) {
	for(int i = 19; i >= 0; i--) {
		if(dep[st[i][v]] <= dep[u]) continue;
		v = st[i][v];
	}
	return v;
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i < N; i++) {
		int a, b; scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 0);
	for(int i = 1; i <= 19; i++) {
		for(int j = 1; j <= N; j++) st[i][j] = st[i - 1][st[i - 1][j]];
	}

	scanf("%d", &M);
	for(int i = 1; i <= M; i++) {
		int a, b; scanf("%d%d", &a, &b);
		if(a == b) { point[a]++; continue; }
		if(dep[a] < dep[b]) swap(a, b);
		int l = lca(a, b);
		if(l == b) {
			fwt.upd(dfn[a], 1);
			int v = up(a, b);
			fwt.upd(dfn[v], -1);
			cntP[a]++;
			cnt[b][th[v]]++;
		}
		else {
			int ua = up(a, l);
			int ub = up(b, l);
			fwt.upd(dfn[a], 1);
			fwt.upd(dfn[b], 1);
			fwt.upd(dfn[ua], -1);
			fwt.upd(dfn[ub], -1);
			cntP[a]++; cntP[b]++;
			if(th[ua] > th[ub]) swap(ua, ub);
			ps[l].emplace_back(th[ua], th[ub]);
		}
	}

	ll ans = 0;
	for(int i = 1; i <= N; i++) {
		ll c0 = point[i];
		ll c1 = cntP[i];
		ll c2 = ps[i].size();

		int c = 0;
		ll cntP2 = 0;
		vector<int> v;
		for(int j : adj[i]) {
			if(j == st[0][i]) continue;
			c1 += cnt[i][c];
			int t = fwt.query(dfn[j], ed[j]);
			c2 += t;
			cntP2 += t;
			v.push_back(t);
			c++;
		}

		// printf("%d\n", i);
		// printf("%lld %lld %lld\n", c0, c1, c2);

		vector<int> w(c, 0);
		for(pii j : ps[i]) {
			w[j.first]++;
			w[j.second]++;
		}
		for(int j = 0; j < c; j++) w[j] += v[j];

		ans += c0 * (c0 + c1 + c2);
		ans -= c0 * (c0 - 1) / 2;
		ans -= c0;

		ans += c1 * (c1 - 1) / 2;
		ans -= (ll)cntP[i] * (cntP[i] - 1) / 2;
		for(int j = 0; j < c; j++) {
			ans -= (ll)cnt[i][j] * (cnt[i][j] - 1) / 2;
		}

		ans += c1 * c2;
		for(int j = 0; j < c; j++) {
			ans -= (ll)cnt[i][j] * w[j];
		}
		ans -= (ll)cntP[i] * cntP2;

		ans += c2 * (c2 - 1) / 2;
		for(int j = 0; j < c; j++) {
			ans -= (ll)w[j] * (w[j] - 1) / 2;
		}
		ans -= (ll)cntP2 * (cntP2 - 1) / 2;

		for(int j = 0; j < c; j++) {
			ans += (ll)v[j] * (v[j] - 1) / 2;
		}

		sort(ps[i].begin(), ps[i].end());
		int tmp = 0;
		for(int j = 0; j < ps[i].size(); j++) {
			if(j && ps[i][j] == ps[i][j - 1]) tmp++;
			else tmp = 0;
			ans += tmp;
		}
		// printf("ans %lld\n", ans);
	}
	printf("%lld\n", ans);
	return 0;
}