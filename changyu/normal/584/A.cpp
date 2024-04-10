#include<cstdio>
#include<cmath>
#define min(a,b)a<b?a:b
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	if(m==10&&n==1)return 0*puts("-1");
	printf("%d",m);
	while(n---(m==10)-1)putchar('0');
	return 0;
}