#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int dp[41][4096],n,m,nm,an,K,next;
void re(int &x,int v){
    if(x==-1||x>v)x=v;
}
main(){
    int i,j;
    scanf("%d%d",&n,&m);
    nm=an=n*m;
    if(n>m)swap(n,m);
    memset(dp,-1,sizeof(dp));
    K=1<<(n<<1);
    dp[0][K-(1<<n)]=0;
    for(i=0;i<nm;i++){
        for(j=0;j<K;j++){
            if(dp[i][j]<0)continue;
            if(j&(K>>1)){
                next=(j<<1)&(K-1);
                re(dp[i+1][next],dp[i][j]);
            }
            next=j;
            if(i%n!=0)next|=1<<n;
            next|=1<<(n-1);
            if(i%n!=n-1)next|=1<<(n-2);
            next<<=1;
            next&=K-1;
            next|=1;
            re(dp[i+1][next],dp[i][j]+1);
        }
    }
    for(i=K-(1<<n);i<(1<<(n<<1));i++)
        if(dp[nm][i]!=-1&&dp[nm][i]<=an)an=dp[nm][i];
    printf("%d\n",nm-an);
}