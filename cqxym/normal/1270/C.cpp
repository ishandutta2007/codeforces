#include<stdio.h>
#define R register int
inline void Solve(){
	int n,x,a=0;
	long long s=0;
	scanf("%d",&n);
	for(R i=0;i!=n;i++){
		scanf("%d",&x);
		s+=x;
		a^=x;
	}
	printf("2\n%d ",a);
	printf("%lld\n",s+a);
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}