#include <stdio.h>
#include <string.h>
int main(){
	int n,d,s=0,t;
	scanf("%d %d",&n,&d);
	for(int i=0;i<n;i++){
		scanf("%d",&t);
		s+=t;
	}
	if((s+(n-1)*10)>d){
		printf("-1");return 0;
	}
	printf("%d",(d-s)/5);
}