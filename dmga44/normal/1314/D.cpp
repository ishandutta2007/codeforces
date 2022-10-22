#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 85
#define oo (ll)(1e10)

ll a[MAXN][MAXN],dp[11][MAXN];
bool mk[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    srand(time(0));

    int n,k;
    cin >> n >> k;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> a[i][j];

    ll res=oo;
    int loops=7500;
    for(int i=0;i<loops;i++)
    {
        for(int j=1;j<n;j++)
            mk[j]=rand()&1;

        for(int j=0;j<n;j++)
            for(int u=0;u<=k;u++)
                dp[u][j]=oo;
        dp[0][0]=0;
        for(int u=1;u<=k;u++)
            for(int j=0;j<n;j++)
                for(int h=0;h<n;h++)
                    if(h!=j && mk[h]==(u&1))
                        dp[u][h]=min(dp[u][h],dp[u-1][j]+a[j][h]);
        res=min(res,dp[k][0]);
    }
    db(res)

    return 0;
}