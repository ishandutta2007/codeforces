#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<bitset>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<queue>
#include<map>

using namespace std;

int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}

const int N=1005;
int t,n,m,a[N],vis[N];

int main()
{
	t=read();
	while(t--)
	{
		memset(vis,0,sizeof(vis));
		n=read();m=read();
		int ans=-1;
		for(int i=1;i<=n;++i)
			a[i]=read(),vis[a[i]]=1;
		for(int j=1;j<=m;++j)
		{
			int b=read();
			if(vis[b]) ans=b;
		}
		if(ans==-1) printf("NO\n");
		else printf("YES\n1 %d\n",ans);
	}
	return 0;
}