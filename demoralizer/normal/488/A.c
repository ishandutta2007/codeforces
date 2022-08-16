#include <stdio.h>
#include <string.h>
int ch(int n){
	if(n<0)n*=-1;
	while(n!=0){
		if((n%10)==8) return 1;
		n/=10;
	}
	return 0;
}
int main(){
	int a,b;
	scanf("%d",&a);
	for(b=1;b<=20;b++){
		if(ch(a+b)){printf("%d",b);break;}
	}
}