#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=(int) 1e5+7;
const int INF=(int) 1e9;
int r;
int n;
int t[N];
int x[N];
int y[N];
int dp[N];
int pre[N];

signed main()
{
        ios::sync_with_stdio(0); cin.tie(0);
        cin>>r>>n;
        x[0]=1;
        y[0]=1;
        for (int i=1;i<=n;i++)
        {
                cin>>t[i]>>x[i]>>y[i];
                dp[i]=-INF;
        }
        pre[0]=0;
        for (int i=1;i<=n;i++)
        {
                for (int j=i-1;j>=0;j--)
                {
                        if (t[i]-t[j]>2*r+10)
                        {
                                dp[i]=max(dp[i],pre[j]+1);
                                break;
                        }
                        if (abs(x[i]-x[j])+abs(y[i]-y[j])<=t[i]-t[j])
                        {
                                dp[i]=max(dp[i],dp[j]+1);
                        }
                }
                pre[i]=max(pre[i-1],dp[i]);
        }
        cout<<pre[n]<<"\n";
}