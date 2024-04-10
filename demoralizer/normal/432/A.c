#include <stdio.h>
#include <string.h>
int main(){
	int n,k,c=0,t;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&t);
		if(t+k<=5)c++;
	}
	printf("%d",c/3);
}