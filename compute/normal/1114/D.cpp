#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4;
int rel[maxn];
int tot=0;
int dp[5005][5005];
int dfs(int l,int r)
{
    int &ret=dp[l][r];
    if(ret!=-1) return ret;
    if(l>=r) ret=0;
    else if(rel[l]==rel[r]) ret=dfs(l+1,r-1)+1;
    else ret=min(dfs(l+1,r),dfs(l,r-1))+1;
    return ret;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    int n;
    ignore=scanf("%d",&n);
    for(int i=0,temp;i<n;i++)
    {
        ignore=scanf("%d",&temp);
        if(i==0||rel[tot-1]!=temp) rel[tot++]=temp;
    }
    int ans=dfs(0,tot-1);
    printf("%d\n",ans);
}