#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50,mod=1e9+7;
int t,n,m,J[N],I[N];
int C(int n,int m){return 1ll*J[n]*I[m]%mod*I[n-m]%mod;}
int main(){
    // freopen("test.in","r",stdin);
    scanf("%d%d",&n,&m);J[0]=I[0]=I[1]=1;
    for(int i=2;i<=n+2*m;i++)I[i]=mod-1ll*mod/i*I[mod%i]%mod;
    for(int i=1;i<=n+2*m;i++)J[i]=1ll*J[i-1]*i%mod,I[i]=1ll*I[i-1]*I[i]%mod;
    // for(int i=1;i<=n;i++)printf("%d\n")
    printf("%d\n",C(n-1+2*m,2*m));
    return 0;
}