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

const int N = 100;
int n,m;

char a[N][N];
bool vis[N][N];
char c;

bool dfs(int i,int j,int pi,int pj)
{
    if(a[i][j]!=c)
        return false;
    if(vis[i][j])
        return true;
    vis[i][j] = true;
    int ans = false;
    if(i>1 && !(i-1==pi && j==pj))
        ans |= dfs(i-1,j,i,j);
    if(i<n && !(i+1==pi && j==pj))
        ans |= dfs(i+1,j,i,j);
    if(j>1 && !(i==pi && j-1==pj))
        ans |= dfs(i,j-1,i,j);
    if(j<m && !(i==pi && j+1==pj))
        ans |= dfs(i,j+1,i,j);
    return ans;
}

int _runtimeTerror_()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            cin>>a[i][j];
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            for(int k=1;k<=n;++k)
                for(int l=1;l<=m;++l)
                    vis[k][l] = false;
            c = a[i][j];
            bool ans = dfs(i,j,i,j);
            if(ans)
            {
                cout<<"Yes\n";return 0;
            }
        }
    }
    cout<<"No\n";
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