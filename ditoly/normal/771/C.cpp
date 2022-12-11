#include<cstdio>
#include<iostream>
using namespace std;
char B[1<<26],*S=B,C;int X;
inline int read()
{
	while((C=*S++)<'0'||C>'9');
	for(X=C-'0';(C=*S++)>='0'&&C<='9';)X=(X<<3)+(X<<1)+C-'0';
	return X;
}
#define MN 200000
struct edge{int nx,t;}e[MN*2+5];
int k,h[MN+5],en,f[MN+5][5];
long long ans,ff[MN+5];
inline void ins(int x,int y)
{
	e[++en]=(edge){h[x],y};h[x]=en;
	e[++en]=(edge){h[y],x};h[y]=en;
}
void dfs(int x,int fa)
{
	int i,j,l;
	f[x][0]=1;
	for(i=h[x];i;i=e[i].nx)if(e[i].t!=fa)
	{
		dfs(e[i].t,x);
		for(j=0;j<k;++j)
		{
			ans+=1LL*f[e[i].t][j]*ff[x]+1LL*f[x][j]*ff[e[i].t];
			for(l=0;l<k;++l)ans+=1LL*f[e[i].t][j]*f[x][l]*((j+l)/k+1);
		}
		for(j=1;j<k;++j)f[x][j]+=f[e[i].t][j-1];
		f[x][0]+=f[e[i].t][k-1];ff[x]+=ff[e[i].t]+f[e[i].t][k-1];
	}
}
int main()
{
	fread(B,1,1<<26,stdin);
	int n=read(),i;k=read();
	for(i=1;i<n;++i)ins(read(),read());
	dfs(1,0);
	cout<<ans;
}