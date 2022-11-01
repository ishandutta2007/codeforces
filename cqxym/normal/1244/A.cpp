#include<stdio.h>
int main(){
	int t,a,b,c,d,k;
	scanf("%d",&t);
	for(register int i=0;i<t;i++){
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		a=(a+c-1)/c;
		b=(b+d-1)/d;
		if(a+b>k){
			puts("-1");
		}else{
			printf("%d %d\n",a,b);
		}
	}
	return 0;
}