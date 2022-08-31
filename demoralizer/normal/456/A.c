#include <stdio.h>
#include <string.h>
int main(){
	int n;
	scanf("%d",&n);
	int a,b;
	for(int i=0;i<n;i++){
		scanf("%d %d",&a,&b);
		if(a!=b)
		{printf("Happy Alex");return 0;}
	}
	printf("Poor Alex");
}