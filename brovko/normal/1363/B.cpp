#include <bits/stdc++.h>
#define int long long
#define y1 dwihweoighweoi
#define ld long double

using namespace std;

int t, dp[1005][2];
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> s;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            dp[i][0]=1e9;
            dp[i][1]=1e9;
        }

        dp[0][0]=s[0]-'0';
        dp[0][1]=0;

        for(int i=1;i<n;i++)
        {
            if(s[i]=='0')
            {
                dp[i][0]=dp[i-1][0];
                dp[i][1]=min(dp[i-1][0], dp[i-1][1])+1;
            }
            else
            {
                dp[i][0]=dp[i-1][0]+1;
                dp[i][1]=min(dp[i-1][0], dp[i-1][1]);
            }
        }

        int Min=min(dp[n-1][0], dp[n-1][1]);

        for(int i=0;i<n;i++)
        {
            dp[i][0]=1e9;
            dp[i][1]=1e9;
            if(s[i]=='0')
                s[i]='1';
            else s[i]='0';
        }

        dp[0][0]=s[0]-'0';
        dp[0][1]=0;

        for(int i=1;i<n;i++)
        {
            if(s[i]=='0')
            {
                dp[i][0]=dp[i-1][0];
                dp[i][1]=min(dp[i-1][0], dp[i-1][1])+1;
            }
            else
            {
                dp[i][0]=dp[i-1][0]+1;
                dp[i][1]=min(dp[i-1][0], dp[i-1][1]);
            }
        }

        Min=min(Min, min(dp[n-1][0], dp[n-1][1]));
        cout << Min << "\n";
    }
}