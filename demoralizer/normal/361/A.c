#include <stdio.h>
#include <string.h>
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ",k*(i==j));
		}
		printf("\n");
	}
}