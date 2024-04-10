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
#define MAXN 2005

int a[MAXN],dp[MAXN][MAXN];
int l,r;

bool ok(int x)
{
    return (l<=x && x<=r);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,h;
    cin >> n >> h >> l >> r;
    for(int i=0;i<n;i++)
        cin >> a[i];

    for(int i=0;i<MAXN;i++)
        for(int j=0;j<MAXN;j++)
            dp[i][j]=-1e9;

    dp[0][0]=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<h;j++)
        {
            int v1=(j+a[i])%h;
            int v2=(j+a[i]-1)%h;
            dp[i+1][v1]=max(dp[i+1][v1],dp[i][j]+ok(v1));
            dp[i+1][v2]=max(dp[i+1][v2],dp[i][j]+ok(v2));
        }
    }

    int res=0;
    for(int i=0;i<h;i++)
        res=max(res,dp[n][i]);
    db(res)

    return 0;
}