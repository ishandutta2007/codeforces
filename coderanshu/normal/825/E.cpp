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
const int N=100005;
vector<int> v[N],vv[N];
int degree[N],ans[N];
int _runtimeTerror_()
{
    ll n,m;
    cin>>n>>m;
    for(int i=0;i<m;++i)
    {
        int x,y;
        cin>>x>>y;
        v[x].pb(y);
        vv[y].pb(x);
    }
    int val=n;
    set<pair<int,int>> s;
    for(int i=1;i<=n;++i)
        s.insert({sz(v[i]),-i}),degree[i]=sz(v[i]);
    while(!s.empty())
    {
        pair<int,int> p=*s.begin();
        //cout<<p<<endl;
        s.erase(s.begin());
        ans[-p.S]=val--;
        for(auto k:vv[-p.S])
        {
            s.erase({degree[k],-k});
            --degree[k];
            s.insert({degree[k],-k});
        }
    }
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