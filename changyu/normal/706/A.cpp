#include<cstdio>
#include<cmath>
#define p(a)(a)*(a)
int n,a,b,v,x,y;double mn=1e9;
int main()
{
	scanf("%d%d%d",&a,&b,&n);
	while(n--){
	  scanf("%d%d%d",&x,&y,&v);
	  double t=sqrt(p(x-a)+p(y-b))/v;
	  if(t<mn)mn=t;
	}
	printf("%.9lf",mn);
	return 0;
}