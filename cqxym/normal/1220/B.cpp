#include<stdio.h>
#include<cmath>
#define R register int
int m[1001];
int main(){
	int n,x;
	scanf("%d",&n);
	for(R i=0;i<n;i++){
		scanf("%d",&m[i]);
	}
	scanf("%d%d%d",&x,&x,&x);
	x=sqrt(1ll*m[1]*m[2]/x);
	printf("%d",x);
	for(R i=1;i<n;i++){
		printf(" %d",m[i]/x);
	}
	return 0;
}