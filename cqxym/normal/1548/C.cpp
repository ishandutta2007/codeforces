#include<stdio.h>
#define R register int
#define L long long
#define N 3000004
#define P 1000000007
inline int GetInv(int x){
	int res=1,y=P-2;
	while(y!=0){
		if((y&1)==1){
			res=(L)res*x%P;
		}
		y>>=1;
		x=(L)x*x%P;
	}
	return res;
}
int invf[N],a[N],b[N];
int main(){
	int n,q,fac=1;
	scanf("%d%d",&n,&q);
	n=n*3+3;
	for(R i=2;i<=n;i++){
		fac=(L)fac*i%P;
	}
	invf[n]=GetInv(fac);
	for(R i=n;i!=0;i--){
		invf[i-1]=(L)invf[i]*i%P;
	}
	for(R i=1;i<=n;i++){
		a[i-1]=(L)fac*invf[i]%P*invf[n-i]%P;
	}
	for(R i=n-3;i!=-1;i--){
		b[i]=a[i+2];
		a[i+1]=(a[i+1]-3ll*b[i])%P;
		a[i]=(a[i]-3ll*b[i])%P;
	}
	for(R i=0;i!=q;i++){
		scanf("%d",&n);
		printf("%d\n",b[n]<0?b[n]+P:b[n]);
	}
	return 0;
}