#include<cstdio>
int main(){
	double H,L;
	scanf("%lf%lf",&H,&L);
	printf("%.8lf",(L*L-H*H)/2/H);
	return 0;
}