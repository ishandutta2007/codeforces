// RED

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

const int N = 100005;

multiset<ll> in[N],out[N];

// cost day

struct node
{
    ll x,y,cost;
};
vector<node> v[1000001];

int _runtimeTerror_()
{
    ll ans = INF;
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<m;++i)
    {
        int d;
        node u;
        cin>>d;
        cin>>u.x>>u.y>>u.cost;
        v[d].pb(u);
    }
    ll inc = 0,dec = 0;
    for(int i=1;i<=n;++i)
    {
        in[i].insert(1e12);
        out[i].insert(1e12);
        inc += 1e12;
        dec += 1e12;
    }
    for(int i=k+1;i<=1000000;++i)
    {
        for(auto &j:v[i])
        {
            if(j.y==0)
            {
                
            }
            else
            {
                dec -= *out[j.y].begin();
                out[j.y].insert(j.cost);
                dec += *out[j.y].begin();
            }
        }
    }
    amin(ans,inc+dec);
    // cout<<ans<<"\n";
    for(int i=k+1;i<=1000000;++i)
    {
        for(auto &j:v[i-k])
        {
            if(j.y==0)
            {
                inc -= *in[j.x].begin();
                in[j.x].insert(j.cost);
                inc += *in[j.x].begin();
            }
            else
            {
                
            }
        }
        for(auto &j:v[i])
        {
            if(j.y==0)
            {
                
            }
            else
            {
                dec -= *out[j.y].begin();
                out[j.y].erase(out[j.y].find(j.cost));
                dec += *out[j.y].begin();
            }
        }
        // for(int j=1;j<=n;++j)
        // {
        //     cout<<"j "<<j<<"\n";
        //     for(auto &k:in[j])
        //         cout<<k<<" ";
        //     cout<<"\n";
        //     for(auto &k:out[j])
        //         cout<<k<<" ";
        //     cout<<"\n";
        // }
        amin(ans,inc+dec);
    }
    if(ans>=1e12)
        cout<<"-1\n";
    else
        cout<<ans<<"\n";
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