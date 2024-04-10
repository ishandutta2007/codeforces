#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
int MOD = 1e9+7;
int dp[2][5002];
void add(int &x,int v){
    x+=v;
    if(x>=MOD)x-=MOD;
    if(x<0)x+=MOD;
}
int main(){
    int n,a,b,K;
    scanf("%d%d%d%d",&n,&a,&b,&K);
    dp[0][a]=1;
    for(int k=1;k<=K;k++){
        int now=k&1;
        int lt=now^1;
        for(int i=1;i<=n;i++)dp[now][i]=0;
        for(int i=1;i<=n;i++){
            if(i==b)continue;
            int mii;
            if(i<b)mii=max(1,i*2-b+1);
            else mii=b+1;
            int maa;
            if(i<b)maa=b-1;
            else maa=min(n,i*2-b-1);
            add(dp[now][mii],dp[lt][i]);
            add(dp[now][i],-dp[lt][i]);
            add(dp[now][i+1],dp[lt][i]);
            add(dp[now][maa+1],-dp[lt][i]);
        }
        for(int i=2;i<=n;i++)add(dp[now][i],dp[now][i-1]);
    }
    int an=0;
    for(int i=1;i<=n;i++)add(an,dp[K&1][i]);
    printf("%d\n",an);
    return 0;
}