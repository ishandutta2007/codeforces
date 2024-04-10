#include<bits/stdc++.h>
using namespace std;
const int maxn=4e6,inf=1e9;
int x[maxn+5],y[maxn+5];
int a[maxn+5];
int dp[maxn+5][2];
bool b[maxn+5][2],turn[maxn+5][2];
int n,m1,m2,t,len;
void print(int now)
{
    vector<int> x;
    vector<pair<int,int> >y;
    for(int i=len;i>=1;--i)
    {
        if(turn[i][now]) x.push_back(a[i]),now^=1;
        if(b[i][now]) y.push_back(make_pair(a[i]-dp[i][now],now+1));
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    printf("%d\n",(int)x.size());
    for(auto num:x) printf("%d ",num);
    if(!x.empty())printf("\n");
    printf("%d\n",(int)y.size());
    for(auto num:y) printf("%d %d\n",num.first,num.second);
}
int main()
{
 
    scanf("%d%d%d%d",&n,&m1,&m2,&t);
    a[++len]=0;
    a[++len]=n+1;
    for(int i=1;i<=m1;++i)
    {
        scanf("%d",&x[i]);
        a[++len]=x[i];
        a[++len]=x[i]+1;
        a[++len]=x[i]-1;
    }
    for(int i=1;i<=m2;++i)
    {
        scanf("%d",&y[i]);
        a[++len]=y[i];
        a[++len]=y[i]+1;
        a[++len]=y[i]-1;
    }
    sort(a+1,a+len+1);
    int l=len;
    len=1;
    for(int i=2;i<=l;++i)
        if(a[i]!=a[i-1]) a[++len]=a[i];
    for(int i=1;i<=m1;++i) b[lower_bound(a+1,a+len+1,x[i])-a][0]=1;
    for(int i=1;i<=m2;++i) b[lower_bound(a+1,a+len+1,y[i])-a][1]=1;
    for(int i=0;i<=len+1;++i) dp[i][0]=dp[i][1]=-inf;
    dp[1][0]=0;
    for(int i=1;i<=len;++i)
    {
        if(b[i][0]==0)
        {
            if(min(t,dp[i][1])>dp[i][0])
            {
                dp[i][0]=min(t,dp[i][1]);
                turn[i][0]=1;
            }
        }
        if(b[i][1]==0)
        {
            if(min(t,dp[i][0])>dp[i][1])
            {
                dp[i][1]=min(t,dp[i][0]);
                turn[i][1]=1;
            }
        }
        if(i==1||dp[i][0]>0)
        {
            if(b[i+1][0]==0) dp[i+1][0]=dp[i][0]+a[i+1]-a[i];
            else dp[i+1][0]=dp[i][0]+a[i+1]-a[i]-t;
        }
        if(i==1||dp[i][1]>0)
        {
            if(b[i+1][1]==0) dp[i+1][1]=dp[i][1]+a[i+1]-a[i];
            else dp[i+1][1]=dp[i][1]+a[i+1]-a[i]-t;
        }
    }
   // for(int i=1;i<=len;++i) printf("%d : block : %d %d   %d %d\n",a[i],b[i][0],b[i][1],dp[i][0],dp[i][1]);
    if(dp[len][0]<=0&&dp[len][1]<=0) return 0*printf("No");
    printf("Yes\n");
    if(dp[len][0]>0) print(0);else print(1);
    return 0;
}