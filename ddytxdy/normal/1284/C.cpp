#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=3e5+50;
int n,ans,mod,J[N],I[N];
int C(int n,int m){return 1ll*J[n]*I[m]%mod*I[n-m]%mod;}
int main(){
	scanf("%d%d",&n,&mod);J[0]=I[0]=I[1]=1;
	for(int i=2;i<=n;i++)I[i]=mod-1ll*mod/i*I[mod%i]%mod;
	for(int i=1;i<=n;i++)J[i]=1ll*J[i-1]*i%mod,I[i]=1ll*I[i-1]*I[i]%mod;
	for(int i=1;i<=n;i++)
		ans=(ans+1ll*(n-i+1)*(n-i+1)%mod*J[n-i]%mod*J[i])%mod;
	cout<<ans;
	return 0;
}