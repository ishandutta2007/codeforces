#include <cstdio>

int n,k;
double L,v1,v2,l,t;

int main()
{
	scanf("%d%lf%lf%lf%d",&n,&L,&v1,&v2,&k);

	n = (n-1)/k+1;

	l = L/(n-(n-1)*(v2-v1)/(v1+v2));

	printf("%.10lf\n",l/v2 + (L-l)/v1);

	return 0;
}