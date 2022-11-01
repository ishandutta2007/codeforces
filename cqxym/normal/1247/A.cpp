#include<stdio.h>
#define R register int
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	if(a==9&&b==1){
		printf("9 10");
	}else{
		if(a>b||a<b-1){
			printf("-1");
		}else{
			if(a==b){
				printf("%d1 %d2",a,b);
			}else{
				printf("%d %d",a,b);
			}
		}
	}
	return 0;
}