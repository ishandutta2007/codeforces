#include<bits/stdc++.h>
const int N=1e5+50,mod=998244353;
int n,k,f[N],a[N],g[N],ans;
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    f[n+1]=1;
    for(int i=1;i<=n;i++){
        int to=i%n+1;
        if(a[i]==a[to]){for(int j=-i;j<=i;j++)f[j+n+1]=1ll*f[j+n+1]*k%mod;continue;}
        for(int j=-i;j<=i;j++)g[j+n+1]=(f[j-1+n+1]+f[j+1+n+1]+1ll*f[j+n+1]*(k-2))%mod;
        for(int j=-i;j<=i;j++)f[j+n+1]=g[j+n+1];
    }
    for(int i=1;i<=n;i++)(ans+=f[i+n+1])%=mod;
    printf("%d\n",ans);
    return 0;
}