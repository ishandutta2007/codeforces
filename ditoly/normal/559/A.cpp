#include<cstdio>
inline int f(int x){return x*x;}
int main()
{
	int a[6],i;
	for(i=0;i<6;++i)scanf("%d",&a[i]);
	printf("%d",f(a[0]+a[1]+a[5])-f(a[1])-f(a[3])-f(a[5]));
}