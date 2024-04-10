#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, K;
vector<int> adj[202020];
int dfn[202020];
int ed[202020];
int dep[202020];
int vn[202020];
int id;
int up[202020];
bool chk[202020];

struct Node {
	int mx = 0, lz = 0;
};

struct SegTree {
	Node T[4 * 202020];

	void propa(int idx, int s, int e) {
		T[idx].mx += T[idx].lz;
		if(s != e) {
			T[idx << 1].lz += T[idx].lz;
			T[idx << 1 | 1].lz += T[idx].lz;
		}
		T[idx].lz = 0;
	}

	void upd(int idx, int s, int e, int p, int q, int x) {
		propa(idx, s, e);
		if(q < p || q < s || e < p) return;
		if(p <= s && e <= q) {
			T[idx].lz += x;
			propa(idx, s, e);
			return;
		}
		int m = s + e >> 1;
		upd(idx << 1, s, m, p, q, x);
		upd(idx << 1 | 1, m + 1, e, p, q, x);
		T[idx].mx = max(T[idx << 1].mx, T[idx << 1 | 1].mx);
	}

	void upd(int p, int q, int x) { upd(1, 1, N, p, q, x); }
	int get() {
		propa(1, 1, N);
		return T[1].mx;
	}

	int query() {
		int idx = 1;
		int s = 1, e = N;
		int mx = get();

		while(s < e) {
			int m = s + e >> 1;
			propa(idx << 1, s, m);
			propa(idx << 1 | 1, m + 1, e);
			if(T[idx << 1].mx == mx) {
				idx = idx << 1;
				e = m;
			}
			else {
				idx = idx << 1 | 1;
				s = m + 1;
			}
		}
		return s;
	}
}seg;

void dfs(int v, int p) {
	dep[v] = dep[p] + 1;
	dfn[v] = ++id;
	up[v] = p;
	for(int i : adj[v]) {
		if(i == p) continue;
		dfs(i, v);
	}
	ed[v] = id;
}

ll f(int r, int b) {
	return (ll)(N - r - b) * (r - b);
}

ll calc(int r, int b_lim) {
	ll ret = f(r, b_lim);
	if(b_lim >= N / 2) ret = min(ret, f(r, N / 2));
	if(b_lim >= (N + 1) / 2) ret = min(ret, f(r, (N + 1) / 2));
	return ret;
}

int main() {
	scanf("%d%d", &N, &K);
	for(int i = 1; i < N; i++) {
		int a, b; scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 0);
	for(int i = 1; i <= N; i++) vn[dfn[i]] = i;
	for(int i = 1; i <= N; i++) seg.upd(i, i, dep[vn[i]]);

	ll ans = -1LL << 60;
	
	int b = N;
	for(int i = 1; i <= K; i++) {
		int x = seg.T[1].mx;
		b -= x;
		int v = seg.query();
		v = vn[v];
		while(v && !chk[v]) {
			chk[v] = true;
			seg.upd(dfn[v], ed[v], -1);
			v = up[v];
		}
		ans = max(ans, calc(i, b));
	}
	printf("%lld\n", ans);

	return 0;
}