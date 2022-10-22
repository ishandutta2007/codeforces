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

const int N=55;
int t,n,k,a[N],b[N],vis[N];

signed main()
{
	t=read();
	while(t--)
	{
		n=read();k=read();
		memset(vis,0,sizeof(vis));
		int flag=1;
		for(int i=1;i<=n;++i)
			a[i]=read();
		for(int i=1;i<=n;++i)
			b[i]=read();
		sort(a+1,a+1+n);
		for(int i=n;i>=1;--i)
		{
			int mmin=1e18,pos=-1;
			for(int j=1;j<=n;++j)
				if(!vis[j]&&a[i]+b[j]<=k&&fabs(a[i]-b[j])<mmin)
				{
					mmin=fabs(a[i]-b[j]);
					pos=j;
				}
			if(pos==-1) flag=0;
			else vis[pos]=1;
		}
		printf("%s\n",flag?"Yes":"No");
	}
	return 0;
}