#include<stdio.h>
int main(){
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if(a+b==c+d||a+c==b+d||a+d==b+c||a+b+c==d||a+c+d==b||b+c+d==a||a+b+d==c){
		printf("yEs");
	}else{
		printf("nO");
	}
	return 0;
}