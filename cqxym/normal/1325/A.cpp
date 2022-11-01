#include<stdio.h>
#define R register int
int main(){
	int t,x;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		scanf("%d",&x);
		printf("1 %d\n",x-1);
	}
	return 0;
}