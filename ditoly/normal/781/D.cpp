#include<cstdio>
#include<cstring>
#include<bitset>
#include<algorithm>
#include<iostream>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=(x<<3)+(x<<1)+c-'0';
	return x;
}
#define MN 500
#define MK 60
#define INF 1000000000000000000LL
bitset<MN+5> g[MK+5][2][MN+5];
long long f[MK+5][MN+5][2],ans;
int main()
{
	int n,m,i,j,k,x,y;
	n=read();m=read();
	while(m--)
	{
		x=read();y=read();
		g[0][read()][x][y]=1;
	}
	for(k=0;k<MK;++k)for(i=1;i<=n;++i)for(j=1;j<=n;++j)
	{
		if(g[k][0][i][j])g[k+1][0][i]|=g[k][1][j];
		if(g[k][1][i][j])g[k+1][1][i]|=g[k][0][j];
	}
	memset(f,128,sizeof(f));f[k+1][1][0]=0;
	for(k=MK;k>=0;--k)
	{
		for(i=1;i<=n;++i)f[k][i][0]=f[k+1][i][0],f[k][i][1]=f[k+1][i][1];
		for(i=1;i<=n;++i)for(j=1;j<=n;++j)
		{
			if(g[k][0][i][j])f[k][j][1]=max(f[k][j][1],f[k+1][i][0]+(1LL<<k));
			if(g[k][1][i][j])f[k][j][0]=max(f[k][j][0],f[k+1][i][1]+(1LL<<k));
		}
	}
	for(i=1;i<=n;++i)ans=max(ans,max(f[0][i][0],f[0][i][1]));
	cout<<(ans>INF?-1:ans);
}