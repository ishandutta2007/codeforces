#include<stdio.h>
#define L long long
int main(){
	int t,a,b;
	scanf("%d",&t);
	for(register int i=0;i!=t;i++){
		scanf("%d%d",&a,&b);
		if(b<9){
			puts("0");
		}else if(b<99){
			printf("%d\n",a);
		}else if(b<999){
			printf("%d\n",a<<1);
		}else if(b<9999){
			printf("%lld\n",(L)a*3);
		}else if(b<99999){
			printf("%lld\n",(L)a<<2);
		}else if(b<999999){
			printf("%lld\n",(L)a*5);
		}else if(b<9999999){
			printf("%lld\n",(L)a*6);
		}else if(b<99999999){
			printf("%lld\n",(L)a*7);
		}else if(b<999999999){
			printf("%lld\n",(L)a<<3);
		}else{
			printf("%lld\n",(L)a*9);
		}
	}
	return 0;
}