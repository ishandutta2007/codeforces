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

const int maxn = 200010;
int n;
int a[maxn];
vi dvs[maxn];
vi pos[maxn];
ll f[maxn];

ll st[maxn << 2];
int lz[maxn << 2];
int mx[maxn << 2];
int mn[maxn << 2];
void updatelz(int node, int L, int R) {
	if (~lz[node]) {
		st[node] = (ll) lz[node] * (R - L + 1);
		mx[node] = mn[node] = lz[node];
		if (L < R) {
			lz[node << 1] = lz[node];
			lz[(node << 1) + 1] = lz[node];
		}
		lz[node] = -1;
	}
}
void build(int node, int L, int R) {
	if (L == R) {
		st[node] = mx[node] = L;
		return;
	}
	build(node << 1, L, L + R >> 1);
	build((node << 1) + 1, (L + R >> 1) + 1, R);
	st[node] = st[node << 1] + st[(node << 1) + 1];
	mx[node] = max(mx[node << 1], mx[(node << 1) + 1]);
	mn[node] = min(mn[node << 1], mn[(node << 1) + 1]);
}
void update(int node, int l, int r, int L, int R, int val) {
	updatelz(node, L, R);
	if (l > R || r < L || mn[node] >= val) return;
	if (l <= L && r >= R && L == R) {
		chkmax(st[node], (ll) val);
		mx[node] = st[node];
		return;
	}
	if (l <= L && r >= R && mx[node] <= val) {
		lz[node] = val;
		updatelz(node, L, R);
		return;
	}
	update(node << 1, l, r, L, L + R >> 1, val);
	update((node << 1) + 1, l, r, (L + R >> 1) + 1, R, val);
	st[node] = st[node << 1] + st[(node << 1) + 1];
	mx[node] = max(mx[node << 1], mx[(node << 1) + 1]);
	mn[node] = min(mn[node << 1], mn[(node << 1) + 1]);
}

void solve() {
	ms(lz, -1);
	FOR(i, 1, maxn) {
		for (int j = 1; j * j <= i; j++) {
			if (i % j == 0) {
				dvs[i].pb(j);
				if (j < i / j) {
					dvs[i].pb(i / j);
				}
			}
		}
	}
	cin>>n;
	FOR(i, 0, n) {
		cin>>a[i];
		FOR(j, 0, sz(dvs[a[i]])) {
			int k = dvs[a[i]][j];
			pos[k].pb(i);
		}
	}
	build(1, 0, n - 1);
	f[maxn - 1] = (ll) n * n - st[1];
	FORd(i, maxn, 1) {
		if (sz(pos[i]) > 1) {
			int x = pos[i][0];
			int y = pos[i][sz(pos[i]) - 2];
			update(1, 0, x, 0, n - 1, y);
			int z = pos[i][1];
			int w = pos[i].back();
			update(1, x + 1, z, 0, n - 1, w);
			update(1, z + 1, n - 1, 0, n - 1, n);
		}
		f[i - 1] = (ll) n * n - st[1];
	}
	ll ans = 0;
	FOR(i, 1, maxn) {
		ans += i * (f[i] - f[i - 1]);
	}
	cout<<ans<<"\n";
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