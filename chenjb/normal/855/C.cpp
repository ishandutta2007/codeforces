#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define inf 1000000007
using namespace std;
int n,m;
int kk,xx;
long long tmp[12][3];
long long f[110000][12][3]; //0: w<kk 1:w=kk 2:w>kk
vector<int> g[110000];
void update(long long &x,long long y)
{
	x=(x+y)%inf;
}
void dfs(int x,int pre)
{
	f[x][0][0]=kk-1;
	f[x][1][1]=1;
	f[x][0][2]=m-kk;
	
	int cnt=g[x].size();
	for(int i=0;i<cnt;i++)
	{
		int son=g[x][i];
		if (son==pre)continue;
		dfs(son,x);
		memset(tmp,0,sizeof(tmp));
		for(int i=xx;i>=0;i--)
		{
			for(int j=0;j<=i;j++)
			{
				update(tmp[i][0],f[x][i-j][0]*f[son][j][0]%inf);
				update(tmp[i][0],f[x][i-j][0]*f[son][j][1]%inf);
				update(tmp[i][0],f[x][i-j][0]*f[son][j][2]%inf);

				update(tmp[i][1],f[x][i-j][1]*f[son][j][0]%inf);
			
				update(tmp[i][2],f[x][i-j][2]*f[son][j][0]%inf);
				update(tmp[i][2],f[x][i-j][2]*f[son][j][2]%inf);
			}
		}
		memcpy(f[x],tmp,sizeof(tmp));
	}		
}
int main()
{
	//freopen("1.in","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)g[i].clear();
	memset(f,0,sizeof(f));
	
	
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	scanf("%d%d",&kk,&xx);
	
	
	dfs(1,0);
	long long ans=0;
	for(int i=0;i<=xx;i++)
	{
		ans=(ans+f[1][i][0])%inf;
		ans=(ans+f[1][i][1])%inf;
		ans=(ans+f[1][i][2])%inf;
	}
	
	cout<<ans<<endl;
}