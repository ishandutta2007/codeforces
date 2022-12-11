#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=(x<<3)+(x<<1)+c-'0';
	return x;
}
#define MN 80
int u[MN+5][MN+5][2][MN+5],f[MN+5][MN+5][2][MN+5],g[MN+5][MN+5];
int cal(int l,int r,int p,int k)
{
	if(!--k)return 0;
	if(u[l][r][p][k])return f[l][r][p][k];
	for(int i=l;++i<r;)
	{
		int d=p?g[r][i]:g[l][i];
		if(d<g[0][0])f[l][r][p][k]=min(f[l][r][p][k],min(cal(l,i,1,k),cal(i,r,0,k))+d);
	}
	return u[l][r][p][k]=1,f[l][r][p][k];
}
int main()
{
	int n=read(),k=read(),i,x,y,ans;
	memset(f,42,sizeof(f));memset(g,42,sizeof(g));ans=g[0][0];
	for(i=read();i--;)x=read(),y=read(),g[x][y]=min(g[x][y],read());
	for(i=1;i<=n;++i)ans=min(ans,min(cal(0,i,1,k),cal(i,n+1,0,k)));
	printf("%d",ans<g[0][0]?ans:-1);
}