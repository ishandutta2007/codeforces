#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,x[1010],y[1010];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d %d",&x[i],&y[i]);
	while(1)
	{
		bool flag0=0,flag1=0;
		for(int i=1;i<=n;++i)
		{
			if((x[i]+y[i])&1)flag1=1;
			else flag0=1;
		}
		if(flag0&&flag1)
		{
			int ans=0;
			for(int i=1;i<=n;++i)if((x[i]+y[i])&1)++ans;
			printf("%d\n",ans);
			for(int i=1;i<=n;++i)if((x[i]+y[i])&1)printf("%d ",i);
			return 0;
		}
		if(flag1)for(int i=1;i<=n;++i)--y[i];
		for(int i=1;i<=n;++i)
		{
			int a=x[i],b=y[i];
			x[i]=(a+b)/2;
			y[i]=(a-b)/2;
		}
	}
	return 0;
}