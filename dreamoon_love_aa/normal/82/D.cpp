#include<stdio.h>
#include<algorithm>
using namespace std;
#define SIZE 1024
#define MAX 2000000000
int a[SIZE],dp[512][SIZE];
int back[512][SIZE];
void track(int x,int y){
    if(x==0)return;
    int tmp[3]={back[x][y],2*x,2*x+1},first=0,i;
    track(x-1,back[x][y]);
    for(i=0;i<3;i++){
        if(tmp[i]!=y){
            if(!first)first++;
            else putchar(' ');
            printf("%d",tmp[i]);
        }
    }
    puts("");
}
main(){
    int n,tmp,i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    for(i=1;i<=(n+1)/2;i++)
        for(j=1;j<=n;j++)dp[i][j]=MAX;
    dp[0][1]=0;
    for(i=1;i*2+1<=n;i++){
        for(j=1;j<i*2;j++){
            tmp=max(a[j],a[i*2])+dp[i-1][j];
            if(tmp<dp[i][i*2+1]){
                dp[i][i*2+1]=tmp;
                back[i][i*2+1]=j;
            }
            tmp=max(a[j],a[i*2+1])+dp[i-1][j];
            if(tmp<dp[i][i*2]){
                dp[i][i*2]=tmp;
                back[i][i*2]=j;
            }
            tmp=max(a[i<<1],a[i*2+1])+dp[i-1][j];
            if(tmp<dp[i][j]){
                dp[i][j]=tmp;
                back[i][j]=j;
            }
        }
    }
    if(n&1){
        i--;
        tmp=MAX;
        for(j=1;j<=n;j++){
            if(dp[i][j]+a[j]<tmp){
                tmp=dp[i][j]+a[j];
                k=j;
            }
        }
        printf("%d\n",tmp);
        track(i,k);
        printf("%d\n",k);
    }
    else{
        tmp=MAX;
        i--;
        for(j=1;j<n;j++){
            if(dp[i][j]+max(a[j],a[n])<tmp){
                tmp=dp[i][j]+max(a[j],a[n]);
                k=j;
            }
        }
        printf("%d\n",tmp);
        track(i,k);
        printf("%d %d\n",k,n);
    }
}