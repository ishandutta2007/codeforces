#include<bits/stdc++.h>
using namespace std;
const int N=20;
int a[N][N],n=10;double dp[N][N],sum;
void mov(int x,int y,int k,int &xx,int &yy){
    if(x&1){
        int dat=min(y-1,k);
        y-=dat;k-=dat;if(!k){xx=x;yy=y;return;}
        k--;x--;
        y+=k;xx=x;yy=y;
    }
    else{
        int dat=min(n-y,k);
        y+=dat;k-=dat;if(!k){xx=x;yy=y;return;}
        k--;x--;
        y-=k;xx=x;yy=y;
    }
}
int main(){
    dp[1][1]=0;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
    for(int i=2;i<=6;i++)dp[1][i]=(sum+6)/(i-1),sum+=dp[1][i];
    for(int i=7;i<=n;i++){
        sum=0;
        for(int j=i-6;j<i;j++)sum+=dp[1][j];
        dp[1][i]=sum/6+1;
    }
    for(int i=2;i<=n;i++){
        if(!(i&1)){
            for(int j=n;j;j--){
                sum=0;
                for(int k=1;k<=6;k++){
                    int xx,yy;mov(i,j,k,xx,yy);
                    sum+=min(dp[xx][yy],dp[xx-a[xx][yy]][yy]);
                }
                dp[i][j]=sum/6+1;
            }
        }
        else{
            for(int j=1;j<=n;j++){
                sum=0;
                for(int k=1;k<=6;k++){
                    int xx,yy;mov(i,j,k,xx,yy);
                    sum+=min(dp[xx][yy],dp[xx-a[xx][yy]][yy]);
                }
                dp[i][j]=sum/6+1;
            }
        }
    }
    printf("%.10f",dp[n][1]);
    return 0;
}