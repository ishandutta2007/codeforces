#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcount(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pi;
typedef vector<ll> vi;
typedef vector<pi> vii;
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos((ld) 0);
const ld EPS = 1e-9;
ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> void setmin(T& a, T val) {if (a > val) a = val;}
template<class T> void setmax(T& a, T val) {if (a < val) a = val;}
void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

const int maxn = 1000010;
int n, m;
int a[maxn];
map<int, int> dc;
vii que[maxn];
int pre[maxn];
int suf[maxn];
int ans[maxn];
int x[maxn];
int y[maxn];
ll z[maxn];
ll t[maxn];
int dmax;
ll tot;

struct Fenwick {
	int fen[maxn + 10];
	ll tot[maxn + 10];
	void update(int p, int x, ll y) {
		for (; p < maxn + 10; p += p & -p) {
			if (fen[p] < x) {
				fen[p] = x;
				tot[p] = y;
				tot[p] %= MOD;
			}
			else if (fen[p] == x) {
				tot[p] += y;
				tot[p] %= MOD;
			}
		}
	}
	pi query(int p) {
		pi res = mp(0, 1);
		for (; p > 0; p -= p & -p) {
			if (res.fi < fen[p]) {
				res.fi = fen[p];
				res.se = tot[p];
			}
			else if (res.fi == fen[p] && fen[p] > 0) {
				res.se += tot[p];
				res.se %= MOD;
			}
		}
		return res;
	}
} pfen, sfen;

void solve() {
	scanf("%d%d", &n, &m);
	FOR(i, 0, n) {
		scanf("%d", a + i);
		dc[a[i]];
	}
	FOR(i, 0, m) {
		int a, b; scanf("%d%d", &a, &b); a--;
		que[a].pb(mp(b, i));
		dc[b];
	}
	int cnt = 0; FORall(it, dc) it->se = ++cnt;
	FOR(i, 0, n) a[i] = dc[a[i]];
	FOR(i, 0, n) {
		FOR(j, 0, sz(que[i])) {
			que[i][j].fi = dc[que[i][j].fi];
		}
	}
	FOR(i, 0, n) {
		FOR(j, 0, sz(que[i])) {
			int val = que[i][j].fi;
			int idx = que[i][j].se;
			pre[idx] = pfen.query(val - 1).fi + 1;
		}
		pi r = pfen.query(a[i] - 1);
		x[i] = r.fi + 1;
		z[i] = r.se;
		pfen.update(a[i], x[i], z[i]);
		if (dmax < x[i]) {
			dmax = x[i];
			tot = z[i];
		}
		else if (dmax == x[i]) {
			tot += z[i];
			tot %= MOD;
		}
	}
	FORd(i, n, 0) {
		FOR(j, 0, sz(que[i])) {
			int val = que[i][j].fi;
			int idx = que[i][j].se;
			suf[idx] = sfen.query(maxn - val - 1).fi + 1;
		}
		pi r = sfen.query(maxn - a[i] - 1);
		y[i] = r.fi + 1;
		t[i] = r.se;
		sfen.update(maxn - a[i], y[i], t[i]);
		setmax(dmax, y[i]);
	}
	FOR(i, 0, n) {
		FOR(j, 0, sz(que[i])) {
			int idx = que[i][j].se;
			setmax(ans[idx], 1);
			setmax(ans[idx], pre[idx] + suf[idx] - 1);
			setmax(ans[idx], dmax - 1);
			if (x[i] + y[i] != dmax + 1 || z[i] * t[i] % MOD != tot) {
				setmax(ans[idx], dmax);
			}
		}
	}
	FOR(i, 0, m) {
		printf("%d\n", ans[i]);
	}
}

int main() {
//	ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}