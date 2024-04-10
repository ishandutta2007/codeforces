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
ll n;
const int N=500005;
ll mask[1<<22],ans[N],dep[N],sub[N];
vector<pll> v[N];
vector<ll> vec[N];
void pre(int s=1,int p=-1)
{
    sub[s]=1;
    for(auto j:v[s])
        if(j.F!=p)
        {
            dep[j.F]=dep[s]+1;
            pre(j.F,s);
            sub[s]+=sub[j.F];
        }
}
void clear(int s,int p,int msk)
{
    mask[msk]=-INF;
    for(auto j:v[s])
        if(j.F!=p)
            clear(j.F,s,msk^(1<<j.S));
}
vector<pair<int,int>> push;
void add(int s,int p,int msk,int addvec)
{
    vec[addvec].pb(s);
    push.pb({msk,dep[s]});
    amax(ans[addvec],mask[msk]+dep[s]-2*dep[addvec]);
    for(int i=0;i<22;++i)
        amax(ans[addvec],mask[msk^(1<<i)]+dep[s]-2*dep[addvec]);
    for(auto j:v[s])
        if(j.F!=p)
            add(j.F,s,msk^(1<<j.S),addvec);
}
void dfs(int s,int p,int bors,int msk)
{
    int mx=-1,bc=-1,val=0;
    ans[s]=0;
    //cout<<"s msk"<<s<<" "<<msk<<endl;
    for(auto j:v[s])
        if(j.F!=p)
            if(sub[j.F]>mx)
                mx=sub[j.F],bc=j.F,val=j.S;
    for(auto j:v[s])
    {
        if(j.F!=p && j.F!=bc)
        {
            dfs(j.F,s,0,msk^(1<<j.S));
        }
    }
    if(bc!=-1)
    {
        dfs(bc,s,1,msk^(1<<val));
        swap(vec[s],vec[bc]);
    }
    for(auto j:v[s])
        if(j.F!=p)
            amax(ans[s],ans[j.F]);
    vec[s].pb(s);
    amax(mask[msk],dep[s]);
    amax(ans[s],mask[msk]-dep[s]);
    for(int i=0;i<22;++i)
        amax(ans[s],mask[msk^(1<<i)]-dep[s]);
    //cout<<mask[msk]<<endl;
    for(auto j:v[s])
        if(j.F!=p && j.F!=bc)
        {
            add(j.F,s,msk^(1<<j.S),s);
            for(auto k:push)
                amax(mask[k.F],k.S);
            push.clear();
        }
    if(!bors)
    {
        clear(s,p,msk);
    }
}
int _runtimeTerror_()
{
    cin>>n;
    for(int i=2;i<=n;++i)
    {
        ll x;char c;
        cin>>x>>c;
        v[i].pb({x,c-'a'}),v[x].pb({i,c-'a'});
    }
    pre();
    for(int i=0;i<(1<<22);++i)
        mask[i]=-INF;
    //for(int i=1;i<=n;++i)
    //    cout<<sub[i]<<" "<<dep[i]<<endl;
    dfs(1,-1,0,0);
    for(int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
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