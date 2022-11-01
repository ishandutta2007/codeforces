#include<stdio.h>
#define R register int
int main(){
	int n,p,m;
	scanf("%d%d",&n,&p);
	for(R i=1;i<31;i++){
		m=n-i*p;
		if(m<i){
			continue;
		}
		int s=0;
		while(m>0){
			s+=m&1;
			m>>=1;
		}
		if(s<=i){
			printf("%d\n",i);
			return 0;
		}
	}
	printf("-1");
	return 0;
}