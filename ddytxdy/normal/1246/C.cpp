#include<bits/stdc++.h>
using namespace std;
const int N=2010,mod=1e9+7;
int n,m,nn,dp[N][N][4],s1[N][N],s2[N][N],ans,f1[N][N],f2[N][N];char c[N][N];//0,1
void add(int *f,int x,int y){for(;x<=nn;x+=x&-x)(f[x]+=y)%=mod;}
int ask(int *f,int x){int y=0;for(;x;x-=x&-x)(y+=f[x])%=mod;return y;}
int main(){
    scanf("%d%d",&n,&m);nn=max(n,m);
    for(int i=1;i<=n;i++)scanf("%s",c[i]+1);
    for(int i=1;i<=n;i++)for(int j=m;j;j--)s1[i][j]=s1[i][j+1]+(c[i][j]=='R');
    for(int i=1;i<=m;i++)for(int j=n;j;j--)s2[i][j]=s2[i][j+1]+(c[j][i]=='R');
    // dp[1][1][0]=1;
    add(f1[1],1,1);add(f1[1],2,-1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            dp[i][j][1]=ask(f2[j],i),dp[i][j][0]=ask(f1[i],j);
            add(f1[i+1],j,dp[i][j][1]);add(f1[i+1],m-s1[i][j]+1,-dp[i][j][1]);
            add(f2[j+1],i,dp[i][j][0]);add(f2[j+1],n-s2[j][i]+1,-dp[i][j][0]);
        }
    printf("%d\n",(ask(f1[n+1],m)+ask(f2[m+1],n))%mod);
    // printf("%d\n",(dp[n+1][m][0]+dp[n][m+1][1])%mod);
    return 0;
}