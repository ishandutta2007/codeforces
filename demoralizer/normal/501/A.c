#include <stdio.h>
#include <string.h>
int x(int a,int b){
	return a>b?a:b;
}
int main(){
	int a,b,c,d,m,v;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	m=x(3*a/10,a-c*a/250);
	v=x(3*b/10,b-d*b/250);
	if(m>v)
	printf("Misha");
	else if(v>m)
	printf("Vasya");
	else
	printf("Tie");
}