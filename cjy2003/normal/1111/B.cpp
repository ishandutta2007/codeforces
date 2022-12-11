#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,k,m,a[100010],t[100010],p,q;
long long sum[100010],tot;
double ans,now;
int main()
{
	scanf("%d %d %d",&n,&k,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i)
		sum[i]=sum[i-1]+a[i];
	for(int i=0;i<=m&&i<n;++i)
	{
		now=sum[n]-sum[i];
		now+=min((long long)m-i,1ll*k*(n-i));
		ans=max(ans,now/(n-i));
	}
	printf("%.10lf",ans);
	return 0;
}