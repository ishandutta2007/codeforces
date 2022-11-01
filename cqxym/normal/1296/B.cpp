#include<stdio.h>
#define R register int
int main(){
	int t,s,n;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		scanf("%d",&n);
		s=0;
		while(n>=10){
			s+=n-n%10;
			n=n/10+n%10;
		}
		printf("%d\n",s+n);
	}
	return 0;
}