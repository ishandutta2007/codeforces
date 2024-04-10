#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 1000005

int dp[MAXN][3][3],f[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,m,a;
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        cin >> a;
        f[a+2]++;
    }

    for(int i=2;i<MAXN;i++)
        for(int j=0;j<3;j++)
            for(int u=0;u<3;u++)
                for(int g=0;g<3;g++)
                    if(f[i-2]>=(j+u+g) && f[i-1]>=(u+g) && f[i]>=g)
                        dp[i][u][g]=max(dp[i-1][j][u]+g+((f[i-2]-j-u-g)/3),dp[i][u][g]);

    int res=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            res=max(res,dp[MAXN-1][i][j]);
    db(res)

    return 0;
}