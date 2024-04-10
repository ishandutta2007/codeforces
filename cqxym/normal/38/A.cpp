#include<stdio.h>
#define R register int
int d[101];
int main(){
	int n,a,b,s=0;
	scanf("%d",&n);
	for(R i=1;i!=n;i++){
		scanf("%d",d+i);
	}
	scanf("%d%d",&a,&b);
	for(R i=a;i!=b;i++){
		s+=d[i];
	}
	printf("%d",s);
	return 0;
}