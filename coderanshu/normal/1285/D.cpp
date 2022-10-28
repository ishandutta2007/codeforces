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

ll go_(vector<int> &a,int bit = 29)
{
    if(bit < 0)
        return 0;
    if(a.empty())
        return (1LL<<30);
    vector<int> l,r;
    int n = sz(a);
    for(int i=0;i<n;++i)
    {
        if(a[i]&(1<<bit))
            l.pb(a[i]);
        else
            r.pb(a[i]);
    }
    ll ans = (1<<bit);
    if(l.empty() || r.empty())
        ans = 0;
    return ans + min(go_(l,bit-1),go_(r,bit-1));
}

int _runtimeTerror_()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;++i)
        cin>>v[i];

    cout<<go_(v)<<"\n";
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