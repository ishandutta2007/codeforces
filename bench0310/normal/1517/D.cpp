#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    vector<array<int,2>> z={{1,0},{-1,0},{0,1},{0,-1}}; //DURL
    vector<vector<array<int,4>>> w(n+1,vector<array<int,4>>(m+1,{-1,-1,-1,-1}));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<m;j++)
        {
            int a;
            cin >> a;
            w[i][j][2]=a;
            w[i][j+1][3]=a;
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int a;
            cin >> a;
            w[i][j][0]=a;
            w[i+1][j][1]=a;
        }
    }
    const int inf=(1<<30);
    auto chmin=[&](int &a,int b){a=min(a,b);};
    vector dp(n+1,vector(m+1,vector(k+1,inf)));
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) dp[i][j][0]=0;
    for(int o=2;o<=k;o+=2)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                for(int t=0;t<4;t++)
                {
                    auto [di,dj]=z[t];
                    if(w[i][j][t]!=-1) chmin(dp[i][j][o],dp[i+di][j+dj][o-2]+2*w[i][j][t]);
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(k&1) dp[i][j][k]=-1;
            cout << dp[i][j][k] << " \n"[j==m];
        }
    }
    return 0;
}