#include<bits/stdc++.h>
using namespace std;
#define N 5005
int n,mod;
int f[N][N];
int ans[N],g[N+N];
int qpow(int x,int y){
    int t=1;
    for(;y;y>>=1){
        if(y&1)t=1LL*t*x%mod;
        x=1LL*x*x%mod;
    }
    return t;
}
int main(){
    int i,j,k;
    scanf("%d%d",&n,&mod);
    for(i=1;i<=n;++i){
        f[1][i]=1;
        g[1+i]++;
    }
    ans[0]=0;
    ans[1]=1;
    for(i=2;i<=n;++i){
        for(j=1;j<i;++j){
            int t1=1;
            if(i-j-j-1>=0){
                t1+=g[i-j-j-1];
                t1%=mod;
            }
            f[i][j]=1LL*t1*ans[j]%mod;
        }
        for(j=1;j<i;++j)(f[i][j]+=f[i][j-1])%=mod;
        f[i][i]=qpow(2,i-1);
        for(j=i+1;j<=n;++j)f[i][j]=f[i][i];
        ans[i]=(f[i][i]-f[i][i-1]+mod)%mod;
        for(j=1;j<=n;++j)(g[i+j]+=f[i][j])%=mod;
    }
    printf("%d\n",ans[n]);
    return 0;
}