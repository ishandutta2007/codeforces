#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
#define EPS 1e-7
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos(0);

const int maxn = 15;
int n, m, q;
vi adj[maxn];
vii lca[maxn];
vi submsk[1 << maxn];
ll f[maxn][maxn][1 << maxn];

int bit(int n, int k) {
	return (n & (1 << k)) > 0;
}

int check(int u, int v, int msk) {
	FOR(i, 0, sz(adj[u])) {
		int w = adj[u][i];
		if (bit(msk, w)) return 0;
	}
	FOR(i, 0, sz(lca[u])) {
		int a = lca[u][i].fi;
		int b = lca[u][i].se;
		if (bit(msk | (1 << v), a) && bit(msk | (1 << v), b)) return 0;
	}
	FOR(i, 0, sz(adj[v])) {
		int w = adj[v][i];
		if (w != u && !bit(msk, w)) return 0;
	}
	FOR(i, 0, sz(lca[v])) {
		int a = lca[v][i].fi;
		int b = lca[v][i].se;
		if (!bit(msk | (1 << v), a) || !bit(msk | (1 << v), b)) return 0;
	}
	return 1;
}

ll calc(int u, int prv, int msk) {
	if (!msk) return 1;
	ll& res = f[u][prv][msk];
	if (~res) return res;
	res = 0;
	FOR(i, prv + 1, n) if (bit(msk, i)) {
		int t = msk ^ (1 << i);
		FOR(j, 0, sz(submsk[t])) {
			int _msk = submsk[t][j];
		 	if (check(u, i, _msk))
		 		res += calc(i, 0, _msk) * calc(u, i, msk ^ _msk ^ (1 << i));
		}
		return res = res + calc(u, i, msk);
	}
	return res;
}

void solve() {
	ms(f, -1);
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < (1 << n); i += 2) {
		for (int j = 0; j < (1 << n); j += 2) {
			if ((i & j) == j) {
				submsk[i].pb(j);
			}
		}
	}
	FOR(i, 0, m) {
		int u, v; scanf("%d%d", &u, &v); u--; v--;
		adj[u].pb(v); adj[v].pb(u);
	}
	FOR(i, 0, q) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c); a--; b--; c--;
		lca[c].pb(mp(a, b));
	}
	printf("%I64d", calc(0, 0, ((1 << n) - 1) ^ 1));
}

int main() {
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}