#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define all(x) x.begin(), x.end()
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
// c0 3f
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

const int N = 4e5 + 50;
const int M = 20;
const int MOD = 998244353;

int n, m, a, b;
vector <pii> G[N];	
pii D[N];
set <pair<pii, int>> S;
int DD[N][M];
deque <pii> Q;

int main() {
	scanf ("%d%d", &n, &m);
	rep(i, 1, m) {
		scanf ("%d%d", &a, &b);
		G[2 * a - 1].pb(mp(2 * b - 1, 0));
		G[2 * b].pb(mp(2 * a, 0));
	}
	rep(i, 1, n) {
		G[2 * i - 1].pb(mp(2 * i, 1));
		G[2 * i].pb(mp(2 * i - 1, 1));
	}
	fill(D, D + N, mp(MOD, MOD));
	D[1] = mp(0, 0);
	S.insert(mp(mp(0, 0), 1));
	while (sz(S)) {
		int v = S.begin()->se;
		S.erase(S.begin());
		for (auto [u, w] : G[v]) {
			pii newd = mp(D[v].fi + w, D[v].se + !w);
			if (newd < D[u]) {
				S.erase(mp(D[u], u));
				D[u] = newd;
				S.insert(mp(D[u], u));
			}
		}
	}
	pii best = min(D[2 * n - 1], D[2 * n]);
	if (M <= best.fi) {
		int res = best.se, pt = 1;
		rep(i, 1, best.fi) {
			res = (res + pt) % MOD;
			pt = 2 * pt % MOD;
		}
		return !printf ("%d\n", res);
	}
	rep(i, 1, 2 * n)
		rep(j, 0, M - 1)
			DD[i][j] = MOD;
	DD[1][0] = 0;
	Q.pb(mp(1, 0));
	while (sz(Q)) {
		auto [v, k] = Q.front();
		Q.pop_front();
		for (auto [u, w] : G[v]) {
			int nk = k + w, nd = DD[v][k] + !w;
			if (nk < M && DD[u][nk] == MOD) {
				DD[u][nk] = nd;
				if (w == 1) Q.push_front(mp(u, nk));
				if (w == 0) Q.push_back(mp(u, nk));
			}
		}
	}
	int ans = MOD;
	rep(i, 0, M - 1) 
		ans = min(ans, min(DD[2 * n][i], DD[2 * n - 1][i]) + (1 << i) - 1);
	printf ("%d\n", ans);
	return 0;
}