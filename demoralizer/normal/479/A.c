#include <stdio.h>
#include <string.h>
int main(){
	int a,b,c,m=0,t;
	scanf("%d\n%d\n%d",&a,&b,&c);
	t=a+b+c;if(t>m)m=t;
	t=a+b*c;if(t>m)m=t;
	t=a*b+c;if(t>m)m=t;
	t=a*b*c;if(t>m)m=t;
	t=(a+b)*c;if(t>m)m=t;
	t=a*(b+c);if(t>m)m=t;
	printf("%d",m);
}