#include<stdio.h>
int main(){
	int t,n;
	scanf("%d",&t);
	for(register int i=0;i<t;i++){
		scanf("%d",&n);
		if(n<4){
			printf("%d\n",4-n);
		}else if((n&1)>0){
			puts("1");
		}else{
			puts("0");
		}
	}
	return 0;
}