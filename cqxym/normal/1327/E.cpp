#include<stdio.h>
#define P 998244353
#define R register int
#define L long long
int f[200000];
inline GetF(int x){
	return x<0?1:f[x];
}
int main(){
	int n;
	scanf("%d",&n);
	f[0]=1;
	for(R i=1;i!=n;i++){
		f[i]=10ll*f[i-1]%P;
	}
	for(R i=1;i!=n;i++){
		int x=n-i-1,s=0;
		if(x>0){
			s=810ll*GetF(n-i-2)%P*x%P;
		}
		s=(s+180ll*GetF(x)%P)%P;
		printf("%d ",s);
	}
	printf("10");
	return 0;
}