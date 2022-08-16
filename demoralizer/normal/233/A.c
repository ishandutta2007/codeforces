#include <stdio.h>
#include <string.h>
int main(){
	int n;
	scanf("%d",&n);
	if(n%2){printf("-1");return 0;}
	for(int i=1;i<=n;i++){
		if(i%2==0)printf("%d ",i-1);
		else printf("%d ",i+1);
	}	
}