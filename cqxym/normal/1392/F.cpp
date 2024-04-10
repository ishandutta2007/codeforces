#include<stdio.h>
#define R register int
#define L long long
int main(){
	int n;
	scanf("%d",&n);
	L s=0,x;
	for(R i=0;i!=n;i++){
		scanf("%lld",&x);
		s+=x-i;
	}
	L d=s/n;
	int e=s%n;
	for(R i=0;i!=e;i++){
		printf("%lld ",d+i+1);
	}
	for(R i=e;i!=n;i++){
		printf("%lld ",d+i);
	}
	return 0;
}