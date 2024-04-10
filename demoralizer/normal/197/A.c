#include <stdio.h>
#include <string.h>
int main(){
	int a,b,r;
	scanf("%d %d %d",&a,&b,&r);
	r*=2;
	if(r>a||r>b)
		printf("Second");
	else printf("First");
}