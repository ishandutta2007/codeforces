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
template<class T> gcd(T a, T b) {T r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
template<class T> lcm(T a, T b) {return a / gcd(a, b) * b;}
template<class T> void setmin(T& a, T val) {a = min(a, val);}
template<class T> void setmax(T& a, T val) {a = max(a, val);}
ll fpow(ll n, ll k, int p = (int) 1e9 + 7) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
void addmod(int& a, int val, int p = (int) 1e9 + 7) {if ((a = a + val) >= p) a -= p;}
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos((ld) 0);

const int maxn = 100010;
int n;
ll x[maxn];
ll y[maxn];

#define T long double
struct PT {
	T x, y;
	PT() {}
	PT(T x, T y) : x(x), y(y) {}
	PT(const PT& p) : x(p.x), y(p.y) {}
	bool operator < (const PT& rhs) const {return make_pair(y, x) < make_pair(rhs.y, rhs.x);}
	bool operator == (const PT& rhs) const {return make_pair(y, x) == make_pair(rhs.y, rhs.x);}
	PT operator + (const PT& p) const {return PT(x + p.x, y + p.y);}
	PT operator - (const PT& p) const {return PT(x - p.x, y - p.y);}
	PT operator * (T c) const {return PT(x * c, y * c);}
	PT operator / (T c) const {return PT(x / c, y / c);}
};

T cross(PT p, PT q) {return p.x * q.y - p.y * q.x;}
T area(PT a, PT b, PT c) {return fabs(cross(a, b) + cross(b, c) + cross(c, a)) / 2;}
T area2(PT a, PT b, PT c) {return cross(a, b) + cross(b, c) + cross(c, a);}
T dot(PT p, PT q) {return p.x * q.x + p.y * q.y;}
T dist(PT p, PT q) {return sqrt(dot(p - q, p - q));}
T dist2(PT p, PT q) {return dot(p - q, p - q);}

PT RotateCCW90(PT p) {return PT(-p.y, p.x);}
PT RotateCW90(PT p) {return PT(p.y, -p.x);}
PT RotateCCW(PT p, T t) {return PT(p.x * cos(t) - p.y * sin(t), p.x * sin(t) + p.y * cos(t));}

PT ProjectPointLine(PT a, PT b, PT c) {
	return a + (b - a) * dot(c - a, b - a) / dot(b - a, b - a);
}

T DistancePointLine(PT a, PT b, PT c) {
	return dist(c, ProjectPointLine(a, b, c));
}

int z[maxn];

void solve() {
	cin>>n;
	vector<pair<pair<ll, ll>, int> > V;
	FOR(i, 0, n) {
		cin>>x[i]>>y[i];
		V.pb(mp(mp(x[i], y[i]), i));
	}
	sort(all(V));
	FOR(i, 0, n) {
		x[i] = V[i].fi.fi;
		y[i] = V[i].fi.se;
		z[i] = V[i].se;
	}
	ld dmin = 1e18;
	int imin = 2;
	FOR(i, 2, n) {
		ld t = DistancePointLine(PT(x[0], y[0]), PT(x[1], y[1]), PT(x[i], y[i]));
		if (t > EPS && t < dmin) {
			dmin = t;
			imin = i;
		}
	}
	cout<<z[0] + 1<<" "<<z[1] + 1<<" "<<z[imin] + 1;
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