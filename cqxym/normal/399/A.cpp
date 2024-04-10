#include<stdio.h>
int main(){
	int n,p,k,l;
	scanf("%d%d%d",&n,&p,&k);
	if(p-k<2){
		l=1;
	}else{
		printf("<< ");
		l=p-k;
	}
	for(register int i=l;i!=p;i++){
		printf("%d ",i);
	}
	printf("(%d)",p);
	if(p+k>n){
		l=n;
	}else{
		l=p+k;
	}
	for(register int i=p+1;i<=l;i++){
		printf(" %d",i);
	}
	if(p+k<n){
		printf(" >>");
	}
	return 0;
}