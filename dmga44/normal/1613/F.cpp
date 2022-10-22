#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

///UH Top
#include <bits/stdc++.h>
#define db(x) cerr << #x << ':' << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
// #define int ll
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
// typedef __int128_t int128;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<ld,pdd> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
// typedef complex<ld> point;
// typedef vector<point> polygon;
// typedef vector<ll> vi;
// typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(998244353);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(2.5e5+5)

struct point
{
    typedef double value_type;
    double x, y;

    point(double x = 0, double y = 0) : x(x), y(y) {}
    point& operator+=(const point &rhs){ x += rhs.x, y += rhs.y; return *this;}
    point operator+(point rhs) const{return rhs += *this;}
    point operator-(const point &rhs) const{return point(x - rhs.x, y - rhs.y);}
    point operator*(const point &rhs) const{return point(x * rhs.x - y * rhs.y, y * rhs.x + x * rhs.y);}
    point& operator/=(double db){x /= db, y /= db; return *this;}
};

point conj(const point &p){return point(p.x, -p.y);}
double real(const point &p){return p.x;}
double imag(const point &p){return p.y;}

namespace fft
{
    const double PI = atan2(static_cast<point::value_type>(0), static_cast<point::value_type>(-1));
    vector<int> rev;
    vector<point> roots = {{0, 0}, {1, 0}};

    void ensure_size(int bits)
    {
        const int n = 1 << bits;
        if (rev.size() >= n) return;

        rev.resize(n);
        for (int i = 1, j = 0; i < n - 1; ++i)
        {
            for (int k = n >> 1; (j ^= k) < k; k >>= 1);
            rev[i] = j;
        }
        rev[n - 1] = n - 1;
        int cur_bits = __lg(roots.size());
        roots.resize(n);
        roots[0] = 1;
        for (; cur_bits < bits; ++cur_bits)
        {
            const double theta = 2 * PI / (1 << (cur_bits + 1));
            for (int i = 1 << (cur_bits - 1); i < (1 << cur_bits); i++)
            {
                roots[i << 1] = roots[i];
                double angle_i = theta * (2 * i + 1 - (1 << cur_bits));
                double y = sin(angle_i), x = cos(angle_i);
                //sincos(angle_i, &y, &x);
                roots[(i << 1) + 1] = point(x, y);
            }
        }
    }

    // n must be a power of 2, sign must be +1 or -1
    void fft_core(point a[], int n, int sign = +1)
    {
        ensure_size(__lg(n));
        int shift = __lg(rev.size() / n);
        if (sign == -1) reverse(a + 1, a + n);
        for (int i = 1; i < n - 1; ++i)
        {
            int j = rev[i] >> shift;
            if (j < i) swap(a[i], a[j]);
        }
        for (int m, mh = 1; (m = mh << 1) <= n; mh = m)
            for (int i = 0; i < n; i += m)
                for (int j = 0; j < mh; ++j)
                {
                    point u = a[i + j + mh] * roots[mh + j];
                    a[i + j + mh] = a[i + j] - u;
                    a[i + j] = a[i + j] + u;
                }
    }

    using ll = long long;

    // Compute ffts of two real arrays doing 1 fft instead of 2 ffts
    // n must be a power of 2
    template<typename T>
    pair<vector<point>, vector<point>> ffts(const vector<T> &a, const vector<T> &b, int n)
    {
        assert(n >= 1 && (n & (n - 1)) == 0);
        vector<point> p(n), pa(n), pb(n);
        for (int i = 0; i < n; ++i)
            p[i] = point(i < a.size() ? a[i] : 0, i < b.size() ? b[i] : 0);
        fft_core(p.data(), n, +1);
        for (int i = 0; i < n; ++i)
        {
            int j = (n - i) & (n - 1);
            point u = p[i], v = conj(p[j]);
            pa[i] = (u + v) * point(0.5, +0.0);
            pb[i] = (u - v) * point(0.0, -0.5);
        }
        return make_pair(move(pa), move(pb));
    }

    typedef long long ll;

    // this only works if intermediate values are less than 10^15
    vector<ll> convolve(const vector<int> &a, const vector<int> &b)
    {
        int n = a.size() + b.size() - 1, m = 1;
        while (m < n) m *= 2;
        vector<point> pa, pb;
        tie(pa, pb) = ffts(a, b, m);
        for (int i = 0; i < m; ++i)
        {
            pa[i] /= m;
            pa[i] = pa[i] * pb[i];
        }
        fft_core(pa.data(), m, -1);
        vector<ll> ans(n);
        for (int i = 0; i < n; ++i)
            ans[i] = llround(real(pa[i]));
        return ans;
    }

