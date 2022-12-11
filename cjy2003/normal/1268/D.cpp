#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,cur[2020][2020],d[2020];
char c[2020][2020];
namespace task1
{
	int cnt[1<<6],mi=0x3f3f3f3f,ans;
	bool check(int b)
	{
		for(int i=1;i<=n;++i)	
			for(int j=1;j<=n;++j)
				cur[i][j]=c[i][j]-'0';
		for(int i=1;i<=n;++i)
			if((b>>i-1)&1)
				for(int j=1;j<=n;++j)cur[i][j]^=1,cur[j][i]^=1;
		memset(d+1,0,n<<2);
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				d[i]+=cur[i][j];
		sort(d+1,d+1+n);
		int sum=0;
		for(int i=1;i<n;++i)
		{
			sum+=d[i];
			if(sum==i*(i-1)/2)return 0;
		}
		return 1;
	}
	void solve()
	{
		for(int i=0;i<1<<n;++i)
		{
			cnt[i]=cnt[i>>1]+(i&1);
			if(check(i))
			{
				if(cnt[i]<mi)mi=cnt[i],ans=0;
				if(cnt[i]==mi)++ans;
			}
		}
		if(mi==0x3f3f3f3f)printf("-1");
		else
		{
			for(int i=2;i<=mi;++i)ans*=i;
			printf("%d %d",mi,ans);
		}
	}
}
namespace task2
{
	int d1[2020],ans;
	bool check()
	{
		memcpy(d1+1,d+1,n<<2);
		sort(d1+1,d1+1+n);
		int sum=0;
		for(int i=1;i<n;++i)
		{
			sum+=d1[i];
			if(sum==i*(i-1)/2)return 0;
		}
		return 1;
	}
	void solve()
	{
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				d[i]+=c[i][j]=='1';
		if(check())printf("0 1");
		else
		{
			for(int i=1;i<=n;++i)
			{
				for(int j=1;j<=n;++j)
				{
					if(c[i][j]=='1')--d[i],++d[j];
					else ++d[i],--d[j];
				}
				if(check())++ans;
				for(int j=1;j<=n;++j)
				{
					if(c[i][j]=='1')++d[i],--d[j];
					else --d[i],++d[j];
				}		
			}
			printf("1 %d",ans);
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%s",c[i]+1);
	if(n<=6)task1::solve();
	else task2::solve();
	return 0;
}