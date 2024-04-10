#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define present(t, x) (t.find(x) != t.end())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcountll(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return a > val ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
inline ll isqrt(ll k) {ll r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

const int MAXN = 300010;
const int LOGN = 20;
pi st[MAXN << 1];
int lz[MAXN];
void build(int n) {
	for (int i = 0; i < n; i++) {
		st[i + n] = mp(0, i);
	}
	for (int i = n - 1; i > 0; i--) {
		st[i] = max(st[i << 1], st[i << 1 | 1]);
	}
}
void apply(int p, int n, int val) {
	st[p].fi += val;
	if (p < n) lz[p] += val;
}
void pushup(int p) {
	while (p > 1) {
		p >>= 1;
		st[p] = max(st[p << 1], st[p << 1 | 1]);
		st[p].fi += lz[p];
	}
}
void pushdown(int p, int n) {
	for (int i = LOGN; i > 0; i--) {
		int q = p >> i;
		if (lz[q]) {
			apply(q << 1, n, lz[q]);
			apply(q << 1 | 1, n, lz[q]);
			lz[q] = 0;
		}
	}
}
void upd(int l, int r, int n, int val) {
	l += n, r += n + 1;
	int l0 = l, r0 = r;
	for (; l < r; l >>= 1, r >>= 1) {
		if (l & 1) apply(l++, n, val);
		if (r & 1) apply(--r, n, val);
	}
	pushup(l0); pushup(r0 - 1);
}
pi query(int l, int r, int n) {
	l += n, r += n + 1;
	pushdown(l, n), pushdown(r - 1, n);
	pi res;
	for (; l < r; l >>= 1, r >>= 1) {
		if (l & 1) res = max(res, st[l++]);
		if (r & 1) res = max(res, st[--r]);
	}
	return res;
}

const int maxn = 300010;
int n;
int l[maxn];
int v[maxn];
int r[maxn];

void solve() {
	cin >> n;
	vector<pair<int, pi> > vs;
	FOR(i, 0, n) {
		cin >> l[i] >> v[i] >> r[i]; l[i]--, v[i]--, r[i]--;
		vs.pb(mp(l[i], mp(v[i], r[i])));
	}
	sort(all(vs));
	int ptr = 0;
	priority_queue<pi, vector<pi>, greater<pi> > pq;
	int ans = 0; pi z;
	build(maxn);
	FOR(i, 0, maxn) {
		while (ptr < n && vs[ptr].fi <= i) {
			upd(vs[ptr].se.fi, vs[ptr].se.se, maxn, 1);
			pq.push(mp(vs[ptr].se.fi, vs[ptr].se.se));
			ptr++;
		}
		while (sz(pq) && pq.top().fi < i) {
			upd(pq.top().fi, pq.top().se, maxn, -1);
			pq.pop();
		}
		pi best = query(i, maxn - 1, maxn);
		if (chkmax(ans, best.fi)) {
			z = mp(i, best.se);
		}
	}
	cout << ans << "\n";
	FOR(i, 0, n) {
		if (l[i] <= z.fi && r[i] >= z.se && v[i] >= z.fi && v[i] <= z.se) {
			cout << i + 1 << " ";
		}
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}