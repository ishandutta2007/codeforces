#include<cstdio>
#define max(a,b)a>b?a:b
int a,b,c,d,e,f,g,h;
int main(){
	scanf("%d%d%d",&a,&b,&c);
	d=max(a+b,a*b);
	e=max(c+b,c*b);
	f=max(d+c,d*c);
	g=max(e+a,e*a);
	h=max(f,g);
	printf("%d",h);
	return 0;
}