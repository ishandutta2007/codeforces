#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50,mod=998244353,inv2=499122177;
int n,m,J[N],I[N],ans,pw[N];
int C(int n,int m){return 1ll*J[n]*I[m]%mod*I[n-m]%mod;}
int main(){
	scanf("%d%d",&n,&m);J[0]=I[0]=I[1]=pw[0]=1;
	for(int i=2;i<=m;i++)I[i]=mod-1ll*mod/i*I[mod%i]%mod;
	for(int i=1;i<=m;i++)J[i]=1ll*J[i-1]*i%mod,I[i]=1ll*I[i-1]*I[i]%mod,pw[i]=2*pw[i-1]%mod;
	ans=1ll*C(m,n-1)*pw[n-2]%mod*(n-2)%mod*inv2%mod;
	cout<<ans;
	return 0;
}