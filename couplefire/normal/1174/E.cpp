#include <iostream>
using namespace std;
#define mod 1000000007
int n,dp[1000005][21][2];
int f(int x,int y){
    int tmp=(1<<x);
    if (y) tmp*=3;
    return n/tmp;
}
int main(){
    scanf("%d",&n);
    int p=0;
    while ((1<<p)<=n)
    p++; p--;
    dp[1][p][0]=1;
    if ((1<<(p-1))*3<=n) dp[1][p-1][1]=1;
    for(int i=1;i<n;i++){
        for(int x=0;x<=p;x++){
            for(int y=0;y<=1;y++){
                dp[i+1][x][y]=(dp[i+1][x][y]+1LL*dp[i][x][y]*(f(x,y)-i))%mod;
                if (x) dp[i+1][x-1][y]=(dp[i+1][x-1][y]+1LL*dp[i][x][y]*(f(x-1,y)-f(x,y)))%mod;
                if (y) dp[i+1][x][y-1]=(dp[i+1][x][y-1]+1LL*dp[i][x][y]*(f(x,y-1)-f(x,y)))%mod;
            }
        }
    }
    printf("%d",dp[n][0][0]);
}