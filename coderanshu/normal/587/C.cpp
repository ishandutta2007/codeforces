#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
#define ll int
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
vector<int> v[N],cnt[N];

const int LOGN=20;
ll dep[N],par[N][LOGN];
vector<int> pre[N][LOGN];

void merge(const vector<int> &a,const vector<int> &b,vector<int> &c)
{
    int cur1=0,cur2=0;
    while(cur1<10 && cur2<10 && sz(c)<10)
    {
        if(a[cur1]<b[cur2])
            c.pb(a[cur1++]);
        else 
            c.pb(b[cur2++]);
    }
    while(cur1<10 && sz(c)<10)
        c.pb(a[cur1++]);
    while(cur2<10 && sz(c)<10)
        c.pb(b[cur2++]);
}
void merge2(const vector<int> &a,vector<int> &b)
{
    vector<int> c;
    int cur1=0,cur2=0;
    while(cur1<10 && cur2<10 && sz(c)<10)
    {
        if(a[cur1]<b[cur2])
            c.pb(a[cur1++]);
        else 
            c.pb(b[cur2++]);
    }
    while(cur1<10 && sz(c)<10)
        c.pb(a[cur1++]);
    while(cur2<10 && sz(c)<10)
        c.pb(b[cur2++]);
    b=c;
}
void dfs(ll s,ll p)
{
    int cc=0;
    while(cc<10)
        pre[s][0].pb(cnt[p][cc++]);
    for(auto j:v[s])
    {
        if(j!=p)
        {
            dep[j]=dep[s]+1,par[j][0]=s;
            dfs(j,s);
        }
    }
}
void sparseMatrix(ll n)
{
    for(ll i=1;i<LOGN;++i)
        for(ll j=1;j<=n;++j)
        {
            merge(pre[j][i-1],pre[par[j][i-1]][i-1],pre[j][i]);
            par[j][i]=par[par[j][i-1]][i-1];
        }
}
vector<int> lca(ll u,ll v)
{
    vector<int> ans(10,1e6);
    if(dep[u]>dep[v])swap(u,v);
    ll df=dep[v]-dep[u];
    merge2(cnt[v],ans);
    for(ll i=0;i<LOGN;++i)
    {
        if(df&(1<<i))
        {
            merge2(pre[v][i],ans);
            v=par[v][i];
       }
    }
    if(u==v)return ans;
    merge2(cnt[u],ans);
    for (ll i=LOGN-1; i>=0; i--) 
    {
        if(par[u][i]!=par[v][i]) 
        { 
            merge2(pre[v][i],ans);
            merge2(pre[u][i],ans);
            u=par[u][i]; 
            v=par[v][i];
        } 
    }
    merge2(cnt[par[u][0]],ans);
    return ans; 
}

int _runtimeTerror_()
{
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=0;i<n-1;++i)
    {
        int x,y;
        cin>>x>>y;
        v[x].pb(y),v[y].pb(x);
    }
    for(int i=0;i<m;++i)
    {
        int x;
        cin>>x;
        cnt[x].pb(i+1);
    }
    for(int i=0;i<=n;++i)
    {
        while(sz(cnt[i])<10)
            cnt[i].pb(1e6);
        sort(all(cnt[i]));
    }
    for(int i=0;i<LOGN;++i)
    {
        for(int j=0;j<10;++j)
            pre[0][i].pb(1e6);
    }
    dfs(1,0);
    sparseMatrix(n);
    while(q--)
    {
        int uu,vv,aa;
        cin>>uu>>vv>>aa;
        vector<int> val=lca(uu,vv);
        while(val.back()==1e6)
            val.pop_back();
        cout<<min(aa,sz(val))<<" ";
        for(int i=0;i<min(aa,sz(val));++i)
            cout<<val[i]<<" ";
        cout<<'\n';
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