#include<stdio.h>
#define R register int
#define L long long
int u[10];
char t[10]={'c','o','d','e','f','o','r','c','e','s'};
int main(){
	L k;
	scanf("%lld",&k);
	L pie=1;
	int r;
	for(R i=1;i<41;i++){
		pie=1;
		for(R j=0;j!=10;j++){
			pie*=i;
		}
		if(pie>=k){
			r=i;
			break;
		}
	}
	for(R i=0;i!=10;i++){
		u[i]=r;
	}
	for(R i=0;i!=10;i++){
		if(pie/r*(r-1)>=k){
			u[i]--;
			pie=pie/r*(r-1);
		}else{
			break;
		}
	}
	for(R i=0;i!=10;i++){
		for(R j=0;j!=u[i];j++){
			printf("%c",t[i]);
		}
	}
	return 0;
}