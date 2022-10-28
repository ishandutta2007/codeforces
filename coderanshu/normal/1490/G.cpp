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
    int n,m;
    cin>>n>>m;
    vector<ll> a(n+1),p(n+1);
    ll sum = 0;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        sum += a[i];
    }
    vector<pll> b;
    ll psum = 0;
    for(int i=1;i<=n;++i)
    {
        psum += a[i];
        if(b.empty() || psum > b.back().F)
        {
            b.push_back({psum,i});
        }
    }
    auto get = [&](ll x)
    {
        if(x == 0)
            return 0ll;
        ll lo = 0,hi = sz(b)-1,ans = hi;
        assert(b[hi].F >= x);
        while(lo<=hi)
        {
            ll mid = (lo+hi)/2;
            if(b[mid].F>=x)
                ans = mid,hi = mid-1;
            else
                lo = mid+1;
        }
        return b[ans].S;
    };
    for(int i=0;i<m;++i)
    {
        ll x;
        cin>>x;
        if(sum <= 0 && x > b.back().F)
        {
            cout<<"-1 ";continue;
        }
        ll ans = 0;
        if(x > b.back().F)
        {
            ans += ceil(1.0*(x-b.back().F)/sum)*n;
            x -= (ans/n)*sum;
        }
        ans += get(x);
        --ans;
        cout<<ans<<" ";
    }
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