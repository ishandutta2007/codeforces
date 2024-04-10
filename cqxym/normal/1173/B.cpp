#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	printf("%d",n+2>>1);
	for(register int i=0;i!=n;i++){
		printf("\n%d %d",i+2>>1,i+3>>1);
	}
	return 0;
}