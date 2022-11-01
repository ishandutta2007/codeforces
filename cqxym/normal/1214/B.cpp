#include<stdio.h>
int main(){
	int a,b,c,d;
	scanf("%d%d%d",&a,&b,&c);
	d=a+b-c;
	if(a>b){
		a=b;
	}
	if(a>c){
		a=c;
	}
	if(a>d){
		a=d;
	}
	printf("%d",a+1);
	return 0;
}