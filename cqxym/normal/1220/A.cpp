#include<stdio.h>
#define R register int
int main(){
	int l,a=0,b=0;
	scanf("%d\n",&l);
	char c;
	for(R i=0;i<l;i++){
		c=getchar();
		if(c=='z'){
			a++;
		}else if(c=='n'){
			b++;
		}
	}
	for(R i=0;i<b;i++){
		printf("1 ");
	}
	for(R i=0;i<a;i++){
		printf("0 ");
	}
	return 0;
}