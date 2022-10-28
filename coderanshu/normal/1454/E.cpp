#include<bits/stdc++.h>
using namespace std ;

#define ll              long long 
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define sz(a)           (ll)a.size()
#define F               first
#define S               second
#define INF             2000000000000000000
#define popcount(x)     __builtin_popcountll(x)
#define pll             pair<ll,ll> 
#define pii             pair<int,int>
#define ld              long double

const int M = 1000000007;
const int MM = 998244353;
const long double PI = acos(-1);

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}

const int N = 200005;

vector<int> v[N];

int sub[N],par[N];

bool bad[N];
bool vis[N];

vector<int> cy;
vector<int> st;

void dfs(int s,int p)
{
    st.pb(s);
    vis[s] = true;
    for(auto j:v[s])
    {
        if(!vis[j])
        {
            dfs(j,s);
        }
        else
        {
            if(j!=p && cy.empty())
            {
                int cur = sz(st)-1;
                while(st[cur]!=j)
                {
                    cy.pb(st[cur]);
                    bad[st[cur]] = true;
                    --cur;
                }
                bad[j] = true;
                cy.pb(j);
            }
        }
    }
    st.pop_back();
}

void go_(int s,int p,ll &cnt)
{
    ++cnt;
    for(auto j:v[s])
    {
        if(j!=p && !bad[j])
            go_(j,s,cnt);
    }
}

int _runtimeTerror_()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        par[i] = 0;
        sub[i] = 0;
        v[i].clear();
        vis[i] = false;
        bad[i] = false;
    }   
    st.clear();
    cy.clear();
    for(int i=1;i<=n;++i)
    {
        int x,y;
        cin>>x>>y;
        v[x].pb(y),v[y].pb(x);
    }
    dfs(1,0);
    ll ans = n*1LL*(n-1);
    for(auto j:cy)
    {
        ll cnt = 0;
        go_(j,0,cnt);
        ans -= cnt*(cnt-1)/2;
    }
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
    cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}