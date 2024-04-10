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

const int N = 300005;

int r[N],p[N];

bool good[N];
vector<int> v[N];
int dep[N];

int parent(int i)
{
    return p[i] = (p[i]==i)?i:parent(p[i]);
}

void merge(int x,int y)
{
    x = parent(x),y = parent(y);
    assert(x!=y);
    if(r[x]>r[y])
        swap(x,y);
    if(r[x]==r[y])
        ++r[y];
    p[x] = y;
}

int _runtimeTerror_()
{
    int n,k,d;
    cin>>n>>k>>d;
    vector<pii> ed;
    for(int i=1;i<=k;++i)
    {
        int p;
        cin>>p;
        good[p] = true;
    }
    for(int i=0;i<n-1;++i)
    {
        int x,y;
        cin>>x>>y;
        v[x].pb(y),v[y].pb(x);
        ed.pb({x,y});
    }
    queue<int> q;
    for(int i=1;i<=n;++i)
    {
        p[i] = i,r[i] = 0;
        if(good[i])
        {
            dep[i] = 0;
            q.push(i);
        }
        else
            dep[i] = N;
    }
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(auto j:v[u])
        {
            if(dep[j]>dep[u] + 1)
            {
                dep[j] = dep[u] + 1;
                q.push(j);
                merge(j,u);
            }   
        }
    }
    int ans = 0;
    for(auto &j:ed)
    {
        if(parent(j.F) != parent(j.S))
            ++ans;
    }
    cout<<ans<<"\n";
    for(int i=0;i<n-1;++i)
    {
        if(parent(ed[i].F) != parent(ed[i].S))
            cout<<i+1<<" ";
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