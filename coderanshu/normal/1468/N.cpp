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
    ll c1,c2,c3;
    ll a1,a2,a3,a4,a5;
    cin>>c1>>c2>>c3>>a1>>a2>>a3>>a4>>a5;
    c1 -= a1;
    c2 -= a2;
    c3 -= a3;
    if(c1 < 0 || c2<0 || c3<0)
    {
        cout<<"NO\n";return 0;
    }
    ll x = min(c1,a4);

    c1 -= x;
    a4 -= x;
    x = min(c2,a5);
    c2 -= x;
    a5 -= x;
    if(a4 + a5<=c3)
        cout<<"YES\n";
    else
        cout<<"NO\n";
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