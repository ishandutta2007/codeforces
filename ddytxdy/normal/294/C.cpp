#include<bits/stdc++.h>
using namespace std;
const int N=1010,mod=1e9+7;
int n,m,a[N],ans=1,J[N],I[N],pw[N];
int C(int n,int m){return 1ll*J[n]*I[m]%mod*I[n-m]%mod;}
int main(){
	scanf("%d%d",&n,&m);J[0]=I[0]=I[1]=pw[0]=1;
	for(int i=2;i<=n;i++)I[i]=mod-1ll*mod/i*I[mod%i]%mod;
	for(int i=1;i<=n;i++)
		J[i]=1ll*J[i-1]*i%mod,
		I[i]=1ll*I[i-1]*I[i]%mod,
		pw[i]=2*pw[i-1]%mod;
	for(int i=1;i<=m;i++)scanf("%d",&a[i]);
	sort(a+1,a+m+1);
	for(int i=2;i<=m;i++){
		int p=a[i]-a[i-1]-1;
		if(p)ans=1ll*ans*pw[p-1]%mod*I[p]%mod;
	}
	ans=1ll*ans*I[a[1]-1]%mod*I[n-a[m]]%mod*J[n-m]%mod;
	printf("%d\n",ans);
	return 0;
}