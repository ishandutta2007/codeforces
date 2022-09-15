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

typedef long long T;
const T oo = (T) 2e18;

//O(n, qlogn)
//Adding lines in descending/ascending order by a
struct ConvexhullTrick {
	struct Line {
		T a, b;
		Line(T a, T b) : a(a), b(b) {}
	};
	double intersect(Line ln1, Line ln2) {
		return 1.0 * (ln2.b - ln1.b) / (ln1.a - ln2.a);
	}
	int bad(Line ln1, Line ln2, Line ln3) {
		return (ln1.a - ln2.a) * (ln2.b - ln3.b) >= (ln2.a - ln3.a) * (ln1.b - ln2.b);
		//return intersect(ln1, ln2) >= intersect(ln2, ln3);
		//return (long double) (ln1.a - ln2.a) * (ln2.b - ln3.b) <= (long double) (ln2.a - ln3.a) * (ln1.b - ln2.b); //for adding in ascending order
		//return intersect(ln1, ln2) <= intersect(ln2, ln3); //for adding in ascending order
	}
	vector<Line> hull;
	vector<double> pos;
	ConvexhullTrick() {
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
		//if (hull.size() >= 2) pos.push_back(-intersect(hull[hull.size() - 2], hull[hull.size() - 1])); //for adding in ascending order
		pos.push_back(+oo);
	}
	T query(T x) {
		if (!hull.size()) return oo;
		int k = lower_bound(pos.begin(), pos.end(), x) - pos.begin() - 1;
		//int k = lower_bound(pos.begin(), pos.end(), -x) - pos.begin() - 1; //for adding in ascending order
		return hull[k].a * x + hull[k].b;
	}
};

const int maxn = 300010;
const int magic = 2500;
int n;
int a[maxn];
int b[maxn];
int f[maxn];
int g[maxn];
int del[maxn];

void solve() {
	scanf("%d", &n);
	vii que;
	vector<pair<pi, int> > v;
	FOR(i, 0, n) {
		int op; scanf("%d", &op);
		if (op == 1) {
			scanf("%d%d", a + i, b + i);
			del[i] = INF;
			que.pb(mp(op, i));
			v.pb(mp(mp(a[i], -b[i]), i));
		}
		else if (op == 2) {
			int z; scanf("%d", &z); z--;
			del[z] = i;
			que.pb(mp(op, z));
		}
		else {
			int x; scanf("%d", &x);
			que.pb(mp(op, x));
		}
	}
	sort(all(v));
	vii cache;
	int cnt = 0;
	vii his;
	FOR(k, 0, n) {
		cache.pb(que[k]);
		int op = que[k].fi;
		int z = que[k].se;
		if (op == 1) {
			his.pb(mp(z, 0));
		}
		else if (op == 2) {
			f[z] = 0;
			his.pb(mp(z, 1));
		}
		if (sz(cache) == magic || k == n - 1) {
			ConvexhullTrick cht;
			int back = -INF << 1;
			FOR(i, 0, sz(v)) {
				int idx = v[i].se;
				if (f[idx]) {
					int a = -v[i].fi.fi;
					int b = v[i].fi.se;
					if (a != back) {
						cht.add(a, b);
						back = a;
					}
				}
			}
			FOR(i, 0, sz(cache)) {
				if (cache[i].fi == 3) {
					int x = cache[i].se;
					ll res = -cht.query(x);
					FOR(j, 0, i) {
						int z = cache[j].se;
						if (cache[j].fi == 1 && del[z] > cnt) {
							chkmax(res, (ll) a[z] * x + b[z]);
						}
					}
					FOR(j, i + 1, sz(cache)) {
						int z = cache[j].se;
						if (cache[j].fi == 2 && z < cnt) {
							chkmax(res, (ll) a[z] * x + b[z]);
						}
					}
					if (res == -oo) {
						puts("EMPTY SET");
					}
					else {
						printf("%I64d\n", res);
					}
				}
				cnt++;
			}
			cache.clear();
			FOR(i, 0, sz(his)) {
				if (his[i].se == 0) {
					f[his[i].fi] = 1;
				}
				else {
					f[his[i].fi] = 0;
				}
			}
			his.clear();
		}
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