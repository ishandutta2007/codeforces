#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50,mod=998244353,inv2=499122177;
int n,k,a[N],pw[N],dat=1,ans,m,J[N],I[N];
int C(int n,int m){return 1ll*J[n]*I[m]%mod*I[n-m]%mod;}
int main(){
    scanf("%d%d",&n,&k);m=n;I[1]=I[0]=J[0]=pw[0]=1;
    for(int i=2;i<=n;i++)I[i]=mod-1ll*mod/i*I[mod%i]%mod;
    for(int i=1;i<=n;i++)J[i]=1ll*J[i-1]*i%mod,I[i]=1ll*I[i-1]*I[i]%mod,pw[i]=2*pw[i-1]%mod;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<n;i++)if(a[i]==a[i+1])dat=1ll*dat*k%mod,m--;
    if(a[1]==a[n])dat=1ll*dat*k%mod,m--;
    for(int i=0,now=1;i<m;i++,now=1ll*now*(k-2)%mod){
        int j=m-i;
        if(j&1)ans=(ans+1ll*pw[j-1]*now%mod*C(m,i))%mod;
        else ans=(ans+1ll*(pw[j]-C(j,j>>1))*inv2%mod*now%mod*C(m,i))%mod;
    }
    printf("%d\n",(1ll*ans*dat%mod+mod)%mod);
    return 0;
}