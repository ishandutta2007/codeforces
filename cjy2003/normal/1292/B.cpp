#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long x[100],y[100],ax,ay,bx,by,xs,ys,t;
int ans;
int main()
{
	scanf("%lld %lld %lld %lld %lld %lld",&x[0],&y[0],&ax,&ay,&bx,&by);
	scanf("%lld %lld %lld",&xs,&ys,&t);
	for(int i=1;i<=80;++i)x[i]=x[i-1]*ax+bx,y[i]=y[i-1]*ay+by;
	int lim;
	for(int i=0;i<=80;++i)
		if(x[i]>2e16||y[i]>2e16)
		{
			lim=i-1;
			break;
		}
//	printf("%d\n",lim);
	for(int i=0;i<=lim;++i)
	{
	//	printf("%lld %lld\n",x[i],y[i]);
		for(int j=i;j>=0;--j)
			for(int k=i;k<=lim;++k)
				if(abs(x[i]-xs)+abs(y[i]-ys)+min(x[i]-x[j]+y[i]-y[j],x[k]-x[i]+y[k]-y[i])+x[k]-x[j]+y[k]-y[j]<=t)ans=max(ans,k-j+1);
	}
	printf("%d",ans);
	return 0;
}