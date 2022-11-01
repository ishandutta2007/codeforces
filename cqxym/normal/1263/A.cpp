#include<stdio.h>
int main(){
	int t,a,b,c;
	scanf("%d",&t);
	for(register int i=0;i<t;i++){
		scanf("%d%d%d",&a,&b,&c);
		if(a>=b+c){
			printf("%d\n",b+c);
		}else if(b>=a+c){
			printf("%d\n",a+c);
		}else if(c>=a+b){
			printf("%d\n",a+b);
		}else{
			printf("%d\n",a+b+c>>1);
		}
	}
	return 0;
}