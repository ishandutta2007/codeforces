#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
#define N 200010
using namespace std;
int T,n,m,mx,a[N],t[N],t1[N],x;
ll ans,sum;
int id(int x,int y)
{
	return (x-1)*m+y;
}
void change(int w)
{
	sum=(sum-1ll*t1[w]*(t[w]-t1[w]));
	t1[w]++;
	sum=(sum+1ll*t1[w]*(t[w]-t1[w]));
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&x),t[x]++,mx=max(mx,x),a[id(i,j)]=x;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			change(a[id(i,j)]);
		ans+=sum;
	}
	sum=0;
	for(int i=1;i<=mx;i++) t1[i]=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
			change(a[id(j,i)]);
		ans+=sum;
	}
	printf("%lld",ans);
}