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

const int N=200005;
ll val[N],n;
set<ll> v[N];
ll ctree[N],sub[N];
ll cntoftr;
ll ans=0;

void dfs1(ll s,ll p)
{
    ++cntoftr;
    sub[s]=1;
    for(auto j:v[s])
        if(j!=p)
        {
            dfs1(j,s);
            sub[s]+=sub[j];
        }
}
ll dfs2(ll s,ll p)
{
    for(auto j:v[s])
        if(j!=p && sub[j]>cntoftr/2)
            return dfs2(j,s);
    return s;
}
ll gsum,sum,centre,cnt,tmpcnt;
void dfs3(int s,int p,ll valu,ll dep,bool fo)
{
    ++tmpcnt;
    if(dep&1)
        valu+=val[s];
    else valu-=val[s];
    valu%=M;valu+=M;valu%=M;
    ll x=valu+val[centre];
    if(dep%2==0)x*=-1;
    x%=M;x+=M;x%=M;
    sum+=valu;sum%=M;
    if(fo)
    {
        if(dep&1)
            ans+=2*x;
    }
    ans%=M;
    ans+=M;ans%=M;
    if(dep&1)
        ans+=(cnt*x%M+gsum)%M;
    else 
        ans+=(cnt*x%M-gsum)%M;
    ans%=M;
    ans+=M;ans%=M;
    for(auto j:v[s])
        if(j!=p)
            dfs3(j,s,valu,dep+1,fo);
}
void decompose(ll s,ll p)
{
    cntoftr=0;
    dfs1(s,s);
    ll centroid=dfs2(s,s);
    if(p==-1)p=centroid;
    ctree[centroid]=p;
    centre=centroid;
    ans+=val[centroid];
    ans%=M;ans+=M;ans%=M;
    for(auto j:v[centroid])
    {
        v[j].erase(centroid);
        dfs3(j,-1,0,2,true);
        cnt+=tmpcnt;
        gsum+=sum;
        gsum%=M;
        cnt%=M;
        sum=0;
        tmpcnt=0;
    }
    gsum=0;
    cnt=0;
    for(auto j=v[centroid].rbegin();j!=v[centroid].rend();++j)
    {
        dfs3(*j,-1,0,2,false);
        cnt+=tmpcnt;
        gsum+=sum;
        gsum%=M;cnt%=M;
        sum=0;
        tmpcnt=0;
    }
    gsum=0;
    cnt=0;
    for(auto j:v[centroid])
    {
        decompose(j,centroid);
    }
    v[centroid].clear();
}

int _runtimeTerror_()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>val[i];
    for(int i=0;i<n-1;++i)
    {
        int x,y;
        cin>>x>>y;
        v[x].insert(y),v[y].insert(x);
    }
    decompose(1,-1);
    cout<<ans<<endl;
    return 0;
}
// double sided centroid decomposition

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