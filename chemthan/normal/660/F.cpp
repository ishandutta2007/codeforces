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
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return a > val ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

#define T long long
#define oo 1e18
struct Convexhull {
	struct Line {
		T a, b;
		Line(T a = 0, T b = 0) : a(a), b(b) {}
		bool operator < (const Line& oth) const {
			return make_pair(-a, b) < make_pair(-oth.a, oth.b);
		}
		bool operator == (const Line& oth) const {
			return make_pair(a, b) == make_pair(oth.a, oth.b);
		}
		bool operator != (const Line& oth) const {
			return make_pair(a, b) != make_pair(oth.a, oth.b);
		}
	};
	long double intersect(Line ln1, Line ln2) {
		return (long double) (ln2.b - ln1.b) / (ln1.a - ln2.a);
	}
	int bad(Line ln1, Line ln2, Line ln3) {
		return (long double) (ln1.a - ln2.a) * (ln2.b - ln3.b) >= (long double) (ln2.a - ln3.a) * (ln1.b - ln2.b);
		//return intersect(ln1, ln2) >= intersect(ln2, ln3);
	}
	set<Line> hull;
	set<pair<long double, Line> > pos;
	void add(T a, T b) {
		Line ln(a, b);
		if (hull.find(ln) != hull.end()) return;
		hull.insert(ln);
		set<Line>::iterator it = hull.find(ln);
		if (it == hull.begin()) {
			pos.insert(make_pair(-oo, ln));
			if (++it != hull.end()) pos.erase(make_pair(-oo, *it));
			it--;
		}
		else {
			Line prv = *(--it); it++;
			if (prv.a == ln.a) {
				hull.erase(ln);
				return;
			}
			if (*it != *hull.rbegin()) {
				Line nxt = *(++it); it--;
				if (bad(prv, ln, nxt)) {
					hull.erase(ln);
					return;
				}
				pos.erase(make_pair(intersect(prv, nxt), nxt));
			}
		}
		Line u, v;
		if (it != hull.begin()) {
			v = *(--it);
			while (it != hull.begin()) {
				u = *(--it);
				if (bad(u, v, ln)) {
					pos.erase(make_pair(intersect(u, v), v));
					hull.erase(v); it = hull.find(v = u);
				}
				else {
					it++;
					break;
				}
			}
			pos.insert(make_pair(intersect(v, ln), ln));
			it++;
		}
		if (*it != *hull.rbegin()) {
			u = *(++it);
			while (*it != *hull.rbegin()) {
				v = *(++it);
				if (ln.a == u.a || bad(ln, u, v)) {
					pos.erase(make_pair(intersect(u, v), v));
					hull.erase(u); it = hull.find(u = v);
				}
				else {
					it--;
					break;
				}
			}
			pos.insert(make_pair(intersect(ln, u), u));
			it--;
		}
	}
	T query(T x) {
		if (!pos.size()) return oo;
		set<pair<long double, Line> >::iterator it = pos.upper_bound(make_pair(x, Line(-oo, -oo)));
		it--;
		return it->second.a * x + it->second.b;
	}
} cht;

const int maxn = 200010;
int n;
int a[maxn];
ll sum[maxn];
ll pre[maxn];

void solve() {
	cin>>n;
	FOR(i, 1, n + 1) cin>>a[i], sum[i] = sum[i - 1] + a[i];
	FOR(i, 1, n + 1) pre[i] = pre[i - 1] + (ll) a[i] * i;
	ll ans = 0;
	FORd(i, n + 1, 1) {
		cht.add(sum[i], -pre[i]);
		ll tot = (ll) (i - 1) * sum[i - 1] - pre[i - 1];
		chkmax(ans, tot - cht.query(i - 1));
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