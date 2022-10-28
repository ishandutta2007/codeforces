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

ll power(ll b,ll e,ll m)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b%m,e/2,m)%m;
    return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b,e/2);
    return power(b*b,e/2);
}

#define runSieve
const int N=20000001;
bool is_composite[N];
int lpf[N];
int dp[N];
void sieve (int n = N) {
    vector<int> prime;
    for (int i = 2; i < n; ++i) {
        if (!is_composite[i]) prime.push_back (i),lpf[i] = i;
        for (int j = 0; j < prime.size () && i * prime[j] < n; ++j) {
            is_composite[i * prime[j]] = true;
            lpf[i*prime[j]] = prime[j];
            if (i % prime[j] == 0) break;
        }
    }
}

int _runtimeTerror_()
{
    ll c,d,x;
    cin>>c>>d>>x;
    ll ans = 0;
    auto get = [&](ll y)
    {
        ll z = x + y * d;
        if(z % (c*y))
            return 0ll;
        z /= c*y;
        return (1LL<<dp[z]);
    };
    for(ll g=1;g*g<=x;++g)
    {
        if(x%g == 0)
        {
            ans += get(g);
            if(g != x/g)
                ans += get(x/g);
        }
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
    for(int i=2;i<N;++i)
    {
        if(!is_composite[i])
            dp[i] = 1;
        else
            dp[i] = dp[i/lpf[i]] + (lpf[i] != lpf[i/lpf[i]]);
    }
    int TESTS=1;
    cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}