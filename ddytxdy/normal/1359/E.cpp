#include<bits/stdc++.h>
using namespace std;
const int N=5e5+50,mod=998244353;
int n,k,J[N],I[N],ans;
int C(int n,int m){return n<m?0:1ll*J[n]*I[m]%mod*I[n-m]%mod;}
int main(){
    scanf("%d%d",&n,&k);J[0]=I[0]=I[1]=1;
    for(int i=2;i<N;i++)I[i]=mod-1ll*mod/i*I[mod%i]%mod;
    for(int i=1;i<N;i++)J[i]=1ll*J[i-1]*i%mod,I[i]=1ll*I[i-1]*I[i]%mod;
    for(int i=1;i<=n;i++)(ans+=C(n/i-1,k-1))%=mod;
    cout<<ans;
    return 0;
}