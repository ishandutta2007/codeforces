#include<cstdio>
int n,d,m,x,y,xx,yy,a,b;
int main(){
	scanf("%d%d%d",&n,&d,&m);
	x=d;y=-d;xx=n+n-d;yy=d;
	for(;m--;)
	  scanf("%d%d",&a,&b),a+=b,b+=b-a,
	  puts(a>=x&&a<=xx&&b>=y&&b<=yy?"YES":"NO");
	return 0;
}