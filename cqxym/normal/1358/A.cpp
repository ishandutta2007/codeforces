#include<stdio.h>
int main(){
	int t,n,m;
	scanf("%d",&t);
	for(register int i=0;i!=t;i++){
		scanf("%d%d",&n,&m);
		printf("%d\n",n*m+1>>1);
	}
	return 0;
}