    // mod < 2^31
    vector<int> convolve(const vector<int> &a, const vector<int> &b, int mod, bool equal = false)
    {
        int n = a.size() + b.size() - 1;
        for (int k :{1, 2, 4, 8, 16})
            n |= (n >> k);
        n++;
        vector<point> pa(n), pb(n);
        for (int i = 0; i < n; ++i)
        {
            if (i < a.size()) pa[i] = point(a[i] >> 15, a[i] & ((1 << 15) - 1));
            if (i < b.size()) pb[i] = point(b[i] >> 15, b[i] & ((1 << 15) - 1));
        }
        fft_core(pa.data(), n, +1);
        if (equal) copy(pa.begin(), pa.end(), pb.begin());
        else fft_core(pb.data(), n, +1);
        vector<point> c(n), d(n);
        for (int i = 0; i < n; ++i)
        {
            int j = (n - i) & (n - 1);
            point u = (pa[i] + conj(pa[j])) * point(0.5, +0.0);
            point v = (pa[i] - conj(pa[j])) * point(0.0, -0.5);
            point x = (pb[i] + conj(pb[j])) * point(0.5, +0.0);
            point y = (pb[i] - conj(pb[j])) * point(0.0, -0.5);
            c[i] = u * (x + y * point(0, 1));
            d[i] = v * (x + y * point(0, 1));
            c[i] /= n;
            d[i] /= n;
        }
        fft_core(c.data(), n, -1);
        fft_core(d.data(), n, -1);
        vector<int> ans(a.size() + b.size() - 1);
        for (int i = 0; i < (int) ans.size(); ++i)
        {
            int u = llround(real(c[i])) % mod;
            int v = llround(imag(c[i])) % mod;
            int x = llround(real(d[i])) % mod;
            int y = llround(imag(d[i])) % mod;
            ans[i] = ((ll) u * (1 << 30) % mod + (ll) (v + x) * (1 << 15) % mod + y) % mod;
        }
        return ans;
    }
}

template<typename T>
vector<T>& operator+=(vector<T>& a, const vector<T>& b)
{
    if (a.size() < b.size())
        a.resize(b.size());
    for (int i = 0; i < (int)b.size(); ++i)
        a[i] += b[i];
    return a;
}

template<typename T>
vector<T> operator+(vector<T> a, const vector<T>& b){return a += b;}

template<typename T>
vector<T>& operator-=(vector<T>& a, const vector<T>& b)
{
    if (a.size() < b.size())
        a.resize(b.size());
    for (int i = 0; i < (int)b.size(); ++i)
        a[i] -= b[i];
    return a;
}

template<typename T>
vector<T> operator-(vector<T> a, const vector<T>& b){return a -= b;}

template<typename T>
vector<T> operator-(vector<T> a)
{
    for (int i = 0; i < (int)a.size(); ++i)
        a[i] = -a[i];
    return a;
}

template<typename T>
vector<T> operator*(const vector<T>& a, const vector<T>& b)
{
    if (a.empty() || b.empty())
        return {};

    if (min(a.size(), b.size()) < 150)
    {
        vector<T> c(a.size() + b.size() - 1, 0);
        for (int i = 0; i < (int)a.size(); ++i)
            for (int j = 0; j < (int)b.size(); ++j)
                c[i + j] += a[i] * b[j];
        return c;
    }

    vector<int> a_int(a.size()), b_int(b.size());
    for (int i = 0; i < (int)a.size(); ++i)
        a_int[i] = static_cast<int>(a[i]);
    for (int i = 0; i < (int)b.size(); ++i)
        b_int[i] = static_cast<int>(b[i]);

    vector<int> c_int = fft::convolve(a_int, b_int, T::mod);
    vector<T> c(c_int.size());
    for (int i = 0; i < (int)c.size(); ++i)
        c[i] = c_int[i];
    return c;
}

vector<point> operator*(vector<point> &a,vector<point> &b)
{
    int n=a.size();
    int m=b.size();
    int sum=n+m;
    while(sum!=(sum&-sum))
        sum+=(sum&-sum);
    while(a.size()<sum)
        a.push_back(point(0,0));
    while(b.size()<sum)
        b.push_back(point(0,0));

    fft::fft_core(a.data(),sum,1);
    fft::fft_core(b.data(),sum,1);

    vector<point> res(sum);
    for(int i=0;i<sum;i++)
    {
        res[i]=a[i]*b[i];
        res[i]/=sum;
    }
    fft::fft_core(res.data(),sum,-1);

    return res;
}

template<typename T>
vector<T>& operator*=(vector<T>& a, const vector<T>& b){return a = a * b;}

template<typename T>
vector<T> inverse(const vector<T>& a)
{
    assert(!a.empty());
    int n = (int)a.size();
    vector<T> b = {1 / a[0]};
    while ((int)b.size() < n)
    {
        vector<T> a_cut(a.begin(), a.begin() + min(a.size(), b.size() << 1));
        vector<T> x = b * b * a_cut;
        b.resize(b.size() << 1);
        for (int i = (int)b.size() >> 1; i < (int)min(x.size(), b.size()); ++i)
            b[i] = -x[i];
    }
    b.resize(n);
    return b;
}

template<typename T>
vector<T>& operator/=(vector<T>& a, vector<T> b)
{
    int n = (int)a.size();
    int m = (int)b.size();
    if (n < m)
        a.clear();
    else
    {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        b.resize(n - m + 1);
        a *= inverse(b);
        a.erase(a.begin() + n - m + 1, a.end());
        reverse(a.begin(), a.end());
    }
    return a;
}

