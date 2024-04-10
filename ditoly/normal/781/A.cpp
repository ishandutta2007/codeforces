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
int h[MN+5],en,r[MN+5],fa[MN+5],c[MN+5];
inline void ins(int x,int y){e[++en]=(edge){h[x],y};h[x]=en;}
void dfs(int x)
{
	int i,j=0;
	for(i=h[x];i;i=e[i].nx)if(e[i].t!=fa[x])
	{
		while(c[x]==++j||c[fa[x]]==j);
		c[e[i].t]=j;fa[e[i].t]=x;dfs(e[i].t);
	}
}
int main()
{
	fread(B,1,1<<26,stdin);
	int n=read(),i,x,y,rt=0;
	for(i=1;i<n;++i)
	{
		if(++r[x=read()]>r[rt])rt=x;
		if(++r[y=read()]>r[rt])rt=y;
		ins(x,y);ins(y,x);
	}
	printf("%d\n",r[rt]+1);
	dfs(c[1]=1);
	for(i=1;i<=n;++i)printf("%d ",c[i]);
}