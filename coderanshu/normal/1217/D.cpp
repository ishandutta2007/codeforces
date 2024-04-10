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

const int N=5005;
vector<int> v[N];

vector<int> t_sort;
int idx[N];
int vs[N];
bool var=false;

void dfs_sort(int u)
{
    vs[u]=2;
    for(auto j:v[u])
    {
        if(vs[j]==2)
            var=true;
        if(vs[j]==0)
        {
            dfs_sort(j);
        }
    }
    vs[u]=1;
    t_sort.push_back(u);
}

// Returns true if there is a topological sort else returns false
void top_sort(int n)
{
    t_sort.clear();
    for(int i=1;i<=n;++i)
        vs[i]=0;
    for(int i=1;i<=n;++i)
    {
        if(vs[i]==0)
        {
            dfs_sort(i);
        }
    }
    reverse(t_sort.begin(),t_sort.end());
    assert(t_sort.size()==n);
    for(int i=0;i<n;++i)
        idx[t_sort[i]]=i;
}

int _runtimeTerror_()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> edges;
    for(int i=0;i<m;++i)
    {
        int x,y;
        cin>>x>>y;
        edges.pb({x,y});
        v[x].pb(y);
    }
    top_sort(n);
    cout<<(!var?1:2)<<"\n";
    for(auto j:edges)
    {
        if(idx[j.F]>idx[j.S])
            cout<<2<<" ";
        else cout<<1<<" ";
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