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
    ll n;
    cin>>n;
    if(n&1)
    {
        cout<<"-1\n";
        return 0;
    }
    set<ll> v;
    vector<int> ans;
    for(int i=2;i<=64;++i)
    {
        v.insert((1LL<<i)-2);
    }
    while(n)
    {
        auto it = v.upper_bound(n);
        --it;
        ll x = *it;
        // cout<<x<<"\n";
        for(int i=2;i<=64;++i)
        {
            if((1LL<<i)-2 == x)
            {
                ans.pb(1);
                for(int j=0;j<i-2;++j)
                    ans.pb(0);
                break;
            }
        }
        n -= x;
    }
    cout<<sz(ans)<<"\n";
    for(auto j:ans)
        cout<<j<<" ";
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