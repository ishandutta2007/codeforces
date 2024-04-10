#include <stdio.h>
#include <string.h>
int main(){
	int n,m,k;
	scanf("%d %d",&n,&m);
	if(m>n){printf("-1");return 0;}
	k=n/(2*m);
	if(2*m*k<n)k++;
	printf("%d",k*m);
}