#include<stdio.h>
#define R register int
#define L long long
#define N 500001
#define P 998244353
int fac[N],invfac[N];
inline GetInv(int x){
	int b=P-2,s=1;
	while(b!=0){
		if((b&1)==1){
			s=(L)s*x%P;
		}
		x=(L)x*x%P;
		b>>=1;
	}
	return s;
}
inline L Calc(int n,int m){
	if(n<m){
		return 0;
	}
	return (L)fac[n]*invfac[n-m]%P*invfac[m]%P;
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	fac[0]=invfac[0]=1;
	for(R i=1;i<=n;i++){
		fac[i]=(L)fac[i-1]*i%P;
	}
	invfac[n]=GetInv(fac[n]);
	for(R i=n-1;i!=0;i--){
		invfac[i]=(L)invfac[i+1]*(i+1)%P;
	}
	int ans=0;
	for(R i=1;i<=n;i++){
		int t=n/i-1;
		L hg=Calc(t,k-1);
		ans=(hg+ans)%P;
	}
	printf("%d",ans);
	return 0;
}