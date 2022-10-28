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

const int N=200005;

vector<int> v[N];
int dep[N],par[N];
vector<int> D;
vector<pair<pair<int,int>,int>> print;

int n;
ll ans=0;

void dfs(int s,int p)
{
    for(auto j:v[s])
    {
        if(j!=p)
        {
            dep[j]=dep[s]+1;
            dfs(j,s);
        }
    }
}
void dfs2(int s,int p)
{
    par[s]=p;
    for(auto j:v[s])
    {
        if(j!=p)
        {
            dep[j]=dep[s]+1;
            dfs2(j,s);
        }
    }
}
void dfs3(int s,int p,int val,int r,int h)
{
    for(auto j:v[s])
        if(j!=p)
            dfs3(j,s,val,r,h+1);
    ans+=h+val;
    print.pb({{s,r},s});
}
int _runtimeTerror_()
{
    cin>>n;
    for(int i=0;i<n-1;++i)
    {
        int x,y;
        cin>>x>>y;
        v[x].pb(y),v[y].pb(x);
    }
    dfs(1,0);
    int root=0,val=-1;
    for(int i=1;i<=n;++i)
    {
        if(dep[i]>val)
            root=i,val=dep[root];
        dep[i]=0;
    }
    dfs2(root,0);
    int root2=0;
    int d=0;
    for(int i=1;i<=n;++i)
    {
        if(dep[i]>d)
            root2=i,d=dep[root2];
        dep[i]=0;
    }
    while(root2!=root)
    {
        D.pb(root2);
        root2=par[root2];
    }
    D.pb(root);
    assert(sz(D)==d+1);
    root2=D[0];
    for(int i=0;i<d+1;++i)
    {
        int r=(i>=(d+1)/2)?root2:root;
        for(auto j:v[D[i]])
            if((i==d || (i<d+1 && j!=D[i+1])) && (i==0 || (i>0 && j!=D[i-1])))
                dfs3(j,D[i],max(i,d-i),r,1);
    }
    while(sz(D)>1)
    {
        ans+=d--;
        print.pb({{D[0],D.back()},D.back()});
        D.pop_back();
    }
    cout<<ans<<'\n';
    for(auto k:print)
        cout<<k.F.F<<" "<<k.F.S<<" "<<k.S<<'\n';
    return 0;
}

// greedy ka tukka bcc
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