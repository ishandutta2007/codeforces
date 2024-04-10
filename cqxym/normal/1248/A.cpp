#include<stdio.h>
#define R register int
int main(){
	int t,c11,c12,c21,c22,n,x;
	scanf("%d",&t);
	for(R i=0;i<t;i++){
		scanf("%d",&n);
		c11=c12=c21=c22=0;
		for(R j=0;j<n;j++){
			scanf("%d",&x);
			if(x%2==0){
				c11++;
			}else{
				c12++;
			}
		}
		scanf("%d",&n);
		for(R j=0;j<n;j++){
			scanf("%d",&x);
			if(x%2==0){
				c21++;
			}else{
				c22++;
			}
		}
		printf("%lld\n",1ll*c11*c21+1ll*c22*c12);
	}
	return 0;
}