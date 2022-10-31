#include<cstdio>
#include<algorithm>

using namespace std;

int n,a[6000000],A[6000000],t[6000000];

namespace RND
{
	long long seed,base;
	long long nxt()
	{
		long long ret=seed;seed=(seed*base+233)%1000000007;return ret; 
	}
	int p[300000],k[300000],b[300000],w[300000];
	void read()
	{
		int m=0;scanf("%d",&m);
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d%d",&p[i],&k[i],&b[i],&w[i]);seed=b[i],base=w[i];
			for(int j=p[i-1]+1;j<=p[i];j++)
			{
				t[j]=nxt()%2+1;a[j]=nxt()%k[i]+1; 
			}
		}
	}
}

long long sum[3];
long long ans[6000000];

long long output()
{
	long long x=1;for(long long i=1;i<=n;i++)x=x*(((ans[i]^(i*i))+1)%1000000007)%1000000007;printf("%lld",x);
}

int main()
{
	scanf("%d",&n);RND::read();
	//for(int i=1;i<=n;i++)printf("%d %d\n",a[i],t[i]); 
	for(int i=1;i<=n;i++)sum[t[i]]+=a[i],A[i]=a[i];
	if(sum[1]==0||sum[2]==0){ans[1]=1;for(int i=2;i<=n;i++)ans[i]=0;output();return 0;}
	int op=0;if(sum[1]<sum[2])op=1;else if(sum[1]>sum[2])op=2;else op=t[1];
	int p=1;if(t[p]!=op){a[p]--;for(int i=2;i<=n;i++)if(t[i]==op){p=i;break;}}
	long long cnt=0;
	for(int i=p;i<=2*n+p;i++)
	{
		int x=(i-1)%n+1;
		if(t[x]==op){cnt+=a[x];a[x]=0;}
		else
		{
			long long y=min((long long)a[x],cnt);a[x]-=y,cnt-=y;
		}
	}
	//puts("!!");
	//for(int i=1;i<=n;i++)printf("%lld ",a[i]);puts("");
	for(int i=1;i<=n;i++)ans[i]=A[i]-a[i];output();
}