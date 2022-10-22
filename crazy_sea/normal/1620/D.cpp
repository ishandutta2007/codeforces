#include<cstdio>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
int calc2(int a,int x,int y)
{
	int s=inf;
	for(int i=0,b;i<=x;i++)
		for(int j=0;j<=y;j++)
		{
			b=a-i-2*j;
			if(b>=0&&b%3==0) s=min(s,b/3);
		}
	return s;
}
int n,a[100010],T,ans;
int calc(int x,int y)
{
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=max(ans,calc2(a[i],x,y));
	return ans;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		ans=inf;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=0;i<=10;i++)
			for(int j=0;j<=10;j++)
				ans=min(ans,calc(i,j)+i+j);
		printf("%d\n",ans);
	}
}