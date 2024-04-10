#include<cstdio>
int n,m,x,d;long long s;
int main(){
	scanf("%d%d",&n,&m);
	for(;m--;){
	  scanf("%d%d",&x,&d);
	  s+=x*n;
	  if(d>0)s+=(1ll*n*(n-1)>>1)*d;
	  if(d<0)s+=(1ll*(n-1>>1)*((n-1>>1)+1)+(n&1?0:n>>1))*d;
	}printf("%.12lf",s*1.0/n);
	return 0;
}