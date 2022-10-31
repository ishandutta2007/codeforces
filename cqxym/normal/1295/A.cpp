#include<stdio.h>
#define R register int
int main(){
	int t,n;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		scanf("%d",&n);
		if((n&1)==1){
			n=n-3>>1;
			putchar('7');
		}else{
			n>>=1;
		}
		for(R j=0;j!=n;j++){
			putchar('1');
		}
		puts("");
	}
	return 0;
}