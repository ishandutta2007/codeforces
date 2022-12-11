#include<cmath>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=555,mod=998244353;
int n,x,f[N][N],pw[N][N],C[N][N];
int main(){
    scanf("%d%d",&n,&x);
    for(int i=0;i<=x;i++)f[0][i]=1;
    for(int i=0;i<=n;i++)C[i][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
    for(int i=1;i<=x;i++){
        pw[i][0]=1;
        for(int j=1;j<=n;j++)
            pw[i][j]=1ll*pw[i][j-1]*i%mod;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=x;j++){
            if(j<i){f[i][j]=pw[j][i];continue;}
            for(int k=0;k<=i;k++)
                f[i][j]=(f[i][j]+1ll*f[k][j-i+1]*pw[i-1][i-k]%mod*C[i][i-k])%mod;
        }
    cout<<f[n][x]<<endl;
    return 0;
}