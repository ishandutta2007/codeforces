#include<cstdio>
using namespace std;
int n;long double p;
int main(){
	scanf("%d%Lf",&n,&p);
	for(int i=0;i<=n;++i)
		if((i*(i-1)*(i-2)/6+i*(i-1)/2*(n-i)+(n-i)*(n-i-1)/2*i/(long double)2)>=p*(n*(n-1)*(n-2)/6)){printf("%d",i);break;}
	return 0;
}