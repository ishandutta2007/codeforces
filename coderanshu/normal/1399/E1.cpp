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
vector<pair<ll,pll>> v[N];
ll dp[N],c[N];
vector<pair<ll,pll>> f;

void dfs(int s,int p)
{
    dp[s]=0;
    if(sz(v[s])==1 && s!=1)
    {
        dp[s]=1;
        return ;
    }
    for(auto j:v[s])
    {
        if(j.F!=p)
        {
            dfs(j.F,s);
            dp[s]+=dp[j.F];
            f.pb({j.S.F,{dp[j.F],j.S.S}});
        }
    }
}
// weight size cost 
int _runtimeTerror_()
{
    int n;
    ll S;
    cin>>n>>S;
    for(int i=1;i<=n;++i)
        v[i].clear(),dp[i]=0,c[i]=0;
    f.clear();
    for(int i=0;i<n-1;++i)
    {
        ll x,y,w,c;
        c=1;
        cin>>x>>y>>w;
        v[x].pb({y,{w,c}});
        v[y].pb({x,{w,c}});
    }
    dfs(1,0);
    ll sum=0;
    assert(sz(f)==n-1);
    for(auto j:f)
        sum+=j.F*j.S.F;
    multiset<pair<pll,pll>> s;
    multiset<pair<pll,pll>> cost[2];
    for(auto j:f)
    {
        pair<pll,pll> p;
        p.F.F=-(j.F+1)/2*j.S.F;
        p.F.S=j.F/2;
        p.S.F=j.S.F;
        p.S.S=j.S.S;
        s.insert(p);
        cost[p.S.S-1].insert(p);
    }
    // faayda cost size color
    ll moves=0;
    auto fy=[&](pair<pll,pll> p,int color)
    {
        sum+=p.F.F;
        s.erase(s.find(p));
        cost[color-1].erase(cost[color-1].find(p));
        moves+=color;
        p.F.F=-(p.F.S+1)/2*p.S.F;
        p.F.S/=2;
        cost[color-1].insert(p);
        s.insert(p);
    };
    while(sum>S)
    {
        pair<pll,pll> p=*s.begin();
        if(p.S.S==1 || cost[0].empty())
        {
            fy(p,p.S.S);
            /*sum+=p.F.F;
            s.erase(s.find(p));
            cost[0].erase(cost[0].find(p));
            ++moves;
            p.F.F=-(p.F.S+1)/2*p.S.F;
            p.F.S/=2;
            cost[0].insert(p);
            s.insert(p);*/
            continue;
        }
        pair<pll,pll> t=*cost[0].begin();
        if(sum+t.F.F<=S)
        {
            ++moves;break;
        }
        if(cost[0].size()<2)
        {
            fy(p,p.S.S);
            continue;
        }
        cost[0].erase(cost[0].begin());
        pair<pll,pll> tt=*cost[0].begin();
        cost[0].insert(t);
        if(tt.F.F+t.F.F>p.F.F)
        {
            fy(t,1);
            fy(tt,1);
        }
        else
        {
            fy(p,2);
        }
        /*sum+=s.begin()->F;
        //cout<<*s.begin()<<"\n";
        s.erase(s.begin());
        p.F=-(p.S.F+1)/2*p.S.S;
        p.S.F/=2;
        s.insert(p);*/
    }
    cout<<moves<<"\n";
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