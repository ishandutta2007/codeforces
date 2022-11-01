#include<stdio.h>
#define R register int
int Gcd(int x,int y){
	return y>0?Gcd(y,x%y):x;
}
int main(){
	int t,a,b;
	scanf("%d",&t);
	for(R i=0;i<t;i++){
		scanf("%d%d",&a,&b);
		if(Gcd(a,b)==1){
			puts("Finite");
		}else{
			puts("Infinite");
		}
	}
	return 0;
}