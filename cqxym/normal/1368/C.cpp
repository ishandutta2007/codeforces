#include<stdio.h>
#define R register int
int main(){
	int n;
	scanf("%d",&n);
	if((n&1)==0){
		printf("%d\n2 0\n3 0\n4 0\n4 1\n4 2\n4 %d\n4 %d\n4 %d\n3 %d\n2 %d\n2 %d",7*n+8,n<<1,n<<1|1,n+1<<1,n+1<<1,n+1<<1,n<<1|1);
		for(R i=0;i!=n;i++){
			printf("\n1 %d\n2 %d\n2 %d\n3 %d",i+1<<1,i<<1|1,i+1<<1,i+1<<1);
		}
		for(R i=1;i!=n;i++){
			if((i&1)==1){
				printf("\n0 %d\n0 %d\n0 %d",i<<1,i<<1|1,i+1<<1);
			}else{
				printf("\n4 %d\n4 %d\n4 %d",i<<1,i<<1|1,i+1<<1);
			}
		}
	}else{
		printf("%d\n2 0\n3 0\n4 0\n4 1\n4 2\n0 %d\n0 %d\n0 %d\n1 %d\n2 %d\n2 %d",7*n+8,n<<1,n<<1|1,n+1<<1,n+1<<1,n+1<<1,n<<1|1);
		for(R i=0;i!=n;i++){
			printf("\n1 %d\n2 %d\n2 %d\n3 %d",i+1<<1,i<<1|1,i+1<<1,i+1<<1);
		}
		for(R i=1;i!=n;i++){
			if((i&1)==1){
				printf("\n0 %d\n0 %d\n0 %d",i<<1,i<<1|1,i+1<<1);
			}else{
				printf("\n4 %d\n4 %d\n4 %d",i<<1,i<<1|1,i+1<<1);
			}
		}
	}
	return 0;
}