#include<bits/stdc++.h>
using namespace std;

int N,M,invM,W,invW,K;
const int p=998244353;
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
	scanf("%d%d%d",&N,&M,&K);invM=M;M=qpow(M,p-2);W=(1-M+p)%p;invW=qpow(W,p-2);
	fac[0]=fac[1]=ifac[0]=ifac[1]=inv[1]=1;
	for(int i=2;i<=K+1;i++)
		inv[i]=1LL*(p-p/i)*inv[p%i]%p,
		fac[i]=1LL*fac[i-1]*i%p,
		ifac[i]=1LL*ifac[i-1]*inv[i]%p;
	CN[0]=1;
	for(int i=1;i<=K+1;i++)
		CN[i]=1LL*CN[i-1]*(N-i+1)%p*inv[i]%p;
	if(N<=K+1){
		int ans=0,powM=1,powW=qpow(W,N);
		for(int i=0;i<=N;i++){
			ans=(ans+1LL*CN[i]*powM%p*powW%p*qpow(i,K)%p)%p,
			powM=1LL*powM*M%p,
			powW=1LL*powW*invW%p;
			if(W==0) powW=(i==N-1);
		}
		printf("%d\n",ans);
		return 0;
	}
	F[K]=1;
	int CC=1,powM=1;
	for(int i=K-1;~i;i--){
		CC=1LL*CC*(N-i-1)%p*inv[K-i]%p;
		powM=1LL*powM*(p-M)%p;
		F[i]=(1LL*F[i+1]*W%p+1LL*CC*powM%p)%p;
	}
	powM=1;int ans=0;
	for(int i=0;i<=K;i++){
		ans=(ans+1LL*CN[i]*qpow(i,K)%p*powM%p*F[i]%p)%p;
		powM=1LL*powM*M%p;
	}
	printf("%d\n",ans);
}