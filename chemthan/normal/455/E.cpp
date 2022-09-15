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
#define bit(n, i) ((n) & (1LL << (i)))
#define bitcount(n) __builtin_popcount(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = (int) 1e9 + 7) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos((ld) 0);

#define T int
#define oo 2e9
struct Convexhull {
	struct Line {
		T a, b;
		Line(T a, T b) : a(a), b(b) {}
	};
	long double intersect(Line ln1, Line ln2) {
		return (long double) (ln2.b - ln1.b) / (ln1.a - ln2.a);
	}
	int bad(Line ln1, Line ln2, Line ln3) {
		return (long double) (ln1.a - ln2.a) * (ln2.b - ln3.b) >= (long double) (ln2.a - ln3.a) * (ln1.b - ln2.b);
	}
	vector<Line> hull;
	vector<long double> pos;
	Convexhull() {
		pos.push_back(-oo);
		pos.push_back(+oo);
	}
	void add(T a, T b) {
		Line ln(a, b);
		pos.pop_back();
		while (hull.size() >= 2 && bad(hull[hull.size() - 2], hull[hull.size() - 1], ln)) {
			hull.pop_back();
			pos.pop_back();
		}
		hull.push_back(ln);
		if (hull.size() >= 2) pos.push_back(intersect(hull[hull.size() - 2], hull[hull.size() - 1]));
		pos.push_back(+oo);
	}
	T query(T x) {
		if (!hull.size()) return oo;
		int k = lower_bound(pos.begin(), pos.end(), x) - pos.begin() - 1;
		return hull[k].a * x + hull[k].b;
	}
};

const int maxn = 100010;
int n;
int a[maxn];
int sum[maxn];

Convexhull st[4 * maxn];
void update(int node, int i, int L, int R, T a, T b) {
	if (i < L || i > R) return;
	st[node].add(a, b);
	if (L == R) return;
	update(node << 1, i, L, (L + R) >> 1, a, b);
	update((node << 1) + 1, i, ((L + R) >> 1) + 1, R, a, b);
}
T query(int node, int l, int r, int L, int R, T x) {
	if (l > R || r < L) return oo;
	if (l <= L && r >= R) return st[node].query(x);
	return min(query(node << 1, l, r, L, (L + R) >> 1, x), query((node << 1) + 1, l, r, ((L + R) >> 1) + 1, R, x));
}

void solve() {
	scanf("%d", &n);
	FOR(i, 1, n + 1) {
		scanf("%d", a + i);
		sum[i] = sum[i - 1] + a[i];
	}
	vector<pair<pair<ll, ll>, int> > vl;
	FOR(i, 1, n + 1) {
		vl.pb(mp(mp(a[i], (ll) i * a[i] - sum[i]), i));
	}
	sort(all(vl));
	FORd(i, sz(vl), 0) {
		update(1, vl[i].se, 1, n, vl[i].fi.fi, vl[i].fi.se);
	}
	int m; scanf("%d", &m);
	while (m--) {
		int u, v; scanf("%d%d", &u, &v);
		printf("%d\n", query(1, v - u, v, 1, n, u - v) + sum[v]);
	}
}

int main() {
//	ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}