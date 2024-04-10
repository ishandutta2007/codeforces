#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
const int maxn=1e5+7;
double dp[maxn][10];
int pre[maxn][10];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,d;
    cin>>n>>d;
    vector<int> a(n+1);
    for(int i=0;i<maxn;i++) for(int j=0;j<10;j++) dp[i][j]=-1e9;
    dp[0][1]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        double val=log(a[i]);
        for(int j=0;j<10;j++)
        {
            int nxt=j*a[i]%10;
            if(dp[i-1][j]>dp[i][j])
            {
                dp[i][j]=dp[i-1][j];
                pre[i][j]=j;
            }
            if(dp[i-1][j]+val>dp[i][nxt])
            {
                dp[i][nxt]=dp[i-1][j]+val;
                pre[i][nxt]=j;
            }
        }
    }
    if(dp[n][d]<0)
    {
        cout<<-1<<'\n';
        return 0;
    }
    vector<int> ans;
    int cur=d;
    for(int i=n;i>=1;i--)
    {
        int cc=a[i]%10;
        if((pre[i][cur]*cc)%10==cur)
        {
            cur=pre[i][cur];
            ans.push_back(a[i]);
        }
    }
    if(ans.size()==0)
    {
        cout<<-1<<'\n';
        return 0;
    }
    cout<<ans.size()<<'\n';
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" \n"[i+1==ans.size()];

}