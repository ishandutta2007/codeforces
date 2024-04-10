#include<cstdio>
#include<algorithm>
#define int long long
const int N=1e5+1;
int n,l,r,g,a[N],b[N],c[N],m;
signed main(){//n==1 ll  
	int md;
	scanf("%I64d",&n);
	for(int i=1;i<=n;i++)scanf("%I64d",a+i);
	std::sort(a+1,a+1+n);
	for(int i=2;i<=n;i++)b[i]=a[i]-a[i-1];
	std::sort(b+2,b+1+n);
	for(int i=2;i<=n;i++)c[i]=c[i-1]+b[i];
	//for(int i=1;i<=n;i++)printf("%lld %lld %lld\n",a[i],b[i],c[i]);
	scanf("%I64d",&m);
	for(;m--;){
	  scanf("%I64d%I64d",&l,&r);g=r-l+1;
	  for(l=2,r=n+1;l<r;)md=l+r>>1,b[md]>g?r=md:l=md+1;
	//printf("%lld\n",l);
	  printf("%I64d ",a[n]+g-a[1]-(c[n]-c[l-1]-(n-l+1)*g)); 
	}
	return 0;
}