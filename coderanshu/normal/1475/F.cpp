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

const int N = 10005;

vector<int> v[N];

const int NN = 1005;
char a[NN][NN],b[NN][NN];
int p[N],sz[N];

int parent(int i)
{
    return p[i] = (p[i] == i)?i:parent(p[i]);
}

int _runtimeTerror_()
{
    int n;
    cin>>n;
    for(int i=1;i<=2*n;++i)
    {
        v[i].clear();
        p[i] = i,sz[i] = 1;
    }
    auto merge = [&](int x,int y)
    {
        x = parent(x),y = parent(y);
        if(x == y)
            return ;
        if(sz[x]>sz[y])
            swap(x,y);
        sz[y] += sz[x];
        p[x] = y;
    };
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            cin>>a[i][j];
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            cin>>b[i][j];
            if(a[i][j] == b[i][j])
                merge(i,j+n);
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(a[i][j]!=b[i][j])
                v[parent(i)].pb(parent(j+n)),v[parent(j+n)].pb(parent(i));
        }
    }
    vector<bool> vis(2*n+2,0);
    vector<int> dep(2*n+2,-1);
    queue<int> q;
    for(int i=1;i<=2*n;++i)
    {
        if(vis[i])
            continue;
        q.push(i);
        dep[i] = 0;
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(auto &j:v[u])
            {
                if(!vis[j])
                {
                    dep[j] = dep[u]^1;
                    q.push(j);
                    vis[j] = true;
                }
                else if(vis[j] && dep[j] == dep[u])
                {
                    cout<<"NO\n";return 0;
                }
            }
        }
    }
    cout<<"YES\n";
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