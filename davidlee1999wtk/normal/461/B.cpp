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
#define P 1000000007
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
vector<int> G[100005];
LL dp[100005][2];
int c[100005];
LL ksm(LL a,LL b)
{
    LL c=1,d=a;
    while(b)
    {
        if(b&1)
            c=(c*d)%P;
        d=(d*d)%P;
        b>>=1;
    }
    return c;
}

void dfs(int x)
{
    int i,len,v;
    len=G[x].size();
    dp[x][0]=dp[x][1]=1;
    for(i=0;i<len;i++)
    {
        v=G[x][i];
        dfs(v);
        if(c[x]==0)
            dp[x][0]=dp[x][0]*(dp[v][0]+dp[v][1])%P;
        else dp[x][1]=dp[x][1]*(dp[v][0]+dp[v][1])%P;
    }
    if(c[x]==1)
        dp[x][0]=0;
    else
    {
        dp[x][1]=0;
        for(i=0;i<len;i++)
        {
            v=G[x][i];
            dp[x][1]=(dp[x][1]+(dp[x][0]*dp[v][1]%P)*ksm(dp[v][0]+dp[v][1],P-2))%P;
        }
    }
    //printf("x=%d %I64d %I64d\n",x,dp[x][0],dp[x][1]);
}

int main()
{
    int n,i,x;
    cin>>n;
    for(i=2;i<=n;i++)
    {
        scanf("%d",&x);
        G[x+1].push_back(i);
    }
    for(i=1;i<=n;i++)
        scanf("%d",&c[i]);
    dfs(1);
    //printf("%I64d",dp[1][1]);
    //cout<<dp[1][1]<<endl;
    cout<<dp[1][1]%P<<endl;
    return 0;
}
// davidlee1999WTK 2014/
// srO myk Orz
//ios::sync_with_stdio(false);