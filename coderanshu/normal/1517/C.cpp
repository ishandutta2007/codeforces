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

const int N = 505;

int n;
int a[N];

int ans[N][N];

int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};


int cnt;

void dfs(int x,int y,int cur)
{
    if(ans[x][y])
        return ;
    if(cnt == 0)
        return ;
    auto valid = [&](int x,int y)
    {
        if(x>=1 && y>=1 && x<=n && y<=n && y <= x)
            return true;
        return false;
    };
    // cout<<x<<" "<<y<<" "<<cnt<<"\n";
    ans[x][y] = cur;
    --cnt;
    for(int i=0;i<4;++i)
    {
        if(cnt == 0)
            return ;
        if(valid(x+dx[i],y+dy[i]))
            dfs(x+dx[i],y+dy[i],cur);
    }
}

int _runtimeTerror_()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;++i)
    {
        cnt = a[i];
        dfs(i,i,a[i]);
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=i;++j)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
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