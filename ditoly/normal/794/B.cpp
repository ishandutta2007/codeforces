#include<cstdio>
#include<cmath>
int main()
{
	int n,h,i;
	scanf("%d%d",&n,&h);
	for(i=1;i<n;++i)printf("%.12lf ",h*sqrt((double)i/n));
}