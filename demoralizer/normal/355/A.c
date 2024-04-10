#include <stdio.h>
#include <string.h>
int main(){
	int k,d;
	scanf("%d %d",&k,&d);
	if(d){
		printf("%d",d);
		for(int i=1;i<k;i++) printf("0");
	}
	else if(k==1) printf("0");
	else printf("No solution");
}