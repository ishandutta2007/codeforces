#include<stdio.h>
#define R register int
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	printf("%d\n",(n+1)*(m+1)-4);
	for(R i=1;i!=n;i++){
		putchar('D');
	}
	for(R i=1;i!=m;i++){
		putchar('R');
	}
	for(R i=1;i!=m;i++){
		putchar('L');
	}
	for(R i=1;i!=n;i++){
		putchar('U');
		for(R j=1;j!=m;j++){
			if((i&1)==1){
				putchar('R');
			}else{
				putchar('L');
			}
		}
	}
	return 0;
}