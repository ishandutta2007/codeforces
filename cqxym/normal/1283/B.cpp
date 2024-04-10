#include<stdio.h>
int main(){
	int t,a,b;
	scanf("%d",&t);
	for(register int i=0;i!=t;i++){
		scanf("%d%d",&a,&b);
		if(a%b<=(b>>1)){
			printf("%d\n",a);
		}else{
			printf("%d\n",a/b*b+(b>>1));
		}
	}
	return 0;
}