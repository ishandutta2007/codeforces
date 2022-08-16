#include <stdio.h>
#include <math.h>
int main(){
	long long int a,b,c,d;
	scanf("%I64d %I64d %I64d",&a,&b,&c);
	d=(long long int)sqrt(a*b*c);
	if(d*d!=a*b*c)d++;
	printf("%I64d",4*(d/a+d/b+d/c));
}