#include<cstdio>
#include<algorithm>
typedef long long ll;
const ll INF=1e18;
const int N=5e5+3;
int n,m,a[N],c1;
ll t,t1,s,s0,mx,f[N];
int main(){
	mx=-INF;
	scanf("%d%d",&n,&m),++m;
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	std::sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
	  if(a[i]>=0)break;
	  f[i]=f[i-1]+(ll)a[i]*((i-1)/m);
	}
	if(a[n]<0)mx=f[n];
	for(int i=n;i;i--){
	  if(a[i]>=0){
		s+=s0,s0+=a[i];
		if(i>1&&a[i-1]<0)mx=std::max(mx,f[i-1]+s0*((i-2)/m+1)+s);
		continue;
	  }
	  t+=t1,t1+=a[i];
	  ++c1;
	  if(i>1&&f[i-1]>-INF)mx=std::max(mx,c1*s0+s+t+f[i-1]+(s0+t1)*((i-2)/m+1));
	}
	s=s0=0;
	for(int i=n;i;i--)s+=s0,s0+=a[i];
	mx=std::max(mx,s);
	printf("%lld\n",mx);
	return 0;
}