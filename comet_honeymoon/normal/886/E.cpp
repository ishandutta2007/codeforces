#include<bits/stdc++.h>
using namespace std;

const int p=1000000007;

int N,K,ans;
int F[1000005],inv[1000005],fac[1000005],sum;

int main(){
	scanf("%d%d",&N,&K); 
	F[0]=1;fac[0]=1;ans=N;sum=1;
	for(int i=1;i<=N;i++){
		inv[i]=(i==1)?1:1LL*(p-p/i)*inv[p%i]%p;
		fac[i]=1LL*fac[i-1]*i%p;
		F[i]=1LL*sum*inv[i]%p;
		ans=(ans-F[i-1]+p)%p;
		sum=(sum+F[i])%p;
		if(i-K>=0) sum=(sum-F[i-K]+p)%p;
	}
	printf("%d\n",1LL*fac[N-1]*ans%p);
}