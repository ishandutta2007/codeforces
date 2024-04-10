#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int fac[1000002],_fac[1000002];
int ksm(int x,int y){
	int t=1;
	while(y){
		if(y&1)t=1LL*t*x%mod;
		x=1LL*x*x%mod;
		y>>=1;
	}
	return t;
}
int C(int n,int m){
	if(n<m)return 0;
	return 1LL*fac[n]*_fac[n-m]%mod*_fac[m]%mod;
}
int main(){
	fac[0]=_fac[0]=1;
	int i,n,j,ans=0;
	for(i=1;i<=1000000;++i){
		fac[i]=1LL*i*fac[i-1]%mod;
		_fac[i]=ksm(fac[i],mod-2);
	}
	scanf("%d",&n);
	/*for(i=2;i<n;++i){
		memset(f[i&3],0,sizeof(f[i&3]));
		for(j=0;j<=i;++j){
			f[i&3][j][0]=(ll)j*(f[(i+3)&3][j-1][1]+f[(i+2)&3][j-1][1])%mod;
			f[i&3][j][1]=(ll)j*(f[(i+3)&3][j-1][0]+f[(i+2)&3][j-1][0])%mod;
		}
		//printf("%d %d\n",f[i&3][i-1][0]-f[i&3][i-1][1],f[i&3][i][0]-f[i&3][i][1]);
	}
	for(i=1;i<n;i++)ans=(ans+f[(n+3)&3][i][0])%mod;
	printf("%lld\n",2LL*n%mod*ans%mod);
	for(i=1;i<n;i+=2)printf("%d ",1LL*f[(n+3)&3][i][0]*_fac[i]%mod);*/
	ans=0;
	for(i=1;i<=n;i+=2){
		ans=(ans+1LL*fac[i]*C(i+1,n-i-1)%mod)%mod;
	}
	printf("%lld\n",2LL*n*ans%mod);
	return 0;
}