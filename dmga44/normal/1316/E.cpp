#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 100005
#define oo (ll)(1e18)

vector<pii> a;
ll dp[MAXN][128],cij[MAXN][7];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,k,p,x;
    cin >> n >> p >> k;
    for(int i=0;i<n;i++)
    {
        cin >> x;
        a.push_back(pii(x,i));
    }

    for(int j=0;j<n;j++)
        for(int i=0;i<p;i++)
            cin >> cij[j][i];

    sort(a.rbegin(),a.rend());
    for(int i=0;i<n;i++)
        for(int j=0;j<(1<<p);j++)
            dp[i][j]=-oo;

    dp[0][0]=0;
    for(int i=0;i<n;i++)
    {
        int pos=a[i].second;
        for(int j=0;j<(1<<p);j++)
        {
            dp[i+1][j]=dp[i][j];
            if(i-__builtin_popcount(j)<k)
                dp[i+1][j]=max(dp[i][j]+a[i].first,dp[i+1][j]);
            for(int u=0;u<p;u++)
                if(j&(1<<u))
                    dp[i+1][j]=max(dp[i][j-(1<<u)]+cij[pos][u],dp[i+1][j]);
        }
    }

    db(dp[n][(1<<p)-1])

    return 0;
}