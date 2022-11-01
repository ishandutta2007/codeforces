#include<stdio.h>
int main(){
	int n,mx,x;
	scanf("%d%d",&n,&mx);
	printf("%d",mx);
	for(register int i=1;i!=n;i++){
		scanf("%d",&x);
		x+=mx;
		printf(" %d",x);
		mx=mx>x?mx:x;
	}
	return 0;
}