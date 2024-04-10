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
    int n,x;
    cin>>n>>x;
    int l = 0;
    if(x<(1<<n))
        l = ((1<<n)-1)/2;
    else
        l = (1<<n)-1;
    cout<<l<<"\n";
    vector<int> v;
    vector<bool> no(1<<18,false);
    no[x] = no[0] = true;
    for(int i=1;i<(1<<n);++i)
    {
        if(!no[i])
            v.pb(i),no[i^x] = true;
    }
    int cur = 0;
    for(auto j:v)
    {
        cout<<(cur^j)<<" ";
        cur = j;
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
    //cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}