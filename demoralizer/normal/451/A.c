#include <stdio.h>
#include <string.h>
int main(){
	int m,n,a;
	scanf("%d %d",&m,&n);
	a=(m<n)?m:n;
	if(a%2)
	printf("Akshat");
	else
	printf("Malvika");
}