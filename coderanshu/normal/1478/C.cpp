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
    vector<ll> a(2*n);
    map<ll,ll> mp;
    for(int i=0;i<2*n;++i)
    {
        cin>>a[i];
        ++mp[a[i]];
    }
    for(auto &j:mp)
    {
        if(j.S != 2)
        {
            cout<<"NO\n";return 0;
        }
    }
    sort(all(a));
    a.resize(unique(all(a))-a.begin());
    if(a[0]%2!=0)
    {
        cout<<"NO\n";return 0;
    }
    ll sum = a[0]/2;
    ll u = 0;
    for(int i=1;i<n;++i)
    {
        if((a[i]-a[i-1])%(2*i) != 0)
        {
            cout<<"NO\n";return 0;
        }
        u += ((a[i]-a[i-1])/(2*i));
        sum -= u;
    }
    if(sum>0 && sum%n==0)
    {
        cout<<"YES\n";return 0;
    }
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