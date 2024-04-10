#include<bits/stdc++.h>
using namespace std ;

#define ll              long long 
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define sz(a)           (ll)a.size()
#define F               first
#define S               second
#define INF             2000000000000000000
#define popcount(x)     __builtin_popcountll(x)
#define pll             pair<ll,ll> 
#define pii             pair<int,int>
#define ld              long double

const int M = 1000000007;
const int MM = 998244353;
const long double PI = acos(-1);

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}

    
const int MOD=1000000007;
struct Mint {
    int val;
 
    Mint(long long v = 0) {
        if (v < 0)
            v = v % MOD + MOD;
        if (v >= MOD)
            v %= MOD;
        val = v;
    }
 
    static int mod_inv(int a, int m = MOD) {
        int g = m, r = a, x = 0, y = 1;
        while (r != 0) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        } 
        return x < 0 ? x + m : x;
    } 
    explicit operator int() const {
        return val;
    }
    Mint& operator+=(const Mint &other) {
        val += other.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    Mint& operator-=(const Mint &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }
    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
           #if !defined(_WIN32) || defined(_WIN64)
                return x % m;
           #endif
           unsigned x_high = x >> 32, x_low = (unsigned) x;
           unsigned quot, rem;
           asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
           return rem;
    }
    Mint& operator*=(const Mint &other) {
        val = fast_mod((uint64_t) val * other.val);
        return *this;
    }
    Mint& operator/=(const Mint &other) {
        return *this *= other.inv();
    }
    friend Mint operator+(const Mint &a, const Mint &b) { return Mint(a) += b; }
    friend Mint operator-(const Mint &a, const Mint &b) { return Mint(a) -= b; }
    friend Mint operator*(const Mint &a, const Mint &b) { return Mint(a) *= b; }
    friend Mint operator/(const Mint &a, const Mint &b) { return Mint(a) /= b; }
    Mint& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }
    Mint& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }
    Mint operator++(int32_t) { Mint before = *this; ++*this; return before; }
    Mint operator--(int32_t) { Mint before = *this; --*this; return before; }
    Mint operator-() const {
        return val == 0 ? 0 : MOD - val;
    }
    bool operator==(const Mint &other) const { return val == other.val; }
    bool operator!=(const Mint &other) const { return val != other.val; }
    Mint inv() const {
        return mod_inv(val);
    }
    Mint power(long long p) const {
        assert(p >= 0);
        Mint a = *this, result = 1;
        while (p > 0) {
            if (p & 1)
                result *= a;
 
            a *= a;
            p >>= 1;
        }
        return result;
    }
    friend ostream& operator << (ostream &stream, const Mint &m) {
        return stream << m.val;
    }
    friend istream& operator >> (istream &stream, Mint &m) {
        return stream>>m.val;   
    }
};

template <typename T>
T extGcd(T a, T b, T& x, T& y) {
   if (b == 0) {
      x = 1;
      y = 0;
      return a;
   }
   else {
      int g = extGcd(b, a % b, y, x);
      y -= a / b * x;
      return g;
   }
}

template <typename T>
T modInv(T a, T m) {
   T x, y;
   extGcd(a, m, x, y);
   return (x % m + m) % m;
}

long long crt(const std::vector< std::pair<int, int> >& pp, int mod = -1);


#include <algorithm>


struct FFT_mod {
   int mod, root, root_1, root_pw;
};

extern FFT_mod suggested_fft_mods[5];
void ntt_shortmod(std::vector<int>& a, bool invert, const FFT_mod& mod_data);


const int mod = 1000000007;

vector<int> mull(const vector<int>& left, const vector<int>& right, const FFT_mod& mod_data) {
   vector<int> left1 = left, right1 = right;
   ntt_shortmod(left1, false, mod_data);
   ntt_shortmod(right1, false, mod_data);

   for (int i = 0; i < left.size(); i++) {
      left1[i] = (left1[i] * 1ll * right1[i]) % mod_data.mod;
   }

   ntt_shortmod(left1, true, mod_data);
   return left1;
}


vector<int> mult(vector<int> &left, vector<int> &right) {
   int ssss = left.size() + right.size() - 1;
   int pot2;
   for (pot2 = 1; pot2 < ssss; pot2 <<= 1);

   left.resize(pot2);
   right.resize(pot2);

   vector<int> res[3];
   for (int i = 0; i < 3; i++) {
      res[i] = mull(left, right, suggested_fft_mods[i]);
   }

   vector<int> ret(pot2);
   for (int i = 0; i < pot2; i++) {
      vector< pair<int,int> > mod_results;
      for (int j = 0; j < 3; j++) {
         mod_results.emplace_back(res[j][i], suggested_fft_mods[j].mod);
      }
      ret[i] = crt(mod_results, mod);
   }
   return ret;
}

