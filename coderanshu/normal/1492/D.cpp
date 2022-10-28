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
    int a,b,k;
    cin>>a>>b>>k;
    if(b == 1)
    {
        if(k == 0)
        {
            string ans;
            ans += "1";
            for(int i=0;i<a;++i)
                ans += "0";
            cout<<"Yes\n"<<ans<<"\n"<<ans<<"\n";
            return 0;
        }
        else
        {
            cout<<"No\n";return 0;
        }
    }
    if(k > a)
    {
        if(k>a+b-2 || a < 1)
        {
            cout<<"No\n";return 0;
        }
        int d = k-a;
        string x,y;
        x += "1",y += "1";
        for(int i=0;i<b-(d+2);++i)
            x += "1",y += "1";
        x += "1";
        y += "0";
        for(int i=0;i<d;++i)
            x += "1",y += "1";
        for(int i=0;i<a-1;++i)
            x += "0",y += "0";
        x += "0",y += "1";
        cout<<"Yes\n";
        cout<<x<<"\n"<<y<<"\n";
        return 0;
    }
    cout<<"Yes\n";
    for(int i=0;i<b;++i)
        cout<<"1";
    for(int i=0;i<a;++i)
        cout<<"0";
    cout<<"\n";
    for(int i=0;i<b-1;++i)
        cout<<"1";
    for(int i=0;i<k;++i)
        cout<<"0";
    cout<<"1";
    for(int i=0;i<a-k;++i)
        cout<<"0";
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