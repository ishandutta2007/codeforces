#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define pconent(t, x) (t.find(x) != t.end())
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
const int FFTMOD = 1007681537;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
inline ll isqrt(ll k) {ll r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
#define db(x) cerr << #x << " = " << (x) << " ";
#define endln cerr << "\n";

string dayOfWeek[] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
//converts Gregorian date to integer (Julian day number)
int dateToInt(int m, int d, int y) {
	return
	    1461 * (y + 4800 + (m - 14) / 12) / 4 +
	    367 * (m - 2 - (m - 14) / 12 * 12) / 12 -
	    3 * ((y + 4900 + (m - 14) / 12) / 100) / 4 +
	    d - 32075;
}
//converts Julian date to integer (Julian day number)
int dateToInt2(int m, int d, int y) {
	int a = (14 - m) / 12;
	int y2 = y + 4800 - a;
	int m2 = m + 12 * a - 3;
	return d + (153 * m2 + 2) / 5 + 365 * y2 + y2 / 4 - 32083;
}
//converts integer (Julian day number) to Gregorian date: month/day/year
void intToDate(int jd, int &m, int &d, int &y) {
	int x, n, i, j;

	x = jd + 68569;
	n = 4 * x / 146097;
	x -= (146097 * n + 3) / 4;
	i = (4000 * (x + 1)) / 1461001;
	x -= 1461 * i / 4 - 31;
	j = 80 * x / 2447;
	d = x - 2447 * j / 80;
	x = j / 11;
	m = j + 2 - 12 * x;
	y = 100 * (n - 49) + i + x;
}
//converts integer (Julian day number) to day of week
string intToDay(int jd) {
	return dayOfWeek[jd % 7];
}

void solve() {
    int n; cin >> n;
    vi a(n);
    for (int& x : a) cin >> x;
    vi vals;
    int cnt = 0;
    int pm = -1;
    FOR(i, 0, 10000000) {
        int m, d, y; intToDate(i, m, d, y);
        if (m != pm) {
            vals.pb(cnt);
            cnt = 0;
        }
        pm = m;
        cnt++;
    }
    FOR(i, 0, sz(vals) - n + 1) {
        vi tmp(vals.begin() + i, vals.begin() + i + n);
        if (a == tmp) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(0), cin.tie(0);
    if (argc > 1) {
        assert(freopen(argv[1], "r", stdin));
    }
    if (argc > 2) {
        assert(freopen(argv[2], "wb", stdout));
    }
    solve();
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}