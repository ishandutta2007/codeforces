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
inline int mrand() {return abs((int) mt());}
inline int mrand(int k) {return abs((int) mt()) % k;}
#define db(x) cerr << "[" << #x << ": " << (x) << "] ";
#define endln cerr << "\n"; 

///// MODNUM TEMPLATE /////
template <int MOD_> struct modnum {
  static constexpr int MOD = MOD_;
  static_assert(MOD_ > 0, "MOD must be positive");

private:
  using ll = long long;

  int v;

  static int minv(int a, int m) {
    a %= m;
    assert(a);
    return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
  }

public:

  modnum() : v(0) {}
  modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
  int toint() {return v;}
  explicit operator int() const { return v; }
  friend std::ostream& operator << (std::ostream& out, const modnum& n) { return out << int(n); }
  friend std::istream& operator >> (std::istream& in, modnum& n) { ll v_; in >> v_; n = modnum(v_); return in; }

  friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
  friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

  modnum inv() const {
    modnum res;
    res.v = minv(v, MOD);
    return res;
  }
  friend modnum inv(const modnum& m) { return m.inv(); }
  modnum neg() const {
    modnum res;
    res.v = v ? MOD-v : 0;
    return res;
  }
  friend modnum neg(const modnum& m) { return m.neg(); }

  modnum operator- () const {
    return neg();
  }
  modnum operator+ () const {
    return modnum(*this);
  }

  modnum& operator ++ () {
    v ++;
    if (v == MOD) v = 0;
    return *this;
  }
  modnum& operator -- () {
    if (v == 0) v = MOD;
    v --;
    return *this;
  }
  modnum& operator += (const modnum& o) {
    v += o.v;
    if (v >= MOD) v -= MOD;
    return *this;
  }
  modnum& operator -= (const modnum& o) {
    v -= o.v;
    if (v < 0) v += MOD;
    return *this;
  }
  modnum& operator *= (const modnum& o) {
    v = int(ll(v) * ll(o.v) % MOD);
    return *this;
  }
  modnum& operator /= (const modnum& o) {
    return *this *= o.inv();
  }

  friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
  friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
  friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
  friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
  friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
  friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};

template <typename T> T pow(T a, long long b) {
  assert(b >= 0);
  T r = 1; while (b) { if (b & 1) r *= a; b >>= 1; a *= a; } return r;
}

using num = modnum<MOD>;

#define double long double
namespace FFT {
    const int maxf = 1 << 20;
    struct cp {
        double x, y;
        cp(double x = 0, double y = 0) : x(x), y(y) {}
        cp operator + (const cp& rhs) const {
            return cp(x + rhs.x, y + rhs.y);
        }
        cp operator - (const cp& rhs) const {
            return cp(x - rhs.x, y - rhs.y);
        }
        cp operator * (const cp& rhs) const {
            return cp(x * rhs.x - y * rhs.y, x * rhs.y + y * rhs.x);
        }
        cp operator !() const {
            return cp(x, -y);
        }
    } rts[maxf + 1];
    cp fa[maxf], fb[maxf];
    cp fc[maxf], fd[maxf];

