#include<stdio.h>
#define R register int
#define L long long
#define P 998244353
int f[200001];
inline int Pow(int a,int b){
	int s=1;
	while(b>0){
		if((b&1)==1){
			s=(L)s*a%P;
		}
		b>>=1;
		a=(L)a*a%P;
	}
	return s;
}
inline int C(int x,int y){
	return x<y?0:(L)f[x]*Pow(f[y],P-2)%P*Pow(f[x-y],P-2)%P;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	f[0]=1;
	for(R i=1;i<=2e5;i++){
		f[i]=(L)f[i-1]*i%P;
	}
	int ans=0;
	for(R i=1;i!=m;i++){
		ans=(ans+C(i,n-2))%P;
	}
	printf("%d",(L)ans*Pow(2,n-3)%P*(n-2)%P);
	return 0;
}