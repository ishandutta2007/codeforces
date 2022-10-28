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
    ll n,m;
    cin>>n>>m;
    set<pii> s;
    for(int i=1;i<=m;++i)
    {
        int x,y;
        cin>>x>>y;
        s.insert({y,x-1});
    }
    bool ans = true;
    bool one = false;
    pii x;
    int cur = n+1;
    while(!s.empty())
    {
        if(one)
        {   
            pii u = *s.rbegin();
            assert(u.F<x.F);
            if(x.S == u.S)
            {
                if((x.F-u.F)%2==0)
                {
                    ans = false;
                    break;
                }
            }
            else
            {
                if((x.F-u.F)%2!=0)
                {
                    ans = false;
                    break;
                }
            }
            one = false;
            s.erase(u);
            cur = u.F;
            continue;
        }
        auto u = *s.rbegin();
        s.erase(*s.rbegin());
        if(u.F>=cur)
        {
            ans = false;break;
        }
        if(s.count({u.F,u.S^1}))
        {
            s.erase({u.F,u.S^1});
            continue;
        }
        one = true;
        cur = u.F;
        x = u;
    }
    if(one)
        ans = false;
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