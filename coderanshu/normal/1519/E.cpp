// Har Har Mahadev
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

const int N = 400005;

bool vis[N];
int dep[N];
vector<pii> v[N];

vector<pii> res;

bool dfs(int u,int p,int id)
{
    vis[u] = true;
    vector<int> boom;
    for(auto &[j,k]:v[u])
    {
        if(!vis[j])
        {
            dep[j] = dep[u] + 1;
            if(dfs(j,u,k))
                boom.push_back(k);
        }
        else if(vis[j] && k != id && dep[j] < dep[u])
        {
            boom.push_back(k);
        }
    }
    bool ret = true;
    if(sz(boom) % 2)
    {
        if(p == 0)
        {
            boom.pop_back();
        }
        else
        {
            boom.push_back(id),ret = false;
        }
    }
    for(int i=0;i<sz(boom);i+=2)
    {
        res.push_back({boom[i],boom[i+1]});
    }
    return ret;
}

int _runtimeTerror_()
{
    int n;
    cin>>n;
    map<pll,vector<int>> mp;
    for(int i=1;i<=n;++i)
    {
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        ll x = (c+d)*b,y = d*a;
        ll g = __gcd(x,y);
        x /= g,y /= g;
        mp[{x,y}].push_back(i);
        x = c * b,y = d * (a + b);
        g = __gcd(x,y);
        x /= g,y /= g;
        mp[{x,y}].push_back(i);
    }
    int cur = 1;
    vector<vector<int>> tmp(n+10);
    for(auto j:mp)
    {
        for(auto &k:j.S)
        {
            tmp[k].push_back(cur);
        }
        // cout<<"\n";
        ++cur;
    }
    --cur;
    for(int i=1;i<=n;++i)
    {
        assert(sz(tmp[i]) == 2);
        v[tmp[i][0]].push_back({tmp[i][1],i});
        v[tmp[i][1]].push_back({tmp[i][0],i});
    }
    // for(int i=1;i<=cur;++i)
    // {
    //     for(auto j:v[i])
    //         cout<<j<<" ";
    //     cout<<"\n";
    // }
    for(int i=1;i<=cur;++i)
    {
        if(!vis[i])
        {
            // cout<<i<<"\n";
            dfs(i,0,0);
        }
    }
    cout<<sz(res)<<"\n";
    for(auto [j,k]:res)
        cout<<j<<" "<<k<<"\n";
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