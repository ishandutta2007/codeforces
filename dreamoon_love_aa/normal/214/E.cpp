#include<stdio.h>
#include<string.h>
using namespace std;
int M,N,a[333][333],dp[611][311][311];
int dx[2]={1,0};
int dy[2]={0,1};
void fresh(int &x,int v){if(x<v)x=v;}
int main(){
    int i,j,k;
    while(scanf("%d",&N)==1){
        M=N;
        for(i=0;i<611;i++)
            for(j=0;j<311;j++)
                for(k=0;k<311;k++)dp[i][j][k]=-1000000000;
        for(i=0;i<M;i++)
            for(j=0;j<N;j++)scanf("%d",&a[i][j]);
        dp[0][0][0]=a[0][0];
        for(i=0;i<M+N-2;i++){
            for(j=0;j<M&&j<=i;j++){
                if(i-j>=N)continue;
                for(k=0;k<M&&k<=i;k++){
                    if(i-k>=N)continue;
                    for(int jj=0;jj<2;jj++)
                        for(int kk=0;kk<2;kk++){
                            if(i-j-jj>=N||j+jj>=M)continue;
                            if(i-k-kk>=N||k+kk>=M)continue;
                            if(j+jj==k+kk)fresh(dp[i+1][j+jj][k+kk],dp[i][j][k]+a[j+jj][i+1-j-jj]);
                            else fresh(dp[i+1][j+jj][k+kk],dp[i][j][k]+a[j+jj][i+1-j-jj]+a[k+kk][i+1-k-kk]);
                        }
                }
            }
        }
        printf("%d\n",dp[M+N-2][M-1][M-1]);
    }
}