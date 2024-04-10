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
const long double PI = acos(-1);

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}

int _runtimeTerror_()
{
    ll n,k;
    cin>>n>>k;
    vector<int> ans(n+1);
    auto get = [&](int l)
    {
        if(l == 0)
            return 1ll;
        --l;
        return (1LL<<l);
    };
    if(n <= 61 && k > get(n))
    {
        cout<<"-1\n";return 0;
    }
    for(int i=1;i<=n-61;++i)
        ans[i] = i;
    for(int i=max(n-60,1ll);i<=n;++i)
    {
        int len = n - i + 1;
        int val = -1;
        for(int j=1;j<=len;++j)
        {
            if(get(len-j) >= k)
            {
                val = j;
                break;
            }
            k -= get(len-j);
        }
        assert(val != -1);
        int cur = i;
        for(int j=i+val-1;j>=i;--j)
        {
            ans[j] = cur++;
        }
        i += val-1;
    }
    for(int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
    cout<<"\n";
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
    cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}