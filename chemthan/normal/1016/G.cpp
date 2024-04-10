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

template<class T> T mulmod(T a, T b, T p) {
    a %= p; b %= p;
    T q = (T) ((long double) a * b / p);
    T r = a * b - q * p;
    while (r < 0) r += p;
    while (r >= p) r -= p;
    return r;
}
template<class T> T powmod(T n, T k, T p) {
    if (!n) return 0;
    T r = 1;
    for (; k; k >>= 1) {
        if (k & 1) r = mulmod(r, n, p);
        n = mulmod(n, n, p);
    }
    return r;
}
template<class T> int rabin(T n) {
    if (n == 2) return 1;
    if (n < 2 || !(n & 1)) return 0;
    const T p[9] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
    T a, d = n - 1, mx = 9;
    int i, r, s = 0;
    while (!(d & 1)) {++s; d >>= 1;}
    for (i = 0; i < mx; i++) {
        if (n == p[i]) return 1;
        if (!(n % p[i])) return 0;
        a = powmod(p[i], d, n);
        if (a != 1) {
            for (r = 0; r < s && a != n - 1; r++) a = mulmod(a, a, n);
            if (r == s) return 0;
        }
    }
    return 1;
}
template<class T> T pollardrho(T n) {
    int it = 0, k = 2;
    T x = 3, y = 3;
    while (1) {
        it++;
        x = (mulmod(x, x, n) + n - 1) % n;
        T d = __gcd(abs(y - x), n);
        if (d != 1 && d != n) return d;
        if (it == k) y = x, k <<= 1;
    }
}

const int maxn = 2e5 + 5;
int n;
long long x, y;
long long a[maxn];

vector<pair<long long, int> > factorize(long long k) {
    map<long long, int> hs;
    FOR(i, 2, 1e6) if (k % i == 0) {
        while (k % i == 0) hs[i]++, k /= i;
    }
    if (k > 1) {
        long long kk = isqrt(k);
        if (kk * kk == k) {
            hs[kk] += 2;
        }
        else if (rabin(k)) {
            hs[k]++;
        }
        else {
            long long p = pollardrho(k);
            long long q = k / p;
            hs[p]++, hs[q]++;
        }
    }
    vector<pair<long long, int> > res;
    for (auto it : hs) {
        res.pb(it);
    }
    return res;
}

map<int, int> ff(vector<pair<long long, int> > facs, vector<long long> dvs) {
    static int f[1 << 20];
    int k = sz(facs);
    auto getmsk = [&] (long long d) {
        int res = 0;
        FOR(i, 0, sz(facs)) {
            int cnt = 0;
            while (d % facs[i].fi == 0) cnt++, d /= facs[i].fi;
            if (cnt >= facs[i].se) {
                res |= 1 << i;
            }
        }
        return res;
    };
    FOR(i, 0, n) if (y % a[i] == 0) {
        int msk = getmsk(a[i]) ^ (1 << k) - 1;
        f[msk]++;
    }
    FOR(i, 0, k) {
        FOR(msk, 0, 1 << k) if (bit(msk, i)) {
            f[msk] += f[msk ^ (1 << i)];
        }
    }
    map<int, int> res;
    FOR(msk, 0, 1 << k) res[msk] = f[msk];
    return res;
}

void rec(int pos, long long num, vector<pair<long long, int> >& facs, vector<long long>& dvs) {
    if (pos == sz(facs)) {
        dvs.pb(num);
        return;
    }
    FOR(i, 0, facs[pos].se + 1) {
        rec(pos + 1, num, facs, dvs);
        num *= facs[pos].fi;
    }
}

void chemthan() {
    cin >> n >> x >> y;
    FOR(i, 0, n) cin >> a[i];
    if (y % x) {
        cout << 0 << "\n";
        return;
    }
    vector<pair<long long, int> > facs = factorize(y);
    vector<long long> vals;
    FOR(i, 0, sz(facs)) {
        vals.pb(1);
        FOR(j, 0, facs[i].se) vals.back() *= facs[i].fi;
    }
    vector<long long> dvs;
    rec(0, 1, facs, dvs);
    sort(all(dvs));
    map<int, int> rr = ff(facs, dvs);
    int k = sz(facs);
    auto getmsk = [&] (long long d) {
        int res = 0;
        FOR(i, 0, sz(facs)) {
            if (d % facs[i].fi == 0) {
                res |= 1 << i;
            }
        }
        return res;
    };
    auto getmsk2 = [&] (long long d) {
        int res = 0;
        FOR(i, 0, sz(facs)) {
            int cnt = 0;
            while (d % facs[i].fi == 0) cnt++, d /= facs[i].fi;
            if (cnt >= facs[i].se) {
                res |= 1 << i;
            }
        }
        return res;
    };
    long long res = 0;
    FOR(i, 0, n) if (a[i] % x == 0) {
        long long b = a[i] / x;
        int msk = getmsk(b) ^ (1 << k) - 1;
        long long t = x;
        FOR(j, 0, k) if (bit(msk, j)) {
            while (t % vals[j]) t *= facs[j].fi;
        }
        int msk2 = getmsk2(t);
        res += rr[msk2];
    }
    cout << res << "\n";
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