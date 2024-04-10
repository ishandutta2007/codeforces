#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;
typedef long long LL;
const LL md=1000000007;
int n;
const int MX=211111;
LL a[MX];
LL inv[MX],fac[MX],facinv[MX];
LL k[MX];
#define C(x,y) (fac[x]*facinv[y]%md*facinv[x-y]%md)

LL O[MX],E[MX],A[MX];
void wk(){
	inv[1]=1;
	for(int i=2;i<=n;i++)inv[i]=inv[md%i]*(md-md/i)%md;
	fac[0]=facinv[0]=1;
	for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%md;
	for(int i=1;i<=n;i++)facinv[i]=facinv[i-1]*inv[i]%md;
	if(n&1){
		for(int i=1;i<=n-2;i+=2)O[i]=E[i]=C((n-2)/2,i/2);
		for(int i=1;i<=n-2;i+=2)O[i+1]=O[i],E[i+1]=md-E[i];
		if(n%4==1){
			for(int i=2;i<=n;i++)O[i]=(O[i]+md-E[i-1])%md;
		}else{
			for(int i=2;i<=n;i++)O[i]=(O[i]+E[i-1])%md;
		}
		LL ans=0LL;
		for(int i=1;i<=n;i++)ans=(ans+O[i]*a[i]%md)%md;
		printf("%lld\n",ans);
	}else{
		for(int i=1;i<=n-1;i+=2)O[i]=E[i]=C((n-1)/2,i/2);
		if(n%4==0){
			for(int i=1;i<=n-1;i+=2)O[i+1]=md-E[i];
		}else{
			for(int i=1;i<=n-1;i+=2)O[i+1]=E[i];
		}
		LL ans=0LL;
		for(int i=1;i<=n;i++)ans=(ans+O[i]*a[i]%md)%md;
		printf("%lld\n",ans);
	}
}
void bf(){
	LL k=1;
	for(int i=n-1;i;i--)
		for(int j=1;j<=i;j++)
			a[j]=(a[j]+md+k*a[j+1])%md,k=-k;
	printf("%lld\n",a[1]);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	if(n<=5000)bf();else wk();
	
	return 0;
}