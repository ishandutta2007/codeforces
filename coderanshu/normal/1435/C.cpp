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
template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}

const int N = 100005;

int cnt[N];

int _runtimeTerror_()
{
    vector<ll> a(6);
    for(int i=0;i<6;++i)
        cin>>a[i];
    int n;
    cin>>n;
    vector<pll> u;
    vector<ll> b(n);
    for(int i=0;i<n;++i)
    {
        cin>>b[i];
        for(int j=0;j<6;++j)
            u.pb({b[i]-a[j],i+1});
    }
    sort(all(u));
    int val = 0;
    ll ans = INF;
    auto add = [&](int i)
    {   
        if(cnt[u[i].S] == 0)
            ++val;
        ++cnt[u[i].S];
    };
    auto del = [&](int i)
    {
        if(cnt[u[i].S] == 1)
            --val;
        --cnt[u[i].S];
    };
    int l = 0,r = 0;
    for(int i=0;i<6*n;++i)
    {
        while(l<i)
            del(l++);
        while(r<6*n && val<n)
            add(r++);
        if(val==n)
            amin(ans,u[r-1].F-u[l].F);
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