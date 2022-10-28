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

vector<int> v[N],gg[N];
set<int> g[N],vv[N];
int n,m;
bool vis[N],vis2[N];

bool dfs(int s)
{
    vis2[s]=true;
    vis[s]=true;
    for(auto j:gg[s])
    {
        if(!vis[j] && dfs(j))
        {
            return true;
        }
        else if(vis2[j])
            return true;
    }
    vis2[s]=false;
    return false;
}

int _runtimeTerror_()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        v[i].clear(),g[i].clear(),gg[i].clear(),vv[i].clear(),vis[i]=false,vis2[i]=false;
    int rem=0;
    for(int i=0;i<m;++i)
    {
        int t,x,y;
        cin>>t>>x>>y;
        if(t==0)
            g[x].insert(y),g[y].insert(x),++rem;
        else
            v[x].pb(y),vv[x].insert(y),gg[y].pb(x);
    }
    queue<int> up;
    for(int i=1;i<=n;++i)
    {
        if(v[i].empty())
        {
            up.push(i);
            if(dfs(i))
            {
                cout<<"NO\n";return 0;
            }
        }
    }
    for(int i=1;i<=n;++i)
    {
        if(!vis[i])
        {
            cout<<"NO\n";return 0;
        }
        vis[i]=false;
    }
    for(int i=1;i<=n;++i)
    {
        if(v[i].empty())
            vis[i]=true;
    }
    while(!up.empty())
    {
        int x=up.front();
        up.pop();
        for(auto j:g[x])
        {
            v[j].pb(x);
            gg[x].pb(j);
            --rem;
            g[j].erase(x);
        }   
        g[x].clear();
        for(auto j:gg[x])
        {
            vv[j].erase(x);
            if(!vis[j])
            {
                if(vv[j].empty())
                {
                    vis[j]=true;
                    up.push(j);
                }
            }
        }
    }
    if(rem)
    {
        cout<<"NO\n";return 0;
    }
    cout<<"YES\n";
    int cnt=0;
    for(int i=1;i<=n;++i)
    {
        for(auto j:v[i])
        {
            ++cnt;
            cout<<i<<" "<<j<<"\n";
        }
    }
    assert(cnt==m);
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
    cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}