#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
int su[100010],sunum;
bool bj[100010];
void init()
{
	bj[1]=1;
	for(int i=2;i<=100000;++i)
	{
		if(!bj[i])su[++sunum]=i;
		for(int j=1;j<=sunum&&su[j]*i<=100000;++j)
		{
			bj[su[j]*i]=1;
			if(i%su[j]==0)break;
		}
	}
}
int n,k,cnt[100010];
long long ans;
int main()
{
	init();
	scanf("%d %d",&n,&k);
	int x;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&x);
		int w=x,num,c=1;
		long long y=1;
		for(int j=1;su[j]*su[j]<=x;++j)
			if(w%su[j]==0)
			{
				num=0;
				while(w%su[j]==0)w/=su[j],++num;
				num%=k;
				for(int l=1;l<=num;++l)c*=su[j];
				if(num)num=k-num;
				while(num&&y<=100000)y*=su[j],--num;
			}
		if(w>1)
		{
			num=k-1;
			while(num&&y<=100000)y*=w,--num;
			c*=w;
		}
	//	printf("%lld %d\n",y,c);
		if(y<=100000)ans+=cnt[y];
		++cnt[c];
	}
	printf("%lld",ans);
	return 0;
}