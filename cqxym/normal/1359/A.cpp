#include<stdio.h>
int main(){
	int t,n,m,k;
	scanf("%d",&t);
	for(register int i=0;i!=t;i++){
		scanf("%d%d%d",&n,&m,&k);
		int x=n/k,y;
		x=x>m?m:x;
		y=(m-x+k-2)/(k-1);
		printf("%d\n",x-y);
	}
	return 0;
}