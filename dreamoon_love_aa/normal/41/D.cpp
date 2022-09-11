#include<stdio.h>
#include<string.h>
#define SIZE 128
char s[SIZE][SIZE];
int a[SIZE][SIZE],dp[SIZE][SIZE][11],last[SIZE][SIZE][11],K;
void print(int x,int y,int z){
    if(x==0){
        printf("%d\n",y+1);
        return;
    }
    print(x-1,y+last[x][y][z],(z-a[x][y]+K*10)%K);
    if(last[x][y][z]==-1)printf("R");
    else printf("L");
}
main(){
    int n,m,i,j,k,ma,final;
    scanf("%d%d%d",&n,&m,&K);
    K++;
    for(i=0;i<n;i++)scanf("%s",s[i]);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)a[i][j]=s[n-1-i][j]-'0';
    memset(dp,-1,sizeof(dp));
    for(i=0;i<m;i++)dp[0][i][a[0][i]%K]=a[0][i];
    for(i=1;i<n;i++)
        for(j=0;j<m;j++){
            if(j){
                for(k=0;k<K;k++){
                    if(dp[i-1][j-1][k]<0||dp[i-1][j-1][k]+a[i][j]<=dp[i][j][(k+a[i][j])%K])continue;
                    dp[i][j][(k+a[i][j])%K]=dp[i-1][j-1][k]+a[i][j];
                    last[i][j][(k+a[i][j])%K]=-1;
                }
            }
            if(j!=m-1){
                for(k=0;k<K;k++){
                    if(dp[i-1][j+1][k]<0||dp[i-1][j+1][k]+a[i][j]<=dp[i][j][(k+a[i][j])%K])continue;
                    dp[i][j][(k+a[i][j])%K]=dp[i-1][j+1][k]+a[i][j];
                    last[i][j][(k+a[i][j])%K]=1;
                }
            }
        }
    ma=-1;
    for(i=0;i<m;i++){
        if(dp[n-1][i][0]>ma){
            ma=dp[n-1][i][0];
            final=i;
        }
    }
    if(ma==-1)puts("-1");
    else{
        printf("%d\n",ma);
        print(n-1,final,0);
        puts("");
    }
}