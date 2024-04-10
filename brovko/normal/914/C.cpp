#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;
const int MOD=1e9+7;

string s;
int k, dp[1005], dp2[1005][1005][2];

int add(int x, int y)
{
    return (x+y)%MOD;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s >> k;

    dp[1]=0;
    for(int i=2;i<1005;i++)
    {
        int c=0;
        int z=i;
        while(z)
        {
            c+=z%2;
            z/=2;
        }

        dp[i]=dp[c]+1;
    }

    int n=s.size();

    if(s[0]=='0')
    {
        dp2[0][0][1]=1;
    }
    else
    {
        dp2[0][0][0]=1;
        dp2[0][1][1]=1;
    }

    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<=n;j++)
        {
            dp2[i+1][j][0]=add(dp2[i+1][j][0], dp2[i][j][0]);

            dp2[i+1][j+1][0]=add(dp2[i][j][0], dp2[i+1][j+1][0]);

            if(s[i+1]=='0')
                dp2[i+1][j][1]=add(dp2[i+1][j][1], dp2[i][j][1]);
            else
            {
                dp2[i+1][j][0]=add(dp2[i][j][1], dp2[i+1][j][0]);
                dp2[i+1][j+1][1]=add(dp2[i][j][1], dp2[i+1][j+1][1]);
            }
        }
    }

    /*for(int i=0;i<=n;i++)
        cout << dp2[n-1][i][0] << ' ';
    cout << endl;*/

    int ans=0;

    for(int j=1; j<=n;j++)
        if(dp[j]==k-1)
    {
        //cout << j << endl;
        ans=add(ans, dp2[n-1][j][0]+dp2[n-1][j][1]);
    }

    if(k==1)
        ans=add(ans, MOD-1);
    if(k==0)
        ans=add(ans, 1);

    cout << ans;
}