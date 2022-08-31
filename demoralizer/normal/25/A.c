#include <stdio.h>
#include <string.h>
int main(){
	int n,t,a,b,c;
	scanf("%d",&n);
	scanf("%d %d %d",&a,&b,&c);
	a%=2;b%=2;c%=2;
	if(a==b&&b==c)
	for(int i=4;i<=n;i++){
		scanf("%d",&t);
		if(a!=t%2)
		{printf("%d",i);return 0;}
	}
	if(a==b)
	printf("3");
	else if(a==c)
	printf("2");
	else
	printf("1");
}