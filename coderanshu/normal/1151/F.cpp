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

struct Matrix
{
    vector<vector<Mint>> val;
    ll n_;
    Matrix (ll n) : n_(n)
    {
        val.resize(n_);
        for(ll i=0;i<n_;++i)
            val[i].resize(n_);
    }
    void print()
    {
        for(ll i=0;i<n_;++i)
        {
            for(ll j=0;j<n_;++j)
                cout<<val[i][j]<<" ";
            cout<<"\n";
        }
    }
    void set(ll x)
    {
        for(ll i=0;i<n_;++i)
            for(ll j=0;j<n_;++j)
                val[i][j]=x;
    }
    Matrix operator*(const Matrix& b) const 
    {
        ll n=n_;
        Matrix ans(n);
        ans.set(0);
        for(ll i=0;i<n_;++i)
        {
            for(ll j=0;j<n_;++j)
            {
                ans.val[i][j]=0;
                for(ll k=0;k<n_;++k)
                {
                    ans.val[i][j]+= val[i][k]*b.val[k][j];
                }

            }
        }
        return ans;
    }
};
Matrix I(ll n)
{
    Matrix Iden(n);
    Iden.set(0);
    for(ll i=0;i<n;++i)
        Iden.val[i][i]=1;
    return Iden;
}
Matrix power(Matrix m,ll pw)
{
    if(pw==0)
        return I(m.n_);
    if(pw==1)
        return m;
    Matrix t=power(m,pw/2);
    t=t*t;
    if(pw&1)
        t=t*m;
    return t;
}

int _runtimeTerror_()
{
    int n,k;
    cin>>n>>k;
    int zero = 0;
    vector<int> a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        zero += a[i]==0;
    }
    int cur = 0;
    for(int i=0;i<zero;++i)
        cur += a[i]==1;
    // ans[i] = probability that among first zeroes , i ones are there 
    vector<Mint> ans(zero+1,0);
    ans[cur] = 1;
    Matrix dp(zero+1);
    dp.set(0);
    Mint x = n*(n-1)/2;
    for(int i=0;i<=zero;++i)
    {
        // for row i
        dp.val[i][i] = i*i + (zero-i)*(n-zero-i);
        dp.val[i][i] = 1 - dp.val[i][i]/x;
        if(i)
            dp.val[i][i-1] = (zero-i+1)*(n-zero-i+1)/x;
        if(i<zero)
            dp.val[i][i+1] = (i+1)*(i+1)/x;
    }
    dp = power(dp,k);
    Mint A = 0;
    for(int i=0;i<=zero;++i)
        A += dp.val[0][i] * ans[i];
    cout<<A<<"\n";
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
    //cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}