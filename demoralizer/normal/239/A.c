#include <stdio.h>
#include <string.h>
int main(){
	int y,k,n,i,c=1;
	scanf("%d %d %d",&y,&k,&n);
	i=y/k+1;
	while(i*k<=n){
		c=0;
		printf("%d ",k*i-y);
		i++;
	}
	if(c) printf("-1");
}