#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
#define ll long long 
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define sz(a) (ll)a.size()
#define F first
#define S second
#define INF 2000000000000000000
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
#define popcount(x) __builtin_popcountll(x)
#define pll pair<ll,ll> 
#define ld long double

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
const int N=100005;
vector<pll> adj[9*N];

int earth,n,cur=1,total;
ll dis[9*N];

struct SEGTREE
{
    int tree[4*N];
    bool rev;
    SEGTREE(bool x):rev(x){}
    void buildTree(ll v,ll st,ll en)
    {
        if(st==en)
        {
            tree[v]=st;   
            return ;
        }
        ll mid=(st+en)>>1;
        buildTree(v<<1,st,mid);
        buildTree(v<<1 | 1,mid+1,en);
        tree[v]=cur++;
        if(!rev)
            adj[tree[v]].pb({tree[v<<1],0}),adj[tree[v]].pb({tree[v<<1 | 1],0});
        else
            adj[tree[v<<1 | 1]].pb({tree[v],0}),adj[tree[v<<1]].pb({tree[v],0});
    }
    void rupdate(ll v,ll st,ll en,ll l,ll r,ll val,ll w)
    {
        if(en<l || st>r)return ;
        if(st>=l && en<=r)
        {
            if(!rev)
                adj[val].pb({tree[v],w});
            else
                adj[tree[v]].pb({val,w});
            return ;
        }
        ll mid=(st+en)>>1;
        rupdate(v<<1,st,mid,l,r,val,w);
        rupdate(v<<1 | 1,mid+1,en,l,r,val,w);
    }
};

void djikstra()
{
    dis[earth]=0;
    set<pll> s;
    s.insert({0,earth});
    while(!s.empty())
    {
        pll p=*s.begin();s.erase(s.begin());
        for(auto j:adj[p.S])
        {
            if(p.F+j.S<dis[j.F])
            {
                s.erase({j.F,dis[j.F]});
                dis[j.F]=p.F+j.S;
                s.insert({dis[j.F],j.F});
            }
        }
    }
}
int _runtimeTerror_()
{
    int q;
    cin>>n>>q>>earth;
    cur=n+1;
    SEGTREE seg1(0),seg2(1);
    seg1.buildTree(1,1,n);
    seg2.buildTree(1,1,n);
    total=cur-1;
    for(int i=1;i<=9*N-10;++i)
        dis[i]=INF;
    for(int i=0;i<q;++i)
    {
        int tt,v,l,r;
        ll w;
        cin>>tt;
        if(tt==1)
        {   
            cin>>v>>l>>w;
            adj[v].pb({l,w});
        }
        else
        {
            cin>>v>>l>>r>>w;
            if(tt==2)
                seg1.rupdate(1,1,n,l,r,v,w);
            else
                seg2.rupdate(1,1,n,l,r,v,w);
        }
    }
    djikstra();
    for(int i=1;i<=n;++i)
        cout<<(dis[i]==INF?-1:dis[i])<<" ";
    return 0;
}
// epic question
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
    cerr<<"\n"<<_time_;
    return 0;
}