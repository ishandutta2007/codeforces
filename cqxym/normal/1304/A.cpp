#include<stdio.h>
int main(){
	int t,x,y,a,b;
	scanf("%d",&t);
	for(register int i=0;i!=t;i++){
		scanf("%d%d%d%d",&x,&y,&a,&b);
		if((y-x)%(a+b)==0){
			printf("%d\n",(y-x)/(a+b));
		}else{
			puts("-1");
		}
	}
	return 0;
}