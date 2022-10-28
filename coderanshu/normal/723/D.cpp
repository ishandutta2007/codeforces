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
const int N=55;
char a[N][N];
int n,m,k,fuck=0,ans=0;
vector<pair<int,pair<int,int>>> v;
void dfs(int i,int j,char c)
{
    if(a[i][j]!='.')
        return ;
    a[i][j]=c;
    ++fuck;
    if(i<n-1)dfs(i+1,j,c);
    if(j<m-1)dfs(i,j+1,c);
    if(i>0)dfs(i-1,j,c);
    if(j>0)dfs(i,j-1,c);
}
void dfs2(int i,int j)
{
    if(a[i][j]!='A')
        return ;
    a[i][j]='.';
    if(i<n-1)dfs2(i+1,j);
    if(j<m-1)dfs2(i,j+1);
    if(i>0)dfs2(i-1,j);
    if(j>0)dfs2(i,j-1);
}
int _runtimeTerror_()
{
    cin>>n>>m>>k;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            cin>>a[i][j];
    for(int i=0;i<n;++i)
    {
        if(a[i][0]=='.')
            dfs(i,0,'F');
        if(a[i][m-1]=='.')
            dfs(i,m-1,'F');
    }
    for(int j=0;j<m;++j)
    {
        if(a[0][j]=='.')
            dfs(0,j,'F');
        if(a[n-1][j]=='.')
            dfs(n-1,j,'F');
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(a[i][j]=='.')
            {
                fuck=0;
                dfs(i,j,'A');
                ans+=fuck;
                v.pb({-fuck,{i,j}});
            }
        }
    }
    sort(all(v));
    for(int i=0;i<k;++i)
    {
        ans+=v[i].F;
        dfs2(v[i].S.F,v[i].S.S);
    }
    cout<<ans<<'\n';
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
            cout<<(a[i][j]=='F'?'.':a[i][j]=='A'?'*':a[i][j]);
        cout<<endl;
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
    cerr<<"\n"<<_time_;
    return 0;
}