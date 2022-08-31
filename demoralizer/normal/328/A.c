#include <stdio.h>
#include <string.h>
int main(){
	int a,b,c,d,e;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	if(((a-b)==(b-c))&&((b-c)==(c-d)))
		{printf("%d",d+b-a);return 0;}
	if(((b*b)==(a*c))&&((c*c)==(b*d)))
	{
		e=d*d/c;
		if((d*d)==(c*e))
		{printf("%d",d*d/c);return 0;}
	}
	printf("42");
}