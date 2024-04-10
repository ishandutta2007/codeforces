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
const int LOGN=20;
vector<ll> v[N],vec[N];
ll dep[N],par[N][LOGN],sub[N];
vector<int> roots;
void dfsl(ll s,ll p)
{
    sub[s]=1;
    for(auto j:v[s])
    {
        if(j!=p)
        {
            dep[j]=dep[s]+1,par[j][0]=s;
            dfsl(j,s);
            sub[s]+=sub[j];
        }
    }
}
void sparseMatrix(ll n)
{
    for(ll i=1;i<LOGN;++i)
        for(ll j=1;j<=n;++j)
                par[j][i]=par[par[j][i-1]][i-1];
}
int kthpar(int u,int k)
{
    for(int i=0;i<LOGN;++i)
        if(k&(1<<i))
            u=par[u][i];
    return u;
}
vector<pair<int,int>> query[N];
int ans[N];
int val[N];

void dfs(int s,int p,bool bors)
{
    int mx=-1,bc=-1;
    for(auto j:v[s])
        if(j!=p)
            if(sub[j]>mx)
                mx=sub[j],bc=j;
    for(auto j:v[s])
        if(j!=p && j!=bc)
            dfs(j,s,0);
    if(bc!=-1)
    {
        dfs(bc,s,1);
        swap(vec[s],vec[bc]);
    }
    val[dep[s]]++;
    vec[s].pb(s);
    for(auto j:v[s])
        if(j!=p && j!=bc)
            for(auto k:vec[j])
                vec[s].pb(k),val[dep[k]]++;
    for(auto k:query[s])
        ans[k.S]=val[k.F];
    if(!bors)
    {
        for(auto j:vec[s])
            val[dep[j]]--;
    }
}
int _runtimeTerror_()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        int p;
        cin>>p;
        if(p==0)
            roots.pb(i);
        else
            v[p].pb(i),v[i].pb(p);
    }
    for(auto j:roots)
        dfsl(j,-1);
    sparseMatrix(n);
    int m;
    cin>>m;
    for(int i=0;i<m;++i)
    {
        int u,p;
        cin>>u>>p;
        int x=kthpar(u,p);
        if(!x)
            ans[i]=1;
        else
            query[x].pb({dep[u],i});
    }
    for(auto j:roots)
       dfs(j,-1,0);
    for(int i=0;i<m;++i)
        cout<<ans[i]-1<<" ";
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
    cerr<<"\n"<<_time_;
    return 0;
}