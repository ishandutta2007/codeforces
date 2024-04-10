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
vector<int> v[1002];
int root,totdis,dep[1002],par[1002];
vector<int> deps[1002];
int mx;

void dfs(int s,int p)
{
    amax(mx,dep[s]);
    deps[dep[s]].pb(s);
    for(auto j:v[s])
    {
        if(j!=p)
        {
            par[j]=s;
            dep[j]=dep[s]+1;
            dfs(j,s);
        }
    }

}
int _runtimeTerror_()
{
    int n;
    cin>>n;
    mx=-1;
    for(int i=0;i<=n;++i)
    {
        v[i].clear();
        deps[i].clear();
        dep[i]=0;
    }
    for(int i=0;i<n-1;++i)
    {
        int x,y;
        cin>>x>>y;
        v[x].pb(y),v[y].pb(x);
    }
    cout<<"? "<<n<<" ";
    for(int i=1;i<=n;++i)
    {
        cout<<i;
        if(i!=n)
            cout<<" ";
    }
    cout<<endl;
    cin>>root>>totdis;
    dfs(root,-1);
    int lo=totdis/2,hi=min(totdis,mx);
    pll ff;
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;
        cout<<"? ";
        cout<<deps[mid].size()<<" ";
        for(auto j:deps[mid])
            cout<<j<<" ";
        cout<<endl;
        pll ans;
        cin>>ans.F>>ans.S;
        if(ans.S==totdis)
            lo=mid+1,ff=ans;
        else hi=mid-1;
    }
    int node1=ff.F,node2=-1;
    int cnt=0;
    int rd=totdis-dep[ff.F];
    if(rd==0)
        node2=root;
    if(node2==-1)
    {
    int x=node1;
    while(dep[x]!=rd)
        x=par[x];
    cout<<"? ";
    cout<<sz(deps[rd])-1<<" ";
    for(auto k:deps[rd])
        if(k!=x)
            cout<<k<<" ";
    cout<<endl;
    int tt;
    cin>>node2>>tt;
    }
    cout<<"! "<<node1<<" "<<node2<<endl;
    string s;
    cin>>s;
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