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
#define db(x) cerr << #x << " = " << (x) << ", ";
#define endln cerr << "\n";
#define chkpt cerr << "-----\n";

template<class T> pair<T, T> euclid(T a, T b) {
	if (!b) return make_pair(1, 0);
	pair<T, T> r = euclid(b, a % b);
	return make_pair(r.second, r.first - a / b * r.second);
}
long long invert(long long x, long long p) {
    pair<long long, long long> r = euclid(x, p);
    return (r.fi % p + p) % p;
}
long long query(long long x, long long y, long long p, long long q) {
    long long g = gcd(p, q); p /= g, q /= g;
    long long d = p * y - q * x;
    long long r = invert(p, q) * (((-d) % q + q) % q) % q;
    long long k = 0;
    if (d > 0) {
        k = (d + q - p - 1) / (q - p);
    }
    if (d < 0) {
        chkmax(k, (-d + p - 1) / p);
    }
    k = max(0LL, k - r);
    if (k > 0) {
           k = (k + q - 1) / q;
    }
    return k * q + r;
}

const int maxn = 120 + 5;
int n;
int a[maxn][5];

int check(int mi) {
    long long sol[5] = {};
    FOR(i, 0, n) {
        FOR(j, 0, 5) if (a[i][j] != -1) sol[j]++;
    }
    int pt[5] = {};
    FOR(i, 0, 5) {
        if (a[0][i] == -1) {
        }
        else if (a[1][i] == -1) {
        }
        else if (a[0][i] > a[1][i]) {
            sol[i] += mi;
        }
        if (sol[i] * 32 <= n + mi) {
            pt[i] = 6;
        }
        else if (sol[i] * 16 <= n + mi) {
            pt[i] = 5;
        }
        else if (sol[i] * 8 <= n + mi) {
            pt[i] = 4;
        }
        else if (sol[i] * 4 <= n + mi) {
            pt[i] = 3;
        }
        else if (sol[i] * 2 <= n + mi) {
            pt[i] = 2;
        }
        else {
            pt[i] = 1;
        }
    }
    long long sc[2] = {};
    FOR(i, 0, 2) {
        FOR(j, 0, 5) {
            if (a[i][j] != -1) {
                sc[i] += pt[j] * 500 / 250 * (250 - a[i][j]);
            }
        }
    }
    return sc[0] > sc[1];
}

void solve() {
    cin >> n;
    FOR(i, 0, n) {
        FOR(j, 0, 5) cin >> a[i][j];
    }
    int st = 0;
    while (1.0 * clock() / CLOCKS_PER_SEC < 1.8) {
        if (check(st)) {
            cout << st << "\n";
            return;
        }
        st++;
    }
    cout << -1 << "\n";
}

int main() {
    int JUDGE_ONLINE = 1;
    if (fopen("in.txt", "r")) {
        JUDGE_ONLINE = 0;
        assert(freopen("in.txt", "r", stdin));
        //assert(freopen("out.txt", "w", stdout));
    }
    else {
        ios_base::sync_with_stdio(0), cin.tie(0);
    }
    solve();
    if (!JUDGE_ONLINE) {
        //cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    }
    return 0;
}