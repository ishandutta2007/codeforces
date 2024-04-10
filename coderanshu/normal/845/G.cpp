#include<bits/stdc++.h>
using namespace std ;

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

const int M=1000000007;
const int MM=998244353;
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
vector<pair<int,int>> g[N];

struct DSU {
    vector<int> p,r;
    int n;
    int components;
    DSU(int _):n(_),components(_) {
        p.resize(n+1);
        r.resize(n+1);
        for(int i=0;i<=_;++i)
            p[i]=i,r[i]=0;
    }
    int parent(int i) {
        return p[i]=(p[i]==i)?i:parent(p[i]);
    }
    void merge(int x,int y) {
        x=parent(x);
        y=parent(y);
        if(x==y)
            return ;
        if(r[x]>r[y])
            p[y]=x;
        else
            p[x]=y;
        if(r[x]==r[y])
            ++r[y];
        --components;
    }
};

#define pii pair<int,int>

int a[N];

void dfs(int s,int p,int val)
{   
    a[s]=val;
    for(auto j:g[s])
        if(j.F!=p)
            dfs(j.F,s,val^j.S);
}

int basis[30];

void insert(int mask)
{
    for(int j=29;j>=0;--j)
    {
        if((mask&(1<<j))==0)
            continue;
        if(!basis[j])
            basis[j]=mask;
        mask^=basis[j];
    }
}
int _runtimeTerror_()
{
    int n,m;
    cin>>n>>m;
    DSU dsu(n);
    vector<pair<pair<int,int>,int>> edge(m);
    for(int i=0;i<m;++i)
    {
        cin>>edge[i].F.F>>edge[i].F.S>>edge[i].S;
    }
    vector<bool> tn(m,false);
    int i=0;
    for(auto j:edge)
    {   
        if(dsu.parent(j.F.F)!=dsu.parent(j.F.S))
        {
            dsu.merge(j.F.F,j.F.S);
            g[j.F.F].pb({j.F.S,j.S});
            g[j.F.S].pb({j.F.F,j.S});
            tn[i]=true;
        }
        ++i;
    }
    dfs(1,-1,0);
    for(int i=0;i<m;++i)
    {
        if(!tn[i])
        {
            insert(a[edge[i].F.F]^a[edge[i].F.S]^edge[i].S);
        }
    }
    int ans=a[1]^a[n];
    for(int j=29;j>=0;--j)
    {
        if((ans&(1<<j))==0)
            continue;
        ans^=basis[j];
    }
    cout<<ans;
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