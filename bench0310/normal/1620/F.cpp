#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        const int inf=(1<<30);
        vector<array<int,2>> dp(n+1,{inf,inf});
        vector<array<int,2>> p(n+1,{-1,-1});
        dp[1]={-inf,-inf};
        auto upd=[&](int i,int j,int lim,int u)
        {
            if(lim<dp[i][j])
            {
                dp[i][j]=lim;
                p[i][j]=u;
            }
        };
        //x will always be either lim or max, dp[i][j] is the other, try minimising it
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<2;j++)
            {
                if(dp[i][j]==inf) continue;
                int x=(j?-a[i]:a[i]);
                for(int k=0;k<2;k++)
                {
                    int y=(k?-a[i+1]:a[i+1]);
                    if(x<y) upd(i+1,k,dp[i][j],j);
                    if(dp[i][j]<y) upd(i+1,k,x,j);
                }
            }
        }
        if(dp[n][0]!=inf)
        {
            int s=0;
            cout << "YES\n";
            vector<int> res(n+1,0);
            for(int i=n;i>=1;i--)
            {
                res[i]=(s?-a[i]:a[i]);
                s=p[i][s];
            }
            for(int i=1;i<=n;i++) cout << res[i] << " \n"[i==n];
        }
        else cout << "NO\n";
    }
    return 0;
}