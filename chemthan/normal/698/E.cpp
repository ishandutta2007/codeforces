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

string dayOfWeek[] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
//converts Gregorian date to integer (Julian day number)
int dateToInt(int m, int d, int y) {
	return
	    1461 * (y + 4800 + (m - 14) / 12) / 4 +
	    367 * (m - 2 - (m - 14) / 12 * 12) / 12 -
	    3 * ((y + 4900 + (m - 14) / 12) / 100) / 4 +
	    d - 32075;
}
//converts integer (Julian day number) to Gregorian date: month/day/year
void intToDate(long long jd, long long &m, long long &d, long long &y) {
	long long x, n, i, j;
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
string intToDay(long long jd) {
	return dayOfWeek[jd % 7];
}

int s, m, h, day, date, month;

int checkdate(long long t) {
	long long m, d, y;
	t += dateToInt(1, 1, 1970);
	intToDate(t, m, d, y);
	if (month != -1 && month != m) {
		return 0;
	}
	if (day != -1 && date != -1) {
		if (day == t % 7 + 1 || date == d) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (day != -1) {
		return day == t % 7 + 1;
	}
	else if (date != -1) {
		return date == d;
	}
}

int checktime(int smh) {
	int ss = smh % 60; smh /= 60;
	int mm = smh % 60; smh /= 60;
	int hh = smh;
	if (s != -1 && s != ss) return 0;
	if (m != -1 && m != mm) return 0;
	if (h != -1 && h != hh) return 0;
	return 1;
}

void solve() {
	cin >> s >> m >> h >> day >> date >> month;
	int q; cin >> q;
	while (q--) {
		long long t; cin >> t;
		int smh = t % (60 * 60 * 24); t /= 60 * 60 * 24;
		if (checkdate(t)) {
			int found = 0;
			for (smh++; smh < 60 * 60 * 24; smh++) {
				if (checktime(smh)) {
					found = 1;
					break;
				}
			}
			if (found) {
				cout << t * 60 * 60 * 24 + smh << "\n";
				continue;
			}
		}
		t++;
		while (!checkdate(t)) t++;
		FOR(i, 0, 60 * 60 * 24) {
			if (checktime(i)) {
				cout << t * 60 * 60 * 24 + i << "\n";
				break;
			}
		}
	}
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