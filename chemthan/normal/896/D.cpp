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
inline void addmod(long & a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
#define db(x) cerr << #x << " = " << (x) << " ";
#define endln cerr << "\n";

template<class T> T mulmod(T a, T b, T p) {
    return (long long) a * b % p;
}
template<class T> pair<T, T> euclid(T a, T b) {
    if (!b) return make_pair(1, 0);
    pair<T, T> r = euclid(b, a % b);
    return make_pair(r.second, r.first - a / b * r.second);
}
 
const int MAXN = 1e5 + 5;
long long pr[MAXN], rm[MAXN], b[MAXN], x[MAXN];
long long chineseRemainder(long long p[], long long r[], int n) {
    long long M = 1;
    for (int i = 0; i < n; i++) M *= p[i];
    long long N = 0;
    for (int i = 0; i < n; i++) {
        b[i] = M / p[i];
        x[i] = (euclid(b[i], (long long) p[i]).first % p[i] + p[i]) % p[i];
        N += mulmod(r[i] * b[i] % M, x[i] % M, M);
        if (N >= M) N -= M;
    }
    return N;
}
 
template<class T> T inverse(T a, T p) {
    pair<T, T> r = euclid(a, p);
    return (r.fi % p + p) % p;
}
 
const int maxn = 1e6 + 5;
int n, p;
int l, r;
int fac[maxn];
int fac2[maxn];
 
long long calc(long long n, long long a, long long b, int p) {
    long long res = 0;
    while (n) {
        res += n / p;
        res -= a / p;
        res -= b / p;
        chkmin(res, LINF);
        n /= p, a /= p, b /= p;
    }
    return res;
}
 
int func(long long n, int p, int pp) {
    if (n < maxn) return fac[n];
    long long d = n / pp;
    int r = n % pp;
    int res = 1;
    res = mult(res, fpow(fac2[pp - 1], d, pp), pp);
    res = mult(res, fac2[r], pp);
    res = mult(res, func(n / p, p, pp), pp);
    return res;
}
 
int binom(long long a, long long b, int p, int pw, int pp) {
    long long t = calc(b, a, b - a, p);
    if (t >= pw) return 0;
    int res = func(b, p, pp);
    res = mult(res, inverse(func(a, p, pp), pp), pp);
    res = mult(res, inverse(func(b - a, p, pp), pp), pp);
    res = mult(res, fpow(p, t, pp), pp);
    return res;
}

void solve() {
    cin >> n >> p >> l >> r;
    map<int, int> hs;
    for (int i = 2; i * i <= p; i++) {
        while (p % i == 0) hs[i]++, p /= i;
    }
    if (p > 1) hs[p]++;
    int cnt = 0;
    FORall(it, hs) {
        int p = it->fi;
        int pw = it->se;
        int pp = (int) round(pow(p, pw));
        fac[0] = fac2[0] = 1;
        FOR(i, 1, maxn) {
            int t = i;
            while (t % p == 0) t /= p;
            fac[i] = mult(fac[i - 1], t, pp);
            if (i % p) {
                fac2[i] = mult(fac2[i - 1], i, pp);
            }
            else {
                fac2[i] = fac2[i - 1];
            }
        }
        pr[cnt] = pp;
        FOR(k, 0, n + 1) {
            int ll = k - l;
            int rr = k - r;
            swap(ll, rr);
            chkmax(ll, 0);
            chkmin(rr, k);
            if (ll > rr) continue;
            rr /= 2;
            ll = (ll + 1) / 2;
            if (ll <= rr) {
                rm[cnt] += mult(binom(rr, k, p, pw, pp), binom(k, n, p, pw, pp), pp);
                if (rm[cnt] >= pp) rm[cnt] -= pp;
                if (ll) {
                    rm[cnt] -= mult(binom(ll - 1, k, p, pw, pp), binom(k, n, p, pw, pp), pp);
                    if (rm[cnt] < 0) rm[cnt] += pp;
                }
            }
        }
        cnt++;
    }
    cout << chineseRemainder(pr, rm, cnt) << "\n";
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