#include<bits/stdc++.h>
#define int long long
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while('0'<=ch && ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
    return x*f;
}
using namespace std;
const int p=1e9+7;
int n=read(),K=read();
int dp[103][43],now[43];
vector<int> e[103];
void dfs(int x,int f)
{
    dp[x][0]=dp[x][K+1]=1;
    for(int i=0;i<e[x].size();i++)
    if(e[x][i]!=f)
    {
        int v=e[x][i];
        dfs(v,x);
        memset(now,0,sizeof(now));
        for(int j=0; j<=2*K; j++) for(int k=0; k<=2*K; k++)
        (j+k<=2*K)?(now[min(j,k+1)]=(now[min(j,k+1)]+dp[x][j]*dp[v][k])%p):now[max(j,k+1)]=(now[max(j,k+1)]+dp[x][j]*dp[v][k])%p;
    	for(int j=0; j<=2*K; j++) dp[x][j]=now[j];
    }
}
signed main()
{
    for(int i=1,x,y; i<n; i++)
	x=read(),y=read(),e[x].push_back(y),e[y].push_back(x);
    dfs(1,0);
    int ans=0;
    for(int i=0; i<=K; i++) ans=(ans+dp[1][i])%p;
    printf("%lld\n",ans);
    return 0;
}