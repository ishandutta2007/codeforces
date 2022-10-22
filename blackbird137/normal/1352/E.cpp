#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<map>
#include<set>

using namespace std;

int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}

const int N=1e4+5;
int t,n,a[N],vis[N],used[N],sum[N],ans;

int main()
{
	t=read();
	while(t--)
	{
		n=read();ans=0;
		memset(vis,0,sizeof(vis));
		memset(sum,0,sizeof(sum));
		memset(used,0,sizeof(used));
		for(int i=1;i<=n;++i)
		{
			a[i]=read();
			vis[a[i]]++;
			sum[i]=sum[i-1]+a[i];
		}
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
			{
				int num=sum[j]-sum[i-1];
				if(num>n)
					continue;
				if(!used[num])
				{
					ans+=vis[num];
					used[num]=1;
				}
			}
		printf("%d\n",ans);
	}
	return 0;
}