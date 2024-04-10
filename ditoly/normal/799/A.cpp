#include<cstdio>
int main()
{
	int n,t,k,d,a,b,x;
	scanf("%d%d%d%d",&n,&t,&k,&d);
	for(a=0;a/t*k<n;++a);
	for(b=d;b/t*k+(b-d)/t*k<n;++b);
	puts(b<a?"YES":"NO");
}