#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 3005
#define mod (ll)(998244353)

string s,t;
int n,m;
ll dp[MAXN][MAXN];

ll qp(ll p)
{
    if(!p)
        return 1;
    ll x=qp(p/2);
    x=(x*x)%mod;
    if(p&1)
        x=(x*2)%mod;
    return x;
}

ll solve(int i,int j)
{
    if(i==-1)
        return 1;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(j==m)
        return qp(i+1);

    ll res=0;
    if(t[j]==s[i])
        res=(res+solve(i-1,j+1))%mod;
    if(i+j>=m)
        res=(res+solve(i-1,j))%mod;
    else if(t[i+j]==s[i])
        res=(res+solve(i-1,j))%mod;
    dp[i][j]=res;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s >> t;
    n=s.size();
    m=t.size();
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            dp[i][j]=-1;

    ll c=solve(n-1,0);

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            dp[i][j]=max(0ll,dp[i][j]);
            //cout << dp[i][j] << ' ';
        }
    ll res=0;
    for(int i=m-1;i<n;i++)
        res=(res+dp[i][0])%mod;
    db(res)

    return 0;
}