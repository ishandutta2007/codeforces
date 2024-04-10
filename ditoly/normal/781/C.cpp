#include<cstdio>
char B[1<<26],*S=B,C;int X;
inline int read()
{
	while((C=*S++)<'0'||C>'9');
	for(X=C-'0';(C=*S++)>='0'&&C<='9';)X=(X<<3)+(X<<1)+C-'0';
	return X;
}
#define MN 200000
struct edge{int nx,t;}e[MN*2+5];
int f[MN+5],h[MN+5],en,ans[MN*2+5],cnt;
int gf(int k){return f[k]?f[k]=gf(f[k]):k;}
inline void ins(int x,int y){e[++en]=(edge){h[x],y};h[x]=en;}
void dfs(int x,int fa)
{
	ans[++cnt]=x;
	for(int i=h[x];i;i=e[i].nx)if(e[i].t!=fa)
	{
		dfs(e[i].t,x);
		ans[++cnt]=x;
	}
}
int main()
{
	fread(B,1,1<<26,stdin);
	int n,m,k,x,y,i,j;
	n=read();m=read();k=read();
	while(m--)
	{
		x=read();y=read();
		if(gf(x)!=gf(y))f[gf(x)]=gf(y),ins(x,y),ins(y,x);
	}
	dfs(1,0);--cnt;
	for(x=1;x*k<cnt;++x);
	for(i=1;i<=k;++i)
	{
		printf("%d ",x);
		for(j=1;j<=x;++j)printf("%d ",cnt?ans[((i-1)*x+j-1)%cnt+1]:1);
		puts("");
	}
}