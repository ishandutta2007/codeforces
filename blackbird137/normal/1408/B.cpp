#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#define int long long

using namespace std;

int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}

const int N=105;
int t,n,k,a[N],ans,vis[N];

signed main()
{
	//freopen("yangli.in","r",stdin);
	t=read();
	while(t--)
	{
		n=read();k=read();
		for(int i=1;i<=n;++i)
			a[i]=read();
		memset(vis,0,sizeof(vis));
		int sum=0,last=-1,now=1;
		ans=1;
		for(int i=1;i<=n;++i)
		{
			int flag=0;
			if(!vis[a[i]])
			{
				vis[a[i]]=1;
				flag=1;
			}
			if(sum==k)
			{
				a[i]-=last;
				if(a[i]==0) now++;
			}
				
			else
			{
				last=a[i];
				now++;
				a[i]=0;sum+=flag;
			}
		}
		if(k==1&&now<=n)
		{
			printf("-1\n");
			continue;
		}
		while(now<=n)
		{
			memset(vis,0,sizeof(vis));
			sum=0,last=-1;
			for(int i=now;i<=n;++i)
			{
				int flag=0;
				if(!vis[a[i]])
				{
					vis[a[i]]=1;
					flag=1;
				}
				if(sum==k-1)
				{
					a[i]-=last;
					if(a[i]==0) now++;
				}
					
				else
				{
					last=a[i];
					now++;
					a[i]=0;sum+=flag;
				}
			}
			ans++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}