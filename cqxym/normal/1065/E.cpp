#include<stdio.h>
#define L long long
#define P 998244353
inline int PowMod(int x,int y){
	int res=1;
	while(y!=0){
		if((y&1)==1){
			res=(L)res*x%P;
		}
		y>>=1;
		x=(L)x*x%P;
	}
	return res;
}
int main(){
	int n,m,k,a=0,b,ans=1,x;
	scanf("%d%d%d",&n,&m,&k);
	for(register int i=0;i!=m;i++){
		scanf("%d",&b);
		x=PowMod(k,b-a);
		ans=((1ll+x)*x>>1)%P*ans%P;
		a=b;
	}
	printf("%d",(L)ans*PowMod(k,n-(b<<1))%P);
	return 0;
}