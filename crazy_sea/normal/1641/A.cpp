#include<cstdio>
#include<algorithm>
#define N 200010
using namespace std;
int n,x,T,a[N],p[N],ans;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&x);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		for(int i=1,j=1;i<=n;i++)
		{
			if(p[i]) continue;
			while(j<=n&&(p[j]||a[j]<1ll*a[i]*x)) j++;
			if(j<=n&&a[j]==1ll*a[i]*x) p[j]=1;
		}
		ans=n;
		for(int i=1;i<=n;i++)
			if(p[i]) ans-=2,p[i]=0;
		printf("%d\n",ans);
	}
}