#include<cstdio>
#define N 100010
#define maxint 0x3f3f3f3f
using namespace std;
int f,ss,ans,s[N],n,x,t[N],T,a[N],p;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&x);
		for(int i=1;i<=x;i++)
		{
			t[i]=maxint;
		}
		f=x;
		ans=-1;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			s[i]=s[i-1]+a[i];
			p=s[i]%x;
			if(t[p]==maxint) t[p]=i;
			if(p==0) continue;
			if(t[f]>t[p]) f=p;
		}
		for(int i=1;i<=n;i++)
		{
			if(s[i]%x) ss=i;
			else ss=i-t[f];
			if(ss>ans) ans=ss;
		}
		printf("%d\n",ans);
	}
}