    int bitrev[maxf];
    void fftinit() {
        int k = 0; while ((1 << k) < maxf) k++;
        bitrev[0] = 0;
        for (int i = 1; i < maxf; i++) {
            bitrev[i] = bitrev[i >> 1] >> 1 | ((i & 1) << k - 1);
        }
        double PI = acos((double) -1.0);
        rts[0] = rts[maxf] = cp(1, 0);
        for (int i = 1; i + i <= maxf; i++) {
            rts[i] = cp(cos(i * 2 * PI / maxf), sin(i * 2 * PI / maxf));
        }
        for (int i = maxf / 2 + 1; i < maxf; i++) {
            rts[i] = !rts[maxf - i];
        }
    }
    void dft(cp a[], int n, int sign) {
        static int isinit;
        if (!isinit) {
            isinit = 1;
            fftinit();
        }
        int d = 0; while ((1 << d) * n != maxf) d++;
        for (int i = 0; i < n; i++) {
            if (i < (bitrev[i] >> d)) {
                swap(a[i], a[bitrev[i] >> d]);
            }
        }
        for (int len = 2; len <= n; len <<= 1) {
            int delta = maxf / len * sign;
            for (int i = 0; i < n; i += len) {
                cp *x = a + i,*y = a + i + (len >> 1), *w = sign > 0 ? rts : rts + maxf;
                for (int k = 0; k + k < len; k++) {
                    cp z = *y * *w;
                    *y = *x - z, *x = *x + z;
                    x++, y++, w += delta;
                }
            }
        }
        if (sign < 0) {
            for (int i = 0; i < n; i++) {
                a[i].x /= n;
                a[i].y /= n;
            }
        }
    }
    void multiply(int a[], int b[], int na, int nb, long long c[], int dup = 0) {
        int n = na + nb - 1; while (n != (n & -n)) n += n & -n;
        for (int i = 0; i < n; i++) fa[i] = fb[i] = cp();
        for (int i = 0; i < na; i++) fa[i] = cp(a[i]);
        for (int i = 0; i < nb; i++) fb[i] = cp(b[i]);
        dft(fa, n, 1);
        if (dup) {
            for (int i = 0; i < n; i++) fb[i] = fa[i];
        }
        else {
            dft(fb, n, 1);
        }
        for (int i = 0; i < n; i++) fa[i] = fa[i] * fb[i];
        dft(fa, n, -1);
        for (int i = 0; i < n; i++) c[i] = (long long) floor(fa[i].x + 0.5);
    }
    void multiply(int a[], int b[], int na, int nb, int c[], int mod = (int) 1e9 + 7, int dup = 0) {
        int n = na + nb - 1;
        while (n != (n & -n)) n += n & -n;
        for (int i = 0; i < n; i++) fa[i] = fb[i] = cp();
        static const int magic = 15;
        for (int i = 0; i < na; i++) fa[i] = cp(a[i] >> magic, a[i] & (1 << magic) - 1);
        for (int i = 0; i < nb; i++) fb[i] = cp(b[i] >> magic, b[i] & (1 << magic) - 1);
        dft(fa, n, 1);
        if (dup) {
            for (int i = 0; i < n; i++) fb[i] = fa[i];
        }
        else {
            dft(fb, n, 1);
        }
        for (int i = 0; i < n; i++) {
            int j = (n - i) % n;
            cp x = fa[i] + !fa[j];
            cp y = fb[i] + !fb[j];
            cp z = !fa[j] - fa[i];
            cp t = !fb[j] - fb[i];
            fc[i] = (x * t + y * z) * cp(0, 0.25);
            fd[i] = x * y * cp(0, 0.25) + z * t * cp(-0.25, 0);
        }
        dft(fc, n, -1), dft(fd, n, -1);
        for (int i = 0; i < n; i++) {
            long long u = ((long long) floor(fc[i].x + 0.5)) % mod;
            long long v = ((long long) floor(fd[i].x + 0.5)) % mod;
            long long w = ((long long) floor(fd[i].y + 0.5)) % mod;
            c[i] = ((u << magic) + v + (w << magic + magic)) % mod;
        }
    }
    vector<int> multiply(vector<int> a, vector<int> b, int mod = (int) 1e9 + 7) {
        static int fa[maxf], fb[maxf], fc[maxf];
        int na = a.size(), nb = b.size();
        for (int i = 0; i < na; i++) fa[i] = a[i];
        for (int i = 0; i < nb; i++) fb[i] = b[i];
        multiply(fa, fb, na, nb, fc, mod, a == b);
        int k = na + nb - 1;
        vector<int> res(k);
        for (int i = 0; i < k; i++) res[i] = fc[i];
        return res;
    }
    int fpow(int a, int k, int p) {
        if (!k) return 1;
        int res = a, t = a; k--;
        while (k) {
            if (k & 1) res = (long long) res * t % p;
            t = (long long) t * t % p;
            k >>= 1;
        }
        return res;
    }
    vector<int> invert(vector<int> a, int n, int mod){
        assert(a[0] != 0);
        vector<int> x(1, fpow(a[0], mod - 2, mod));
        while (x.size() < n) {
            vector<int> tmp(a.begin(), a.begin() + min(a.size(), 2 * x.size()));
            vector<int> nx = multiply(multiply(x, x, mod), tmp, mod);
            x.resize(2 * x.size());
            for (int i = 0; i < x.size(); i++) {
                x[i] += x[i];
                x[i] -= nx[i];
                if (x[i] < 0) x[i] += mod;
                if (x[i] >= mod) x[i] -= mod;
            }
        }
        x.resize(n);
        return x;
    }
    pair<vector<int>, vector<int> > divmod(vector<int> a, vector<int> b, int mod) {
        int n = a.size(), m = b.size();
        if (n < m) {
            return make_pair(vector<int>(), a);
        }
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        vector<int> rb = invert(b, n - m + 1, mod);
        vector<int> d = multiply(a, rb, mod);
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        while (d.size() > n - m + 1) d.pop_back();
        reverse(d.begin(), d.end());
        vector<int> r = multiply(d, b, mod);
        while (r.size() >= m) r.pop_back();
        for (int i = 0; i < m; i++) {
            r[i] = a[i] - r[i];
            if (r[i] < 0) r[i] += mod;
        }
        return make_pair(d, r);
    }
    vector<int> chirpz_transform(vector<int> a, int z, int k, int mod) {
        int n = a.size();
        vector<int> x;
        vector<int> y;
        int iz = fpow(z, mod - 2, mod);
        for (int i = 0; i < n; i++) {
            x.push_back((long long) a[i] * fpow(z, (long long) i * i, mod) % mod);
        }
        for (int i = 1 - n; i < k; i++) {
            y.push_back(fpow(iz, (long long) i * i, mod));
        }
        vector<int> r = FFT::multiply(x, y, mod);
        vector<int> res(k);
        for (int i = 0; i < k; i++) {
            res[i] = (long long) r[i + n - 1] * fpow(z, (long long) i * i, mod) % mod;
        }
        return res;
    }
}
#undef double

