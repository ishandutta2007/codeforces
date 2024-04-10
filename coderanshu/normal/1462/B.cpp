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
    string s;
    cin>>n>>s;
    string u;
    for(int i=0;i<4;++i)
        u += s[i];
    bool ans = false;
    if(u == "2020")
        ans = true;
    u = s.substr(0,3) + s.substr(n-1,1);
    if(u=="2020")
        ans = true;
    u = s.substr(0,2) + s.substr(n-2,2);
    if(u=="2020")
        ans = true;
    u = s.substr(0,1) + s.substr(n-3,3);
    if(u=="2020")
        ans = true;
    u = s.substr(n-4,4);
    if(u=="2020")
        ans = true;
    cout<<(ans?"YES":"NO")<<"\n";
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