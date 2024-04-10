#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#define INF 100000000
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int s[6][1005],n;
int dp[1005],loc[1005][1005];
int main()
{
    int k,ans,i,j,x,l,y,flag;
    cin>>n>>k;
    ans=0;
    for(i=1;i<=k;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&s[i][j]);
    for(j=2;j<=k;j++)
        for(i=1;i<=n;i++)
            loc[j][s[j][i]]=i;
    for(i=1;i<=n;i++)
    {
        x=s[1][i];
        for(l=i-1;l;l--)
        {
            flag=1;
            y=s[1][l];
            for(j=2;j<=k;j++)
                if(loc[j][y]>loc[j][x])
                    flag=0;
            if(flag)
                dp[x]=max(dp[x],dp[y]);
        }
        dp[x]++;
        ans=max(ans,dp[x]);
    }
    cout<<ans<<endl;
}

// davidlee1999WTK 2014/
// srO myk Orz
//ios::sync_with_stdio(false);