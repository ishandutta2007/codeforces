#include<bits/stdc++.h>
#define N 2005
#define mod 998244353
using namespace std;
int num[N], c[N];
int f[2][N][N];
int main(){
    int n,i,x,j,k,ans=0;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d",&x);
        ++num[x];
        ++c[num[x]];
    }
    for(i=1;i<=n;++i){
        c[i]+=c[i-1];
    }
    f[0][0][n]=1;
    for(i=1;i<=n;++i){
        int nw=i&1;
        for(j=0;j<=n;++j){
            for(k=n/max(1,i-1);k>=0;--k){
                (f[nw^1][j][k]+=f[nw^1][j][k+1])%=mod;
            }
        }
        for(j=0;j<=n;++j){
            if(j<=c[i]){
                for(k=n/i;k>=0;--k){
                    if(j>=k)(f[nw][j][k]+=f[nw^1][j-k][k])%=mod;
                }
            }
            else{
                for(k=n/i;k>=0;--k)f[nw][j][k]=0;
            }
        }
        for(j=0;j<=n;++j){
            for(k=n/max(1,i-1);k>=0;--k){
                f[nw^1][j][k]=0;
            }
        }
    }
    for(k=0;k<=n;++k){
        ans+=f[n&1][n][k];
        ans%=mod;
    }
    printf("%d\n",ans);
    return 0;
}