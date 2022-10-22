#include<cstdio>
#include<cmath>
double n,m;
int main(){
	scanf("%lf%lf",&n,&m);
	printf("%.lf",n-(sqrt(9+8*(n+m))-3)/2);
	return 0;
}