long long crt(const std::vector< std::pair<int, int> >& a, int mod) {
   long long res = 0;
   long long mult = 1;

   int SZ = a.size();
   std::vector<int> x(SZ);
   for (int i = 0; i<SZ; ++i) {
      x[i] = a[i].first;
      for (int j = 0; j<i; ++j) {
         long long cur = (x[i] - x[j]) * 1ll * modInv(a[j].second,a[i].second);
         x[i] = (int)(cur % a[i].second);
         if (x[i] < 0) x[i] += a[i].second;
      }
      res = (res + mult * 1ll * x[i]);
      mult = (mult * 1ll * a[i].second);
      if (mod != -1) {
         res %= mod;
         mult %= mod;
      }
   }

   return res;
}


FFT_mod suggested_fft_mods[] = {
   { 7340033, 5, 4404020, 1 << 20 },
   { 415236097, 73362476, 247718523, 1<<22 },
   { 463470593, 428228038, 182429, 1<<21},
   { 998244353, 15311432, 469870224, 1 << 23 },
   { 918552577, 86995699, 324602258, 1 << 22 }
};

int FFT_w[1050000];
int FFT_w_dash[1050000];


void ntt_shortmod(std::vector<int>& a, bool invert, const FFT_mod& mod_data) {
   // only use if mod < 5*10^8
   int n = (int)a.size();
   int mod = mod_data.mod;

   for (int i = 1, j = 0; i<n; ++i) {
      int bit = n >> 1;
      for (; j >= bit; bit >>= 1)
         j -= bit;
      j += bit;
      if (i < j)
         std::swap(a[i], a[j]);
   }

   for (int len = 2; len <= n; len <<= 1) {
      int wlen = invert ? mod_data.root_1 : mod_data.root;
      for (int i = len; i<mod_data.root_pw; i <<= 1)
         wlen = int(wlen * 1ll * wlen % mod_data.mod);

      long long tt = wlen;
      for (int i = 1; i < len / 2; i++) {
         FFT_w[i] = tt;
         FFT_w_dash[i] = (tt << 31) / mod;
         int q = (FFT_w_dash[1] * 1ll * tt) >> 31;
         tt = (wlen * 1ll * tt - q * 1ll * mod) & ((1LL << 31) - 1);
         if (tt >= mod) tt -= mod;
      }
      for (int i = 0; i<n; i += len) {
         int uu = a[i], vv = a[i + len / 2] % mod;
         if (uu >= 2*mod) uu -= 2*mod;
         a[i] = uu + vv;
         a[i + len / 2] = uu - vv + 2 * mod;

         for (int j = 1; j<len / 2; ++j) {
            int u = a[i + j];
            if (u >= 2*mod) u -= 2*mod;
            int q = (FFT_w_dash[j] * 1ll * a[i + j + len / 2]) >> 31;
            int v = (FFT_w[j] * 1ll * a[i + j + len / 2] - q * 1ll * mod) & ((1LL << 31) - 1);
            a[i + j] = u + v;
            a[i + j + len / 2] = u - v + 2*mod;
         }
      }
   }
   if (invert) {
      int nrev = modInv(n, mod);
      for (int i = 0; i<n; ++i)
         a[i] = int(a[i] * 1ll * nrev % mod);
   }
}

const int N = 100005;

Mint fac[N],fac_inv[N];

int _runtimeTerror_()
{
    ll n,k;
    cin>>n>>k;
    if(n > k)
    {
        cout<<"0\n";return 0;
    }
    vector<vector<int>> dp(20,vector<int>(k+1,0));
    for(int i=1;i<=k;++i)
        dp[0][i] = 1;
    for(int i=1;i<=19;++i)
    {
        vector<int> l = dp[i-1],r = dp[i-1];
        int len = (1<<(i-1));
        for(int i=1;i<=k;++i)
        {
            l[i] = int(l[i] * fac_inv[i] * Mint(2).power(i*1ll*len));
            r[i] = int(r[i] * fac_inv[i]);
        }
        dp[i] = mult(l,r);
        dp[i].resize(k+1);
        for(int j=1;j<=k;++j)
            dp[i][j] = int(dp[i][j] * fac[j]);
    }
    vector<int> ans(k+1,0);
    ans[0] = 1;
    int cur = 0;
    for(int i=0;i<20;++i)
    {
        if(n&(1<<i))
        {
            vector<int> l = dp[i],r = ans;
            int len = cur;
            for(int j=1;j<=k;++j)
            {
                l[j] = int(l[j] * fac_inv[j] * Mint(2).power(j*1ll*len));
                r[j] = int(r[j] * fac_inv[j]);
            }
            ans = mult(l,r);
            ans.resize(k+1);
            for(int j=1;j<=k;++j)
                ans[j] = int(ans[j] * fac[j]);
            cur += (1<<i);
        }
    }
    Mint val = 0;
    for(int i=1;i<=k;++i)
        val += ans[i] * fac[k] * fac_inv[i] * fac_inv[k-i];
    cout<<val<<"\n";
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initialize();
    #endif
    int TESTS=1;
    fac[0] = fac_inv[0] = 1;
    for(int i=1;i<N;++i)
    {
        fac[i] = fac[i-1] * i;
        fac_inv[i] = fac_inv[i-1] / i;
    }
    //cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}