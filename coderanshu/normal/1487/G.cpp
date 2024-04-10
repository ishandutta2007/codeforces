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

    
const int MOD=MM;
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

Mint ans = 0;


const int N = 410,K = 26;
Mint dp[2][N][N][3][3];

int cnt[K+2];

Mint sum[N][N];

Mint dp2[2][N][2][2];

int _runtimeTerror_()
{
    int n;
    cin >> n;
    for(int i=0;i<26;++i)
    {
        cin >> cnt[i];
    }
    for(int i=0;i<3;++i)
    {
        for(int j=0;j<3;++j)
        {
            Mint val = 1;
            int one = (i==0) + (j==0);
            int two = (i==1) + (j==1);
            if(i==2)
                val *= 24;
            if(j == 2)
                val *= 24;
            dp[0][one][two][i][j] += val;
        }
    }
    int c = n/2+1;
    for(int i=3;i<=n;++i)
    {
        for(int j=0;j<=c;++j)
            for(int k=0;k<=c;++k)
                for(int l=0;l<3;++l)
                    for(int m=0;m<3;++m)
                        dp[i%2][j][k][l][m] = 0;
        for(int j=0;j<=c;++j)
        {
            for(int k=0;k<=c;++k)
            {
                for(int l=0;l<3;++l)
                {
                    for(int m=0;m<3;++m)
                    {
                        Mint u = dp[(i-1)%2][j][k][l][m];
                        dp[i%2][j][k][m][2] += u*(24-(l==2));
                        if(l == 0)
                            dp[i%2][j][k+1][m][1] += u;
                        else if(l == 1)
                            dp[i%2][j+1][k][m][0] += u;
                        else if(l == 2)
                            dp[i%2][j+1][k][m][0] += u,dp[i%2][j][k+1][m][1] += u;
                    }
                }                    
            }
        }
    }
    Mint ans = Mint(25).power(n-2)*26*26;
    for(int i=400;i>=0;--i)
    {
        for(int j=400;j>=0;--j)
        {
            for(int x=0;x<3;++x)
                for(int y=0;y<3;++y)
                    sum[i][j] += dp[n%2][i][j][x][y];
            sum[i][j] += sum[i+1][j] + sum[i][j+1] - sum[i+1][j+1];
        }
    }
    vector<Mint> T(26,0);
    for(int i=0;i<26;++i)
    {
        for(int j=i+1;j<26;++j)
        {
            ans -= sum[cnt[i]+1][cnt[j]+1];
        }
        for(int j=0;j<26;++j)
        {
            if(i!=j)
                T[i] -= sum[cnt[i]+1][cnt[j]+1];
        }
    }
    for(int i=0;i<2;++i)
    {
        for(int j=0;j<2;++j)
        {
            Mint val = 1;
            if(i == 1)
                val *= 25;
            if(j == 1)
                val *= 25;
            int one = 0;
            one = (i==0) + (j==0);
            dp2[0][one][i][j] += val;
        }
    }
    for(int i=3;i<=n;++i)
    {
        for(int j=0;j<=n;++j)
                for(int l=0;l<2;++l)
                    for(int m=0;m<2;++m)
                        dp2[i%2][j][l][m] = 0;
        for(int j=0;j<=n;++j)
        {
            for(int l=0;l<2;++l)
            {
                for(int m=0;m<2;++m)
                {
                    Mint u = dp2[(i-1)%2][j][l][m];
                    dp2[i%2][j][m][1] += u*(25-(l==1));
                    if(l == 1)
                        dp2[i%2][j+1][m][0] += u;
                }
            }                    
        }
    }
    for(int i=0;i<26;++i)
    {
        for(int j=cnt[i]+1;j<=n;++j)
        {
            for(int k=0;k<2;++k)
            {
                for(int l=0;l<2;++l)
                {
                    T[i] += dp2[n%2][j][k][l];
                }
            }
        }
    }
    for(int i=0;i<26;++i)
    {
        ans -= T[i];
    }
    cout<<ans<<"\n";
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