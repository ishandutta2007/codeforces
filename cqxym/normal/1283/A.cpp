#include<stdio.h>
int main(){
	int t,a,b;
	scanf("%d",&t);
	for(register int i=0;i!=t;i++){
		scanf("%d%d",&a,&b);
		printf("%d\n",1440-60*a-b);
	}
	return 0;
}