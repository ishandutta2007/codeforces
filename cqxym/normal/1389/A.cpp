#include<stdio.h>
int main(){
	int t,l,r;
	scanf("%d",&t);
	for(register int i=0;i!=t;i++){
		scanf("%d%d",&l,&r);
		if(r<l<<1){
			puts("-1 -1");
		}else{
			printf("%d %d\n",l,l<<1);
		}
	}
	return 0;
}