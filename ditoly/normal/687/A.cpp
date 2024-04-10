#include<cstdio>
#include<cstdlib>
void read(int&x)
{
	x=0;char c;
	do{c=getchar();}while(c<'0'||c>'9');
	do{x=x*10+c-'0';c=getchar();}while(c>='0'&&c<='9');
}
#define MAXN 100000
#define MAXM 200000
struct node{int nx,x;}g[MAXN+5],e[MAXM+5];
int en,n,m,f[MAXN+5],a[3];
void ins(int x,int y)
{
	int k=g[x].x;
	if(k)e[k].nx=++en;
	else g[x].nx=++en;
	e[en].x=y;
	g[x].x=en;
}
void dfs(int x)
{
	int i,y,c=f[x]==1?2:1;
	for(i=g[x].nx;i;i=e[i].nx)
	{
		y=e[i].x;
		if(f[y])
			if(f[y]==c)continue;
			else{puts("-1");exit(0);}
		else
		{
			f[y]=c;
			a[c]++;
			dfs(y);
		}
	}
}
int main()
{
	int i,u,v;
	read(n);read(m);
	for(i=0;i<m;i++)
	{
		read(u);read(v);
		ins(u,v);ins(v,u);
	}
	for(i=1;i<=n;i++)if(!f[i])
	{
		f[i]=1;
		a[1]++;
		dfs(i);
	}
	printf("%d\n",a[1]);
	for(i=1;i<=n;i++)if(f[i]==1)printf("%d ",i);
	printf("\n%d\n",a[2]);
	for(i=1;i<=n;i++)if(f[i]==2)printf("%d ",i);
}