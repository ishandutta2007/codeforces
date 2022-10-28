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

ll power(ll b,ll e,ll m)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b%m,e/2,m)%m;
    return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b,e/2);
    return power(b*b,e/2);
}
template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}

const int N = 200005;

bitset<N> vis;

int _runtimeTerror_()
{
    int n,k;
    cin>>n>>k;
    vector<int> v,ans;
    int cur = 1;
    auto add = [&](int i)
    {
        if(i!=cur)
        {
            cout<<"-1\n";
            exit(0);
        }
        ++cur;
    };
    v.pb(n);
    for(int i=1;i<=k;++i)
    {
        int p;
        cin>>p;
        ans.pb(p);
        vis[p] = 1;
        while(!v.empty() && v.back()<p)
            add(v.back()),v.pop_back();
        v.push_back(p);
    }
    int pr = 1;
    while(!v.empty())
    {
        for(int i=v.back();i>=pr;--i)
            if(!vis[i])
                ans.pb(i);
        pr = v.back();
        v.pop_back();
    }
    for(auto j:ans)
        cout<<j<<" ";
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