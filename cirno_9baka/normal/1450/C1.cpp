#include<bits/stdc++.h>
using namespace std;
int t,n,i,j,cnt[605],mx,vis[605];
char c[505][505],p[505][505];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		memset(cnt,0,sizeof(cnt));
		memset(vis,0,sizeof(vis));
		for(i=1;i<=n;++i)
			scanf("%s",c[i]+1);
		for(i=1;i<=n;++i)
			for(j=1;j<=n;++j)
				if(c[i][j]!='.')
					++cnt[(i+j)%3];
		mx=0;
		if(cnt[1]>cnt[mx])
			mx=1;
		if(cnt[2]>cnt[mx])
			mx=2;
		for(i=mx;i<=2*n;i+=3)
		{
			vis[i]=1;
			for(j=1;j<i;++j)
				if(i-j<=n&&j<=n)
					p[i-j][j]=c[i-j][j];
		}
		int k=1;
		for(i=1;i<=2*n;++i)
			if(!vis[i])
			{
				for(j=1;j<i;++j)
					if(i-j<=n&&j<=n)
						if(c[i-j][j]!='.')
							p[i-j][j]=(k?'X':'O');
						else
							p[i-j][j]=c[i-j][j];
				k^=1;
			}
		int s=0,as=0;
		for(i=1;i<=n;++i)
			for(j=1;j<=n;++j)
			{
				if(p[i][j]!=c[i][j])
					++s;
				if(c[i][j]!='.')
					++as;
			}
		if(s>as/3)
		{
			int k=0;
			for(i=1;i<=2*n;++i)
				if(!vis[i])
				{
					for(j=1;j<i;++j)
						if(i-j<=n&&j<=n)
							if(c[i-j][j]!='.')
								p[i-j][j]=(k?'X':'O');
							else
								p[i-j][j]=c[i-j][j];
					k^=1;
				}
		}
		for(i=1;i<=n;++i)
		{
			for(j=1;j<=n;++j)
				putchar(p[i][j]);
			putchar('\n');
		}
	}
}