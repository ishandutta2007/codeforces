#include<bits/stdc++.h>
using namespace std;
const int N=5050,mod=998244353;
int n,S[N][N],C[N][N],J[N],g[N],f[N];
int main(){
    scanf("%d",&n);S[0][0]=1;
    for(int i=0;i<=n;i++)C[i][0]=1,J[i]=i?1ll*J[i-1]*i%mod:1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod,
            S[i][j]=(S[i-1][j-1]+1ll*j*S[i-1][j])%mod;
    for(int i=1;i<=n;i++)for(int j=1;j<=i;j++)
        g[j]=(g[j]+1ll*S[i][i-j+1]*J[i-j+1]%mod*C[n][i]%mod*J[n-i])%mod;
    for(int i=1;i<=n;i++)
        for(int j=i,op=1;j<=n;j++,op*=-1)
            f[i]=(f[i]+1ll*op*C[j-1][i-1]*g[j])%mod;
    for(int i=1;i<=n;i++)printf("%d ",(f[i]+mod)%mod);
    return 0;
}