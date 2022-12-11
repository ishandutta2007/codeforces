#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[500050],sum[1000010],pre[1000010],A;
long long ans;
int mx1,mx2;
inline void upd(int x)
{
	if(x>mx1)mx2=mx1,mx1=x;
	else if(x>mx2)mx2=x;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),++sum[a[i]],A=max(A,a[i]);
	pre[0]=-1;
	for(int i=1;i<=2*A;++i)pre[i]=sum[i]?i:pre[i-1],sum[i]+=sum[i-1];
	long long cnty;
	int x,c;
	for(int i=2;i<=A;++i)
	{
		cnty=0;
		for(int j=A/i*i;j;j-=i)cnty+=sum[A]-sum[j-1];
	//	printf("%d %lld\n",i,cnty);
		mx1=-0x3f3f3f3f,mx2=-0x3f3f3f3f;
		for(int j=A/i*i;j>=0;j-=i)
		{
			x=pre[j+i-1];
			if(x>=j)
			{
				c=sum[x]-sum[x-1];
				upd(x%i);
				if(c>1)upd(x%i);
				else if(pre[x-1]>=j)upd(pre[x-1]%i);
			}
			x=(j+mx1)/2;
			if(x>1&&cnty-j/i>1)ans=max(ans,1ll*i*min(1ll*x,cnty-j/i));
			if(mx1>=0&&mx2>=0)
			{
				x=j+mx2;
				if(x>1&&cnty-j/i*2>1)ans=max(ans,1ll*i*min(1ll*x,cnty-j/i*2));
				x=j+mx1;
				if(x>1&&cnty-j/i*2-1>1&&sum[A]-sum[x-1]>=2)ans=max(ans,1ll*i*min(1ll*x,cnty-j/i*2-1));	
			}
	//		printf("%d %d %d %lld\n",j,mx1,mx2,ans);
		}
	//	printf("%d %lld\n",i,ans);
	}
	printf("%lld",ans);
	return 0;
}