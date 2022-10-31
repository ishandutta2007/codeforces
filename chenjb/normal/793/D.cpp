#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <cstdlib>
#define LL long long 
using namespace std;
int f[81][81][81][2];
int g[81][81],n,m,k;
int main()
{
	//freopen("1.in","r",stdin);
	memset(g,255,sizeof(g));
	cin>>n>>k>>m;
	int x,y,w;
	memset(f,100,sizeof(f));
	int inf=f[1][1][1][1];
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>w;
		if (g[x][y]==-1)g[x][y]=w; else g[x][y]=min(g[x][y],w);
		if (x<y)
			{
				f[2][x][y][1]=min(f[2][x][y][1],w);
				f[2][y][n+1][0]=min(f[2][y][n+1][0],w);
			}
		else 
			{
				f[2][y][x][0]=min(f[2][y][x][0],w);
				f[2][0][y][1]=min(f[2][0][y][1],w);
			}
	}
	int now;
	for(int i=2;i<=k-1;i++)
		for(int l=0;l<=n+1;l++)
			for(int r=l;r<=n+1;r++)
				for(int way=0;way<=1;way++)
				if (f[i][l][r][way]!=inf)
				{
					if (way==0)now=l; else now=r;
					for(int p=l+1;p<=r-1;p++)
						if (g[now][p]!=-1)
						{
							int q;
							if (p<now)q=0;else q=1;
							int w=f[i][l][r][way]+g[now][p];
							if (q==0)
							{
								f[i+1][p][r][0]=min(f[i+1][p][r][0],w);
								f[i+1][l][p][1]=min(f[i+1][l][p][1],w);
							}
							if (q==1)
							{
								f[i+1][l][p][1]=min(f[i+1][l][p][1],w);
								f[i+1][p][r][0]=min(f[i+1][p][r][0],w);
							}
						}
				}
	int ans=inf;
	for(int l=1;l<=n;l++)
		for(int r=l;r<=n;r++)
			for(int p=0;p<=1;p++)
				ans=min(ans,f[k][l][r][p]);
	if (k==1)ans=0;
	if (ans==inf)cout<<-1<<endl; else cout<<ans<<endl;
	return 0;
}