void chemthan() {
    int n, k; cin >> n >> k;
    vi a(n);
    FOR(i, 0, n) cin >> a[i];
    vector<num> f(n + 1);
    FOR(i, 0, n) {
        num x = num(i) * num(k - 1) / num(n) / num(k);
        num y = num(i) / num(n) / num(k);
        num z = num(n - i) / num(n) / num(k);
        num t = z * num(k - 1);
        f[i + 1] = (num(1) - y - t) * f[i] - (i ? x * f[i - 1] : num(0)) - num(i) / n;
        f[i + 1] /= z;
    }
    vi dp(n + 1);
    FOR(i, 0, n + 1) dp[i] = f[i].toint();
    vi fac(n + 1, 1);
    FOR(i, 1, n + 1) fac[i] = mult(fac[i - 1], i);
    vi inv_fac(n + 1);
    FOR(i, 0, n + 1) inv_fac[i] = inv(fac[i]);
    auto binom = [&] (int n, int k) {
        return mult(fac[n], mult(inv_fac[k], inv_fac[n - k]));
    };
    map<int, int> cnt;
    int c = 0;
    FOR(i, 0, n) {
        if (a[i] != -1) {
            cnt[a[i]]++;
        }
        else {
            c++;
        }
    }
    vi g(c + 1);
    FOR(i, 0, c + 1) {
        int t = inv(k);
        g[i] = mult(binom(c, i), mult(fpow(t, i), fpow(1 - t + MOD, c - i)));
    }
    vi b(n + 1);
    FOR(i, 0, n + 1) b[i] = dp[n - i];
    auto ee = FFT::multiply(g, b);
    int res = 0;
    for (auto [v, x] : cnt) {
        addmod(res, ee[n - x]);
    }
    addmod(res, mult(k - sz(cnt), ee[n]));
    submod(res, dp[n]);
    cout << res << "\n";

}

int32_t main(int32_t argc, char* argv[]) {
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