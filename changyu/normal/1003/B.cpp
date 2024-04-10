#include<cstdio>
int a[2],x,n;char s[201];
int out(char a,int c){for(;c--;)putchar(a);}
int main()
{
	scanf("%d%d%d",a,a+1,&x);
	n=a[0]>a[1]?0:1;
	if(x-1&1) out(n+48,a[n]-(x-1>>1)-1),out((n^1)+48,a[n^1]-(x-1>>1));
	else out(n+48,a[n]-(x-1>>1)),out((n^1)+48,a[n^1]-(x-1>>1));
	for(int i=1,k=n;i<x;i++)
	  putchar(k+48),k^=1;
	return 0;
}