template<typename T>
vector<T> operator/(vector<T> a, const vector<T>& b){return a /= b;}

template<typename T>
vector<T>& operator%=(vector<T>& a, const vector<T>& b)
{
    int n = (int)a.size();
    int m = (int)b.size();
    if (n >= m)
    {
        vector<T> c = (a / b) * b;
        a.resize(m - 1);
        for (int i = 0; i < m - 1; ++i)
            a[i] -= c[i];
    }
    return a;
}

template<typename T>
vector<T> operator%(vector<T> a, const vector<T>& b){return a %= b;}

template<const int _mod_>
struct mod_int
{
    static const int mod = _mod_;
    int val;

    mod_int(long long v = 0)
    {
        if (v < 0) v = v % mod + mod;
        if (v >= mod) v %= mod;
        val = v;
    }

    static int mod_inv(int a, int m = mod)
    {
        int g = m, r = a, x = 0, y = 1;
        while (r != 0)
        {
            int q = g / r;
            g %= r;
            swap(g, r);
            x -= q * y;
            swap(x, y);
        }
        return x < 0 ? x + m : x;
    }

    explicit operator int() const{return val;}

    mod_int& operator+=(const mod_int &other)
    {
        val += other.val;
        if (val >= mod) val -= mod;
        return *this;
    }

    mod_int& operator-=(const mod_int &other)
    {
        val -= other.val;
        if (val < 0) val += mod;
        return *this;
    }

    static unsigned fast_mod(uint64_t x, unsigned m = mod)
    {
#if !defined(_WIN32) || defined(_WIN64)
        return x % m;
#endif
        // Optimized mod for Codeforces 32-bit machines.
        // x must be less than 2^32 * m for this to work, so that x / m fits in a 32-bit integer.
        unsigned x_high = x >> 32, x_low = (unsigned) x;
        unsigned quot, rem;
        asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
        return rem;
    }

    mod_int& operator*=(const mod_int &other)
    {
        val = fast_mod((uint64_t) val * other.val);
        return *this;
    }

    mod_int& operator/=(const mod_int &other){return *this *= other.inv();}

    friend mod_int operator+(const mod_int &a, const mod_int &b){return mod_int(a) += b;}
    friend mod_int operator-(const mod_int &a, const mod_int &b){return mod_int(a) -= b;}
    friend mod_int operator*(const mod_int &a, const mod_int &b){return mod_int(a) *= b;}
    friend mod_int operator/(const mod_int &a, const mod_int &b){return mod_int(a) /= b;}

    mod_int& operator++()
    {
        val = val == mod - 1 ? 0 : val + 1;
        return *this;
    }

    mod_int& operator--()
    {
        val = val == 0 ? mod - 1 : val - 1;
        return *this;
    }

    mod_int operator++(int)
    {
        mod_int a = *this;
        ++*this;
        return a;
    }
    mod_int operator--(int)
    {
        mod_int a = *this;
        --*this;
        return a;
    }
    mod_int operator-() const{return val == 0 ? 0 : mod - val;}
    mod_int inv() const{return mod_inv(val);}

    bool operator==(const mod_int &other) const{return val == other.val;}
    bool operator!=(const mod_int &other) const{return val != other.val;}
    bool operator<(const mod_int &other) const{return val < other.val;}
    bool operator>(const mod_int &other) const{return val > other.val;}

    template<typename T>
    bool operator<(const T &other) const{return val < other;}

    template<typename T>
    bool operator>(const T &other) const{return val > other;}

    friend string to_string(const mod_int &m){return to_string(m.val);}
    friend mod_int abs(const mod_int &m){return mod_int(m.val);}

    friend ostream& operator<<(ostream &stream, const mod_int &m){return stream << m.val; }
    friend istream& operator>>(istream &stream, mod_int &m){return stream >> m.val;}
};

vector<int> g[MAXN];
bool mk[MAXN];
int sz[MAXN];

typedef mod_int<mod> mint;

void dfs(int u)
{
    mk[u]=1;
    for(auto v : g[u])
        if(!mk[v])
        {
            sz[u]++;
            dfs(v);
        }
}

vector<mint> mul(vector<vector<mint>>& p,int l,int r)
{
    if(l==r)
        return p[l];
    int mid=(l+r)>>1;
    vector<mint> m1=mul(p,l,mid);
    vector<mint> m2=mul(p,mid+1,r);
    while(m1.back()==0)
        m1.pop_back();
    while(m2.back()==0)
        m2.pop_back();
    return m1*m2;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0);

    vector<vector<mint>> to_mul;
    for(int i=0;i<n;i++)
        to_mul.push_back({1,sz[i]});

    vector<mint> poly=mul(to_mul,0,n-1);

    vector<mint> facs(n+1);
    facs[0]=1;
    for(int i=1;i<=n;i++)
        facs[i]=facs[i-1]*i;

    mint ans=0;
    for(int i=0;i<min(n,(int)poly.size());i++)
    {
        mint mul=1;
        if(i&1)
            mul=-1;
        mint add=facs[n-i]*mul*poly[i];
        ans+=add;
    }
    cout << ans << '\n';

    return 0;   
}