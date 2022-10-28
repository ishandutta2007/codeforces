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
    ll n;
    cin>>n;
    ll cur = -1;
    int cnt = 0;
    ll y = n;
    for(ll i=2;i*i<=n;++i)
    {
        if(n%i==0)
        {
            ll u = 0;
            while(n%i==0)
                ++u,n/=i;
            if(u>cnt)
                cnt = u,cur = i;
        }
    }
    if(cur==-1)
    {
        cout<<"1\n"<<n<<"\n";
        return 0;
    }
    cout<<cnt<<"\n";
    for(int i=0;i<cnt-1;++i)
    {
        y/=cur;
        cout<<cur<<" ";
    }
    cout<<y<<"\n";
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