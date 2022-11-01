#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> v={0};
    for(int i=1;i<=n;i++)
    {
        int a;
        cin >> a;
        while(a--) v.push_back(i);
    }
    vector cost(m+2,vector(m+1,vector(n+1,int(0))));
    for(int i=1;i<=n;i++)
    {
        for(int l=1;l<=m;l++)
        {
            int t=0;
            for(int r=l;r<=m;r++)
            {
                t+=abs(v[r]-i);
                cost[l][r][i]=t;
            }
        }
    }
    const int inf=(1<<30);
    vector dp(m+1,vector(m+1,int(inf))); //sum,prv
    dp[0][m]=0;
    auto chmin=[&](int &a,int b){a=min(a,b);};
    for(int i=1;i<=n;i++)
    {
        int mx=(m/i);
        vector ndp(m+1,vector(mx+1,int(inf)));
        for(int s=0;s<=m;s++)
        {
            for(int p=0;p<=(m/max(1,i-1));p++)
            {
                for(int j=0;j<=min({m-s,p,mx});j++)
                {
                    chmin(ndp[s+j][j],dp[s][p]+cost[s+1][s+j][i]);
                }
            }
        }
        dp=ndp;
    }
    int res=inf;
    for(int i=0;i<=(m/n);i++) chmin(res,dp[m][i]);
    cout << res << "\n";
    return 0;
}