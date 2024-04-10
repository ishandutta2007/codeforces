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
    ll n,l,r,s;
    cin>>n>>l>>r>>s;
    ll len = (r - l + 1);
    if(s < len * (len + 1)/2 || s > n * (n + 1)/2 - (n-len)*(n-len+1)/2)
    {
        cout<<"-1\n";return 0;
    }
    vector<int> a(n+1,0);
    ll cur = len * (len + 1)/2;
    int lf = 1,rg = len;
    while(s - cur > len)
        ++lf,++rg,cur += len;
    vector<int> v;
    if(s > cur)
    {
        s -= cur;
        for(int i=lf;i<=rg;++i)
        {
            if(i + s == rg + 1)
                continue;
            v.push_back(i);
        }
        v.push_back(rg+1);
    }
    else
        for(int i=lf;i<=rg;++i)
            v.push_back(i);
    vector<int> rem;
    for(int i=1;i<=n;++i)
    {
        bool have = false;
        for(int j:v)
            if(j == i)
                have = true;
        if(!have)
            rem.push_back(i);
    }
    for(int i=1;i<=n;++i)
    {
        if(i < l || i > r)
        {
            cout<<rem.back()<<" ";
            rem.pop_back();
        }
        else
        {
            cout<<v.back()<<" ";
            v.pop_back();
        }
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
    cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}