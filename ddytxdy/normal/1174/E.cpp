#include<bits/stdc++.h>
using namespace std;
const int N=1e6+50,mod=1e9+7;
int n,k=0,ans=1,J[N],I[N],a[60];
int P(int n,int m){return 1ll*J[n]*I[n-m]%mod;}
int power(int x,int y){
	int z=1;
	for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;
	return z;
}
int main(){
	scanf("%d",&n);J[0]=1;
	for(int i=1;i<=n;i++)J[i]=1ll*J[i-1]*i%mod;
	I[n]=power(J[n],mod-2);
	for(int i=n;i;i--)I[i-1]=1ll*I[i]*i%mod;
	while((1<<k+1)<=n)k++;
	for(int i=0;i<=k+1;i++)a[i]=1<<i;
	for(int i=k,d;~i;i--){
		int x=n/a[i]-n/a[i+1];
		ans=1ll*ans*x%mod*P(n-n/a[i+1]-1,x-1)%mod;
	}
	if(n>1&&(1<<k-1)*3<=n){
		for(int j=1;j<=k;j++){
			for(int i=0;i<j;i++)a[i]=1<<i;
			a[j]=a[j-1]*3;
			for(int i=j+1;i<=k+1;i++)a[i]=a[i-1]<<1;
			int dat=1;
			for(int i=k,d;~i;i--){
				int x=n/a[i]-n/a[i+1];
				dat=1ll*dat*x%mod*P(n-n/a[i+1]-1,x-1)%mod;
			}
			(ans+=dat)%=mod;
		}
	}
	printf("%d\n",ans);
	return 0;
}