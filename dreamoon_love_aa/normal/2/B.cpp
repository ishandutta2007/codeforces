#include<stdio.h>
#include<algorithm>
using namespace std;
#define SIZE 1010
int a[SIZE][SIZE],dp[SIZE][SIZE],an,last[SIZE][SIZE];
char s[SIZE+SIZE];
int f(int x,int y){
    if(x==0)return 2;
    int an=0;
    while(x%y==0){
        an++;
        x/=y;
    }
    return an;
}
void Track(int x,int y,int &iter){
    if(x==1&&y==1)return;
    if(last[x][y]==1){
        Track(x-1,y,iter);
        s[iter++]='D';
    }
    else{
        Track(x,y-1,iter);
        s[iter++]='R';
    }
}
void g(int x,int N){
    int i,j;
    for(i=1;i<=N;i++)
        for(j=1;j<=N;j++){
            int tmp=f(a[i][j],x);
            if(i==1){
                dp[i][j]=dp[i][j-1]+tmp;
                last[i][j]=0;
            }
            else if(j==1){
                dp[i][j]=dp[i-1][j]+tmp;
                last[i][j]=1;
            }
            else{
                if(dp[i-1][j]<dp[i][j-1]){
                    dp[i][j]=dp[i-1][j]+tmp;
                    last[i][j]=1;
                }
                else{
                    dp[i][j]=dp[i][j-1]+tmp;
                    last[i][j]=0;
                }
            }
        }
        if(an>dp[N][N]){
            an=dp[N][N];
            int tmp=0;
            Track(N,N,tmp);
            s[tmp]=0;
        }
}
main(){
    int N,i,j;
    an=100000;
    scanf("%d",&N);
    for(i=1;i<=N;i++)
        for(j=1;j<=N;j++)scanf("%d",&a[i][j]);
    g(2,N);
    g(5,N);
    if(an>1){

        for(i=1;i<=N;i++){
            for(j=1;j<=N;j++)
                if(a[i][j]==0)break;
            if(j<=N)break;
        }
        if(i<=N){
            int k=0;
            for(j=1;j<i;j++)s[k++]='D';
            for(j=1;j<N;j++)s[k++]='R';
            for(j=i;j<N;j++)s[k++]='D';
            s[k]=0;
            an=1;
        }
    }
    printf("%d\n%s\n",an,s);
}