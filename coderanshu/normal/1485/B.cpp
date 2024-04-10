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
    int n,q;
    ll k;
    cin>>n>>q>>k;
    vector<ll> a(n+1);
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    for(int i=0;i<q;++i)
    {
        int l,r;
        cin>>l>>r;
        if(l==r)
            cout<<k-1<<"\n";
        else
        {
            int x = r-l+1;
            ll ans = 0;
            ans += a[l+1]-2;
            ans += k-a[r-1]-1;
            if(x == 3)
                ans += a[r]-a[l]-2;
            else if(x>=4)
                ans += a[r]+a[r-1]-a[l]-a[l+1]-2*(x-2);
            cout<<ans<<"\n";
        }
    }
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