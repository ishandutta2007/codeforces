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

const int N = 300005;

int p[N];

set<int> v[N],g[N],gg[N],rgg[N],rg[N];

bool vis[N];
bool ans;

void dfs(int s,vector<int> &t)
{
    t.pb(s);
    vis[s] = true;
    for(auto j:g[s])
    {
        if(vis[j])
        {
            ans = false;
            return ;
        }
        dfs(j,t);
    }
}

int _runtimeTerror_()
{
    int n,k;
    cin>>n>>k;
    ans = true;
    for(int i=1;i<=n;++i)
    {
        cin>>p[i];
        if(p[i])
            gg[i].insert(p[i]),rgg[p[i]].insert(i);
    }
    for(int i=1;i<=k;++i)
    {
        int x,y;
        cin>>x>>y;
        // v[x].insert(y);
        // v[y].insert(x);
        g[x].insert(y);
        rg[y].insert(x);
    }
    vector<vector<int>> seg;
    vector<int> pre;
    vector<int> num(n+1);
    vector<bool> vis2(n+1);
    for(int i=1;i<=n;++i)
    {
        if(rg[i].empty())
        {
            vector<int> t;
            dfs(i,t);
            if(!ans)
            {
                cout<<"0\n";return 0;
            }
            for(auto j:t)
                num[j] = seg.size();
            seg.pb(t);
            pre.pb(sz(t));
            for(auto j:t)
            {
                vis2[j] = true;
                if(gg[j].empty() || vis2[*gg[j].begin()])
                    --pre.back();
            }
            for(auto j:t)
                vis2[j] = false;
        }
    }
    // for(auto j:seg)
    // {
    //     for(auto k:j)
    //         cout<<k<<" ";
    //     cout<<"\n";
    // }
    vector<int> ans;
    for(int i=1;i<=n;++i)
    {
        if(!vis[i])
        {
            cout<<"0\n";return 0;
        }
    }
    set<pii> s;
    for(int i=0;i<sz(seg);++i)
    {
        // cout<<pre[i]<<" "<<i<<"\n";
        s.insert({pre[i],i});
    }
    while(!s.empty())
    {
        auto [x,y] = *s.begin();
        s.erase(s.begin());
        // cout<<x<<" "<<y<<"\n";
        if(x!=0)
        {
            assert(sz(ans)<n);
            cout<<"0\n";return 0;
        }
        for(auto &j:seg[y])
            ans.pb(j);
        for(auto &j:seg[y])
        {
            for(auto &k:rgg[j])
            {
                if(s.count({pre[num[k]],num[k]}))
                {
                    s.erase({pre[num[k]],num[k]});
                    --pre[num[k]];
                    s.insert({pre[num[k]],num[k]});
                }
            }
        }
    }
    assert(sz(ans) == n);
    for(auto j:ans)
        cout<<j<<" ";
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