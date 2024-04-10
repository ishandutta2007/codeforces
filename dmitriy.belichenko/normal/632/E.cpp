#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <cassert>
#include <ctime>
#include <random>
#include <bitset>
#define forn(i, n) for (int i = 0; i < n; i++)
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) x.size()
#define ld long double
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

const int N = 100, M = 20;

int read() {
    int x; cin >> x; return x;
}

mt19937 rng(20190);

int mod = 998244353;
 int MOD = mod;
//const int primitive_root_mod = 3;
int root = 15311432;
int root_1 = 469870224;
int root_pw = 1 << 23;

int prod(int u, int v) {
    return (u * 1LL * v) % mod;
}

int sum(int u, int v) {
    return (u + v) % mod;
}

int mpow(int u, int p) {
    if (!p) return 1;
    int x = mpow(u, p / 2);
    return prod(prod(x, x), p & 1 ? u : 1);
}

int inverse(int x) {
    return mpow(x, mod - 2);
}

inline void fft(vector<int> & a, bool invert) {
    int n = (int)a.size();
    
    for (int i = 1, j = 0; i < n; ++i) {
        int bit = n >> 1;
        for (; j >= bit; bit >>= 1)
            j -= bit;
        j += bit;
        if (i < j)
            swap(a[i], a[j]);
    }
    
    for (int len = 2; len <= n; len <<= 1) {
        int wlen = invert ? root_1 : root;
        for (int i = len; i < root_pw; i <<= 1)
            wlen = int(wlen * 1ll * wlen % mod);
        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; ++j) {
                int u = a[i + j], v = int(a[i + j + len / 2] * 1ll * w % mod);
                a[i + j] = u + v < mod ? u + v : u + v - mod;
                a[i + j + len / 2] = u - v >= 0 ? u - v : u - v + mod;
                w = int(w * 1ll * wlen % mod);
            }
        }
    }
    if (invert) {
        int nrev = inverse(n);
        for (int i = 0; i < n; ++i)
            a[i] = int(a[i] * 1ll * nrev % mod);
    }
}

inline vi poly_prod(vi const &p1, vi const &p2) {
    vector<int> prod1 = vector<int>(p1.begin() , p1.end());
    vector<int> prod2 = vector<int>(p2.begin() , p2.end());
    int x = sz(prod1) - 1;
    while (prod1[x] == 0)
        --x;
    int y = sz(prod2) - 1;
    while (prod2[y] == 0)
        --y;
    int g = 0;
    while ((1 << g) < (x + y + 1))
        ++g;
    prod1.resize(1 << g, 0);
    prod2.resize(1 << g, 0);
    fft(prod1, false);
    fft(prod2, false);
    for (int i = 0; i < sz(prod1); ++i)
        prod1[i] = prod(prod1[i], prod2[i]);
    fft(prod1, true);
    return prod1;
}

vector<int> multiply_sq(vector<int> const& a){
    vector<int> fa(a.begin(), a.end());
    int n = 1;
    while(n < (a.size()<<1))
        n <<= 1;
    fa.resize(n);
    
    fft(fa, false);
    for(int i=0;i<n;i++)
        fa[i] = (int)(1LL*fa[i]*fa[i]%MOD);
    fft(fa, true);
    return fa;
}

template<class A, class B>
void sum(A &a, B b)
{
    a += b;
    if (a < 0LL) a += MOD;
    if (a >= MOD) a -= MOD;
}
ll add(ll a, ll b)
{
    a += b;
    if (a < 0) a += MOD;
    if (a >= MOD) a -= MOD;
    return a;
    
}
int to_i(char c)
{
    return c - 'a';
}
ll mult(ll a, ll b) {
    ll val = a * b - (ll) ((ld) a * b / MOD) * MOD;
    if (val < 0) {
        val += MOD;
    }
    if (val >= MOD) {
        val -= MOD;
    }
    return val;
}

ll gcd (ll a, ll b)
{
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}
ll gcd_eu (ll a, ll b, ll & x, ll & y)
{
    if (a == 0)
    {
        x = 0LL; y = 1LL;
        return b;
    }
    ll x1, y1;
    ll d = gcd_eu (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
long long poww(long long a, long long b)
{
    long long val = 1;
    a %= MOD;
    while (b > 0)
    {
        if (b % 2) val = mult(a, val);
        a = mult(a, a);
        b >>= 1;
    }
    return val % MOD;
}
ll inv(ll a)
{
    return poww(a , MOD - 2);
}
vector<int> bpow(vector<int> &poly, long long b)
{
    vector<int> val = {1};
    while (b > 0)
    {
        if (b % 2) val = poly_prod(val , poly);
        poly = multiply_sq(poly);
        b >>= 1;
    }
    return val;
}
vector<int> poly(1005 , 0);
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n , k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        int u;
        cin >> u;
        poly[u] = 1;
    }
    vector<int> a= poly;
    
    poly = bpow(poly, k);
    mod = 7340033;
    root = 5;
    MOD = mod;
    root_1 = 4404020;
    root_pw = 1<<20;
    a = bpow(a, k);
    for(int i = 0; i < poly.size(); i++)
    {
        if( a[i]  > 0 || poly[i] > 0)
        {
            cout << i << " ";
        }
    }
    return 0;
}