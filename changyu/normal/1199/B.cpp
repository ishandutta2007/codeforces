#include<cstdio>
double h,l;
int main(){
	scanf("%lf%lf",&h,&l);printf("%.15lf",(l*l-h*h)/h/2);
	return 0;
}