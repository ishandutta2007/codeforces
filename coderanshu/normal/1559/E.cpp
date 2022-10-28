// Har Har Mahadev
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

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }

#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 2351
#endif

	
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

const int N=100005;
int lpf[N],mobius[N];

void _lpf_()
{
    lpf[1]=1;
    for(int i=2;i<=N-2;++i)
    {
        if(!lpf[i])
        {
            for(int j=i;j<=N-2;j+=i)
            {
                if(!lpf[j])
                    lpf[j]=i;
            }
        }
    }
}
void Mobius()
{
    mobius[1]=1;
    for(int i=2;i<=N-2;++i)
    {
        if(lpf[i/lpf[i]]==lpf[i])
            mobius[i]=0;
        else
            mobius[i]=-1*mobius[i/lpf[i]];
    }
}

const int L = 52;

int l[L],r[L];

Mint ans[N];

Mint dp[L][N], sum[L][N];

int _runtimeTerror_()
{
	_lpf_();
	Mobius();

    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;++i)
    	cin >> l[i] >> r[i];
    for(int i=1;i<=m;++i)
    {
    	if(mobius[i] == 0)
    		continue;

    	bool possible = true;

    	int up = m / i;
    	sum[0][0] = 1;
    	for(int j=1;j<=up;++j)
    		sum[0][j] = 1;
    	for(int j=1;j<=n;++j)
    	{
    		sum[j][0] = 0;
    		for(int k=1;k<=up;++k)
    		{
    			int lx = (l[j] + i - 1)/i, rx = (r[j] / i);
    			if(lx > rx)
    			{
    				possible = false;
    				break;
    			}
    			if(k >= lx)
    				dp[j][k] = sum[j-1][k-lx] - (k - rx - 1 >= 0 ? sum[j-1][k-rx-1] : 0);
    			sum[j][k] = sum[j][k-1] + dp[j][k];
    		}
    		if(!possible)
    			break;
    	}
    	// debug(possible);
    	for(int j=1;j<=up;++j)
    		ans[i] += dp[n][j];
    }

    // for(int i=1;i<=m;++i)
    	// cout << ans[i] << "\n";

    Mint val = 0;
    for(int i=1;i<=m;++i)
    	val += mobius[i] * ans[i];

    cout << val << "\n";
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
    int TESTS = 1;
    //cin >> TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}