#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define fr(i,a,b) for (ll i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (ll i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (ll i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (ll i = n - 1; i >= 0; i--)
#define fill(ar,val) memset(ar, val, sizeof(ar))
#define fill0(ar) fill((ar), 0)
#define debug(x) cout<<#x<<": "<<x<<endl

#define ld double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000000000000

ll dp[1002][1002];
ll mat[1002][1002];
ll mark[1002][1002];
ll ans=0;
ll n,m;
void dfs(ll x,ll y)
{
    if(mark[x][y])
    {
        return;
    }
    mark[x][y]=1;
    if(x-1!=0)
    {
        if(mat[x-1][y])
        {
            dfs(x-1,y);
        }
        else
        {
            ans+=1;
        }
    }
    if(y-1!=0)
    {
        if(mat[x][y-1])
        {
            dfs(x,y-1);
        }
        else
        {
            ans+=1;
        }
    }
    if(x!=n)
    {
        if(mat[x+1][y])
        {
            dfs(x+1,y);
        }
        else
        {
            ans+=1;
        }
    }
    if(y!=m)
    {
        if(mat[x][1+y])
        {
            dfs(x,1+y);
        }
        else
        {
            ans+=1;
        }
    }
}
void dfs1(ll x,ll y)
{
    //debug(ans);
    if(mark[x][y]==2)
    {
        return;
    }
    mark[x][y]=2;
    dp[x][y]=ans;
    if(x-1!=0)
    {
        if(mat[x-1][y])
        {
            dfs1(x-1,y);
        }
    }
    if(y-1!=0)
    {
        if(mat[x][y-1])
        {
            dfs1(x,y-1);
        }
    }
    if(x!=n)
    {
        if(mat[x+1][y])
        {
            dfs1(x+1,y);
        }
    }
    if(y!=m)
    {
        if(mat[x][1+y])
        {
            dfs1(x,1+y);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    double pi= 3.14159265358979323846;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll k;
    cin>>n>>m>>k;
    
    rep(i,n)
    {
        rep(j,m)
        {
            char c;
            cin>>c;
            if(c=='*')
            {
                mat[i+1][1+j]=0;
            }
            else
            {
                mat[1+i][1+j]=1;
            }
        }
    }
    rep(i,n+2)
    {
        rep(j,m+2)
        {dp[i][j]=-1;}}
    rep(i,k)
    {
        ll x,y;
        cin>>x>>y;
        if(dp[x][y]!=-1)
        {
            cout<<dp[x][y]<<endl;
        }
        else
        {
            ans=0;
            dfs(x,y);
            dfs1(x,y);
            cout<<dp[x][y]<<endl;
        }
    }
    
    return 0;
}