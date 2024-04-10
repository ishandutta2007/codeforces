#include <stdio.h>
#include <string.h>
int main(){
	int n,m,a,b,c;
	scanf("%d %d %d %d",&n,&m,&a,&b);
	if(a*m<=b){
	printf("%d",a*n);return 0;
	}
	c=n/m*b;
	if(a*(n%m)>b)c+=b;
	else c+=a*(n%m);
	printf("%d",c);
}