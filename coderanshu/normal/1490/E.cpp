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
    int n;
    cin>>n;
    vector<pll> a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i].F;
        a[i].S = i+1;
    }
    sort(all(a));
    int lo = 0,hi = n-1,ans = n-1;
    auto f = [&](int x)
    {
        ll sum = 0;
        for(int i=0;i<=x;++i)
            sum += a[i].F;
        for(int i=x+1;i<n;++i)
        {
            if(sum >= a[i].F)
                sum += a[i].F;
            else
                return false;
        }
        return true;
    };
    while(lo<=hi)
    {
        int mid = (lo+hi)/2;
        if(f(mid))
            ans = mid,hi = mid-1;
        else
            lo = mid+1;
    }
    vector<int> p;
    for(int i=0;i<n;++i)
    {
        if(a[i].F >= a[ans].F)
            p.pb(a[i].S);
    }
    cout<<sz(p)<<"\n";
    sort(all(p));
    for(auto &j:p)
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