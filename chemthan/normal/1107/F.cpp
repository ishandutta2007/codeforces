#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); --i)
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
const int FFTMOD = 119 << 23 | 1;
const int INF = (int) 1e9 + 23111992;
const ll LINF = (ll) 1e18 + 23111992;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
inline ull isqrt(ull k) {ull r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int myrand() {return abs((int) mt());}
#define db(x) cerr << #x << " = " << (x) << " ";
#define endln cerr << "\n";

template<class T, T oo> struct Hungary {
	static const int MAXN = 1000 + 5;
	static const int MAXM = 1000 + 5;
	int nx, ny, maty[MAXM], frm[MAXM], used[MAXM];
	T cst[MAXN][MAXM], fx[MAXN], fy[MAXM], dst[MAXM];
	void init(int nx, int ny) {
		this->nx = nx, this->ny = ny;
		fill_n(fx, nx + 1, 0), fill_n(fy, ny + 1, 0);
		fill_n(maty, nx + 1, 0);
		for (int i = 0; i <= nx; i++) {
			fill_n(cst[i], ny + 1, oo);
		}
	}
	void add(int x, int y, T c) {
		cst[x][y] = c;
	}
	T mincost() {
		for (int x = 1; x <= nx; x++) {
			int y0 = 0;
			maty[0] = x;
			for (int y = 0; y <= ny; y++) {
				dst[y] = oo + 1;
				used[y] = 0;
			}
			do {
				used[y0] = 1;
				int x0 = maty[y0], y1;
				T delta = oo + 1;
				for (int y = 1; y <= ny; y++) if (!used[y]) {
					T curdst = cst[x0][y] - fx[x0] - fy[y];
					if (dst[y] > curdst) {
						dst[y] = curdst;
						frm[y] = y0;
					}
					if (delta > dst[y]) {
						delta = dst[y];
						y1 = y;
					}
				}
				for (int y = 0; y <= ny; y++) if (used[y]) {
					fx[maty[y]] += delta;
					fy[y] -= delta;
				}
				else {
					dst[y] -= delta;
				}
				y0 = y1;
			}
			while (maty[y0] != 0);
			do {
				int y1 = frm[y0];
				maty[y0] = maty[y1];
				y0 = y1;
			}
			while (y0);
		}
		T res = 0;
		for (int y = 1; y <= ny; y++) {
			int x = maty[y];
			if (cst[x][y] < oo) res += cst[x][y];
		}
		return res;
	}
};
Hungary<long long, (long long) 1e18> hungary;

const int maxn = 500 + 5;
int n;
int a[maxn];
int b[maxn];
int k[maxn];

long long calc() {
    hungary.init(n, n);
    FOR(i, 0, n) {
        FOR(j, 0, n) {
            hungary.add(i + 1, j + 1, min(0LL, -a[i] + (long long) min(k[i], j) * b[i]));
        }
    }
    return -hungary.mincost();
}

void chemthan() {
    cin >> n;
    FOR(i, 0, n) {
        cin >> a[i] >> b[i] >> k[i];
    }
    cout << calc() << "\n";
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(0), cin.tie(0);
    if (argc > 1) {
        assert(freopen(argv[1], "r", stdin));
    }
    if (argc > 2) {
        assert(freopen(argv[2], "wb", stdout));
    }
    chemthan();
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}