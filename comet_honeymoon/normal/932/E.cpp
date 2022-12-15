#include<bits/stdc++.h>
using namespace std;

int N,K;
const int p=1000000007,inv2=(p+1)/2;
int fac[5005],ifac[5005],inv[5005],CN[5005];
int F[5005];

int qpow(int a,int k){
	int ans=1;
	while(k){
		if(k&1) ans=1LL*ans*a%p;
		a=1LL*a*a%p;
		k>>=1;
	}
	return ans;
}

int main(){
	scanf("%d%d",&N,&K);
	fac[0]=fac[1]=ifac[0]=ifac[1]=inv[1]=1;
	for(int i=2;i<=K+1;i++)
		inv[i]=1LL*(p-p/i)*inv[p%i]%p,
		fac[i]=1LL*fac[i-1]*i%p,
		ifac[i]=1LL*ifac[i-1]*inv[i]%p;
	CN[0]=1;
	for(int i=1;i<=K+1;i++)
		CN[i]=1LL*CN[i-1]*(N-i+1)%p*inv[i]%p;
	if(N<=K+1){
		int ans=0;
		for(int i=0;i<=N;i++)
			ans=(ans+1LL*CN[i]*qpow(i,K)%p)%p;
		printf("%d\n",ans);
		return 0;
	}
	F[K]=1;
	int CC=1,W=1;
	for(int i=K-1;i;i--){
		CC=1LL*CC*(N-i-1)%p*inv[K-i]%p;
		W=1LL*W*(p-inv2)%p;
		F[i]=(1LL*F[i+1]*inv2%p+1LL*CC*W%p)%p;
	}
	int pow2=qpow(2,N),ans=0;
	for(int i=1;i<=K;i++){
		pow2=1LL*pow2*inv2%p;
		ans=(ans+1LL*CN[i]*qpow(i,K)%p*pow2%p*F[i]%p)%p;
	}
	printf("%d\n",ans);
}