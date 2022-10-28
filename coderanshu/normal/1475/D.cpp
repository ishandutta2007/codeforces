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
    vector<int> a(n+1),b(n+1);
    vector<ll> sum1(n+1,0),sum2(n+1,0),v,w;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int i=1;i<=n;++i)
    {
        cin>>b[i];
        if(b[i] == 1)
            v.pb(a[i]);
        else
            w.pb(a[i]);
    }
    ll ans = INF;
    sort(all(v),greater<ll>());
    sort(all(w),greater<ll>());
    int x = sz(v),y = sz(w);
    sum1.resize(x+1),sum2.resize(y+1);
    for(int i=1;i<=x;++i)
        sum1[i] = sum1[i-1] + v[i-1];
    for(int i=1;i<=y;++i)
        sum2[i] = sum2[i-1] + w[i-1];
    for(int i=0;i<=x;++i)
    {
        ll rem = m - sum1[i];
        auto it = lower_bound(all(sum2),rem)-sum2.begin();
        if(it>y)
            continue;
        amin(ans,i+it*2);
    }
    if(ans == INF)
        ans = -1;
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
    cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}