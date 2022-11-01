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
        int n,k;
        cin >> n >> k;
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        vector nxt(n+2,vector(n+1,n+1));
        for(int i=n;i>=1;i--)
        {
            nxt[i]=nxt[i+1];
            nxt[i][a[i]]=i;
        }
        vector dp(n+1,vector(n+1,n+1));
        dp[0][0]=0;
        auto chmin=[&](int &x,int y){x=min(x,y);};
        int res=n+1;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(dp[i][j]==n+1) continue;
                if(j>=k) chmin(res,dp[i][j]-i);
                if(i+1<=n) chmin(dp[i+1][j],dp[i][j]+1);
                int p=nxt[dp[i][j]+1][i+1];
                if(i+1<=n&&j+1<=n&&p!=n+1) chmin(dp[i+1][j+1],p);
            }
        }
        if(res==n+1) res=-1;
        cout << res << "\n";
    }
    return 0;
}