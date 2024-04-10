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

#define RL long long
struct PT {
	RL x, y;
	PT() {}
	PT(RL x, RL y) : x(x), y(y) {}
	PT(const PT& p) : x(p.x), y(p.y) {}
	int operator < (const PT& rhs) const {return make_pair(y, x) < make_pair(rhs.y, rhs.x);}
	int operator == (const PT& rhs) const {return make_pair(y, x) == make_pair(rhs.y, rhs.x);}
	PT operator + (const PT& p) const {return PT(x + p.x, y + p.y);}
	PT operator - (const PT& p) const {return PT(x - p.x, y - p.y);}
};
RL cross(PT p, PT q) {return p.x * q.y - p.y * q.x;}
RL area(PT a, PT b, PT c) {return cross(a, b) + cross(b, c) + cross(c, a);}

void ConvexHull(vector<PT>& pts) {
	sort(pts.begin(), pts.end());
	pts.erase(unique(pts.begin(), pts.end()), pts.end());
	vector<PT> up, dn;
	for (int i = 0; i < pts.size(); i++) {
		while (up.size() > 1 && area(up[up.size() - 2], up.back(), pts[i]) >= 0) up.pop_back();
		while (dn.size() > 1 && area(dn[dn.size() - 2], dn.back(), pts[i]) <= 0) dn.pop_back();
		up.push_back(pts[i]);
		dn.push_back(pts[i]);
	}
	pts = dn;
	for (int i = up.size() - 2; i >= 1; i--) pts.push_back(up[i]);
}

const int maxn = 5010;
int n;
ll s;
int x[maxn];
int y[maxn];

void solve() {
	cin>>n>>s;
	vector<PT> vp;
	FOR(i, 0, n) cin>>x[i]>>y[i], vp.pb(PT(x[i], y[i]));
	ConvexHull(vp);
	n = sz(vp);
	FOR(i, 0, n) vp.pb(vp[i]);
	pair<ll, pair<pi, int> > opt;
	FOR(i, 0, n) {
		int cur = i;
		FOR(j, 1, n) {
			int k = i + j;
			while (cur < k && area(vp[i], vp[cur], vp[k]) <= area(vp[i], vp[cur + 1], vp[k])) cur++;
			chkmax(opt, mp(area(vp[i], vp[cur], vp[k]), mp(mp(i, cur), k)));
		}
	}
	PT u = vp[opt.se.fi.fi];
	PT v = vp[opt.se.fi.se];
	PT w = vp[opt.se.se];
	PT A = u + (w - v);
	PT B = u - (w - v);
	PT C = w + (v - u);
	cout<<A.x<<" "<<A.y<<"\n";
	cout<<B.x<<" "<<B.y<<"\n";
	cout<<C.x<<" "<<C.y<<"\n";
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