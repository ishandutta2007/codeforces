#include<cstdio>
#define N 100010
using namespace std;
int n,m,k,a[N],l,r;
long long s[N];
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	a[n+1]=k+1;
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i+1]-a[i-1]-2;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&l,&r);
		printf("%lld\n",s[r-1]-s[l]+k-a[r-1]+a[l+1]-3);
	}
	return 0;
}