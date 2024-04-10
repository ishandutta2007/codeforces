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

vector<pii> v[N];
ll w[N];
ll dis[N][2];

set<int> path;

int l[N],r[N];

bitset<N> vis;

void dfs_l(int u,int p)
{
    vis[u] = true;
    l[u] = p;
    for(auto &j:v[u])
    {
        if(path.count(j.S))
            continue;
        if(!vis[j.F] && dis[j.F][0] == dis[u][0] + w[j.S])
            dfs_l(j.F,p);
    }
}

void dfs_r(int u,int p)
{
    vis[u] = true;
    r[u] = p;
    for(auto &j:v[u])
    {
        if(path.count(j.S))
            continue;
        if(!vis[j.F] && dis[j.F][1] == dis[u][1] + w[j.S])
            dfs_r(j.F,p);
    }
}

int _runtimeTerror_()
{
    int n,m,Q;
    cin>>n>>m>>Q;
    for(int i=1;i<=n;++i)
        dis[i][0] = dis[i][1] = INF;
    vector<pii> ed(m+1);
    for(int i=1;i<=m;++i)
    {
        int x,y;
        cin>>x>>y>>w[i];
        v[x].push_back({y,i});
        v[y].push_back({x,i});
        ed[i] = {x,y};
    }
    auto dij = [&](int so,int id)
    {
        dis[so][id] = 0;
        set<pll> s;
        s.insert({0,so});
        while(!s.empty())
        {
            auto [x,y] = *s.begin();
            s.erase(s.begin());
            for(auto &[j,k]:v[y])
            {
                if(dis[j][id] > x + w[k])
                {
                    s.erase({dis[j][id],j});
                    dis[j][id] = x + w[k];
                    s.insert({dis[j][id],j});
                }
            }
        }
    };
    dij(1,0);
    dij(n,1);
    vector<pii> nodes;
    int node = n;
    while(node != 1)
    {
        for(auto &j:v[node])
        {
            if(dis[j.F][0] + w[j.S] == dis[node][0])
            {
                nodes.push_back({node,j.S});
                path.insert(j.S);
                node = j.F;
                break;
            }
        }
    }
    reverse(all(nodes));
    int nn = sz(nodes);
    map<int,int> mp;
    dfs_l(1,0);
    for(int i=0;i<nn;++i)
    {
        mp[nodes[i].S] = i;
        dfs_l(nodes[i].F,i+1);
    }
    vis.reset();
    for(int i=nn-1;i>=0;--i)
    {
        dfs_r(nodes[i].F,i);
    }
    dfs_r(1,-1);
    vector<vector<ll>> get(nn+1),del = get;
    auto upd = [&](int l,int r,ll val)
    {
        if(l > r)
        {
            return ;
        }
        get[l].push_back(val);
        del[r+1].push_back(val);
    };
    multiset<ll> st;
    for(int i=1;i<=m;++i)
    {
        if(path.count(i))
            continue;
        upd(l[ed[i].F],r[ed[i].S],dis[ed[i].F][0] + dis[ed[i].S][1]+w[i]);
        upd(l[ed[i].S],r[ed[i].F],dis[ed[i].S][0] + dis[ed[i].F][1]+w[i]);
    }
    vector<ll> ans(nn+1,INF);
    for(int i=0;i<nn;++i)
    {
        for(auto &j:get[i])
            st.insert(j);
        for(auto &j:del[i])
            st.erase(st.find(j));
        if(!st.empty())
            ans[i] = *st.begin();
    }
    for(int i=1;i<=Q;++i)
    {
        ll id,x = INF;
        cin>>id>>x;
        ll val = INF;
        if(!mp.count(id))
        {
            val = min({dis[n][0],dis[ed[id].F][0] + dis[ed[id].S][1] + x,dis[ed[id].F][1] + dis[ed[id].S][0] + x});
        }
        else
        {
            val = min({ans[mp[id]],dis[ed[id].F][0] + dis[ed[id].S][1] + x,dis[ed[id].F][1] + dis[ed[id].S][0] + x});
        }
        if(val == INF)
            val = -1;
        cout<<val;
        cout<<"\n";
    }
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