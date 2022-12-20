#include<cstdio>
#include<cmath>
#define ld double
int n,h;
int main()
{
	scanf("%d%d",&n,&h);
	for(int i=1; i<n;++i)printf("%.15lf ",sqrt((ld)((long long)h*h*i)/n));
}