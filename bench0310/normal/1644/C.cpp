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
        int n,x;
        cin >> n >> x;
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        vector dp(n+1,vector(n+1,int(0)));
        auto chmax=[&](int &b,int c){b=max(b,c);};
        vector<int> res(n+1,0);
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                chmax(dp[i][j],dp[i-1][j]+a[i]);
                if(j>0) chmax(dp[i][j],dp[i-1][j-1]+a[i]+x);
                chmax(res[j],dp[i][j]);
            }
        }
        for(int i=0;i<=n;i++) cout << res[i] << " \n"[i==n];
    }
    return 0;
}