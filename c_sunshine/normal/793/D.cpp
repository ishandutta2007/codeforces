#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
template<class T> inline bool ten(T &x,const T &y){return y<x?x=y,1:0;}
template<class T> inline bool rel(T &x,const T &y){return x<y?x=y,1:0;}

int n,m,k;
int f[85][85][85];
int g[85][85];
int main()
{
	scanf("%d%d",&n,&k);
	scanf("%d",&m);
	memset(g,-1,sizeof(g));
	for(int i=1;i<=m;i++)
	{
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		if(g[u][v]==-1)g[u][v]=c;
		else ten(g[u][v],c);
	}
	memset(f,31,sizeof(f));
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=n+1;j++)
			f[i][j][0]=0;
	for(int len=1;len<=n+1;len++)
		for(int i=0;i+len<=n+1;i++)
		{
			int j=i+len;
			for(int t=1;t<=k;t++)
			{
				for(int p=i+1;p<j;p++)
				{
					if(g[i][p]!=-1)
						ten(f[i][j][t],g[i][p]+min(f[p][i][t-1],f[p][j][t-1]));
					if(g[j][p]!=-1)
						ten(f[j][i][t],g[j][p]+min(f[p][i][t-1],f[p][j][t-1]));
				}
			}
		}
	int ans=1e9;
	for(int i=1;i<=n;i++)
		ten(ans,min(f[i][0][k-1],f[i][n+1][k-1]));
	if(ans>1000000)cout<<-1<<endl;
	else cout<<ans<<endl;
	return 0;
}