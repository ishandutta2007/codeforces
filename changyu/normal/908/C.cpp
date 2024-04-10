#include<cmath>
#include<cstdio>
#include<cstring>
#define p(a)(a)*(a)
#define max(a,b)a>b?a:b
int n,r,x[1000];double y[1000];
int main()
{
	memset(y,63,sizeof y);
	scanf("%d%d%d",&n,&r,x);
	printf("%.lf",y[0]=r);
	for(int i=1;i<n;i++){
	  double mx=r,t;
	  scanf("%d",x+i);
	  for(int j=0;j<i;j++)
		if(p(x[j]-x[i])<=p(2*r))
		  t=y[j]+sqrt(p(2*r)-p(x[i]-x[j])),mx=max(mx,t);
	  printf(" %.9lf",y[i]=mx);
	}
	return 0;
}