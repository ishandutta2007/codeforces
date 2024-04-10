#include<cstdio>
typedef long long ll;
ll n,p,w,d,x,y;
int main(){
	scanf("%lld%lld%lld%lld",&n,&p,&w,&d);
	for(y=0;y<w;y++)
	  if(p-y*d>=0&&(p-y*d)%w==0&&(p-y*d)/w+y<=n)
		return 0*printf("%lld %lld %lld\n",(p-y*d)/w,y,n-y-(p-y*d)/w);
	return 0*puts("-1");
}