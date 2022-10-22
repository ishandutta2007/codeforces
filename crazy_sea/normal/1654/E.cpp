#include<cstdio>
#include<algorithm>
using namespace std;
const int B=320,N=1e5+10;
int t[N*(B+1)];
int a[N],n,ans,x,y;
void work(int x)
{
	for(int i=1;i<=n;i++)
		ans=max(ans,++t[a[i]+i*x]);
	for(int i=1;i<=n;i++) t[a[i]+i*x]=0;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=0;i<=B;i++) work(i);
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=i+B&&j<=n;j++)
		{
			x=a[j]-a[i],y=j-i;
			if(x<=0||x%y) continue;
			t[x/y]++;
			ans=max(ans,t[x/y]+1);
		}
		for(int j=i+1;j<=i+B&&j<=n;j++)
		{
			x=a[j]-a[i],y=j-i;
			if(x>0) t[x/y]=0;
		}
	}
	for(int i=1;i+i<=n;i++) swap(a[i],a[n-i+1]);
	for(int i=1;i<=B;i++) work(i);
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=i+B&&j<=n;j++)
		{
			x=a[j]-a[i],y=j-i;
			if(x<=0||x%y) continue;
			t[x/y]++;
			ans=max(ans,t[x/y]+1);
		}
		for(int j=i+1;j<=i+B&&j<=n;j++)
		{
			x=a[j]-a[i],y=j-i;
			if(x>0) t[x/y]=0;
		}
	}
	printf("%d",n-ans);
}