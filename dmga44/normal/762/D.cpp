#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
#define MAXN (ll)(1e5+5)
#define oo (ll)(0x3f3f3f3f3f3f3f3f)

ll a[MAXN][3],dp[MAXN][(1<<3)][3];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    mt19937 rng(time(0));

    int n;
    cin >> n;
    for(int j=0;j<3;j++)
        for(int i=0;i<n;i++)
            cin >> a[i][j];
    for(int i=0;i<=n;i++)
        for(int j=0;j<(1<<3);j++)
            for(int k=0;k<3;k++)
                dp[i][j][k]=-oo;
    dp[0][1][0]=0;
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<(1<<3);j++)
        {
            for(int k=0;k<3;k++)
            {
                if(k==0)
                {
                    dp[i+1][1][0]=max(dp[i+1][1][0],dp[i][j][k]+a[i][0]);
                    dp[i+1][3][1]=max(dp[i+1][3][1],dp[i][j][k]+a[i][0]+a[i][1]);
                    dp[i+1][7][2]=max(dp[i+1][7][2],dp[i][j][k]+a[i][0]+a[i][1]+a[i][2]);
                    if(j==7)
                        dp[i+1][7][0]=max(dp[i+1][7][0],dp[i][j][k]+a[i][0]+a[i][1]+a[i][2]);
                }
                if(k==1)
                {
                    dp[i+1][3][0]=max(dp[i+1][3][0],dp[i][j][k]+a[i][0]+a[i][1]);
                    dp[i+1][2][1]=max(dp[i+1][2][1],dp[i][j][k]+a[i][1]);
                    dp[i+1][6][2]=max(dp[i+1][6][2],dp[i][j][k]+a[i][1]+a[i][2]);
                }
                if(k==2)
                {
                    dp[i+1][7][0]=max(dp[i+1][7][0],dp[i][j][k]+a[i][0]+a[i][1]+a[i][2]);
                    dp[i+1][6][1]=max(dp[i+1][6][1],dp[i][j][k]+a[i][2]+a[i][1]);
                    dp[i+1][4][2]=max(dp[i+1][4][2],dp[i][j][k]+a[i][2]);
                    if(j==7)
                        dp[i+1][7][2]=max(dp[i+1][7][2],dp[i][j][k]+a[i][0]+a[i][1]+a[i][2]);
                }
            }
        }
    }
    db(max(dp[n][4][2],max(dp[n][6][2],dp[n][7][2])))

    return 0;
}
/**
3
1 1 1
1 -1 1
1 1 1

5
10 10 10 -1 -1
-1 10 10 10 10
-1 10 10 10 10

1
-1
-2
-5
**/