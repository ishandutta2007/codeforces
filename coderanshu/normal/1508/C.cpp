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

const int N = 200005;
int n,m;
ll rem = 0;
vector<pll> v[N];
int p[N],sz[N];

set<int> vis;

int num[N];
int cur = 1;
vector<vector<int>> cmp;
vector<ll> edges;
bool cycle = false;
void dfs(int s)
{
    queue<int> q;
    q.push(s);
    cmp.push_back({});
    edges.push_back(0);
    vis.erase(s);
    while(!q.empty())
    {
        int s = q.front();
        q.pop();
        edges.back() += n - sz(v[s]) - 1;
        cmp.back().push_back(s);
        vector<int> get;
        for(auto [j,k]:v[s])
        {
            if(vis.count(j))
            {
                vis.erase(j);
                get.push_back(j);
            }
        }
        while(!vis.empty())
        {
            int u = *vis.begin();
            q.push(u);
            vis.erase(u);
        }
        for(auto &j:get)
            vis.insert(j);
    }
    ll si = sz(cmp.back());
    if(edges.back() != 2*(si-1))
        cycle = true;
    for(auto &j:cmp.back())
        num[j] = cur;
    ++cur;
}

int parent(int i)
{
    return p[i] == i?i:parent(p[i]);
}
void merge(int x,int y)
{
    x = parent(x),y = parent(y);
    if(x == y)
        return ;
    if(sz[x] > sz[y])
        swap(x,y);
    p[x] = y;
    sz[y] += sz[x];
}

vector<pll> g[N];
ll above[N];
int par[N];
int in[N],out[N],pp = 1;
ll minx[N];

void dfs2(int s,int p)
{
    in[s] = pp++;
    par[s] = p;
    for(auto &[j,k]:g[s])
    {
        if(j == p)
            continue;
        above[j] = k;
        dfs2(j,s);
    }
    out[s] = pp-1;
}

int _runtimeTerror_()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        sz[i] = 1,p[i] = i,minx[i] = INF;
    vector<pair<ll,pll>> ed;
    for(int i=0;i<m;++i)
    {
        ll x,y,w;
        cin>>x>>y>>w;
        v[x].push_back({y,w});
        v[y].push_back({x,w});
        ed.push_back({w,{x,y}});
        rem ^= w;
    }   
    sort(all(ed));
    for(int i=1;i<=n;++i)
        vis.insert(i);
    for(int i=1;i<=n;++i)
    {
        if(vis.count(i))
            dfs(i);
    }
    // for(auto &j:cmp)
    // {
    //     for(auto &k:j)
    //         cout<<k<<" ";
    //     cout<<"\n";
    // }
    ll ans = 0;
    if(cycle)
    {
        for(auto [j,k]:ed)
        {
            k.F = num[k.F],k.S = num[k.S];
            if(parent(k.F) != parent(k.S))
                ans += j,merge(k.F,k.S);
        }
        cout<<ans<<"\n";
        return 0;
    }
    vector<vector<bool>> have(n+1,vector<bool>(n+1,false));
    for(auto [j,k]:ed)
        have[k.F][k.S] = 1,have[k.S][k.F] = 1;
    assert(n <= 700);
    vector<pair<ll,pll>> tmp;
    for(int i=1;i<=n;++i)
    {
        for(int j=i+1;j<=n;++j)
        {
            if(!have[i][j])
                ed.push_back({0,{i,j}});
        }
    }   
    sort(all(ed));
    for(auto [j,k]:ed)
    {
        if(parent(k.F) != parent(k.S))
        {
            ans += j,merge(k.F,k.S);
            g[k.F].push_back({k.S,j});
            g[k.S].push_back({k.F,j});
        }
        else
        {
            tmp.push_back({j,k});
        }
    }
    // cout<<"ans : "<<ans<<"\n";
    dfs2(1,0);
    // for(int i=1;i<=n;++i)
        // cout<<in[i]<<"\n";
    for(auto &[j,k]:tmp)
    {
        auto [x,y] = k;
        int u = x;
        // cout<<x<<" "<<y<<"\n";
        while(!(in[u] <= in[y] && in[y] <= out[u]))
        {
            if(u == 0)
                break;
            // cout<<u<<"\n";
            amin(minx[u],j);
            u = par[u];
        }
        // swap(x,y);
        // u = x;
        while(!(in[u] <= in[y] && in[y] <= out[u]))
        {
            if(u == 0)
                break;
            amin(minx[u],j);
            u = par[u];
        }
    }
    ll val = INF;
    for(int i=1;i<=n;++i)
    {
        // cout<<minx[i]<<" "<<above[i]<<"\n";
        if(i != 1 && above[i] == 0)
        {
            if(minx[i] < rem)
                amin(val,ans+minx[i]);
            else
                amin(val,ans+rem);
            // amin(val,ans+minx[i]-rem);
        }
    }
    cout<<val<<"\n";return 0;
    // // for(auto &j:tmp)
    //     // cout<<j<<"\n";
    // ans = INF;
    // for(int i=0;i<sz(tmp);++i)
    // {
    //     for(int j=1;j<=n;++j)
    //         p[j] = j,sz[j] = 1;
    //     vector<pair<ll,pll>> A = ed;
    //     for(int j=0;j<sz(tmp);++j)
    //     {
    //         if(i == j)
    //             A.push_back({rem,{tmp[j].F,tmp[j].S}});
    //         else
    //             A.push_back({0,{tmp[j]}});
    //     }
    //     sort(all(A));
    //     ll val = 0;
    //     for(auto [j,k]:A)
    //     {
    //         // cout<<j<<" "<<k<<"\n";
    //         if(parent(k.F) != parent(k.S))
    //             val += j,merge(k.F,k.S);
    //     }
    //     amin(ans,val);
    // }
    cout<<ans<<"\n";
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