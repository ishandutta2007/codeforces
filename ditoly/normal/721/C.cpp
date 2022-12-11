#include<cstdio>
int read()
{
	int x=0;char c;
	while((c=getchar())<'0'||c>'9');
	for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
	return x;
}
#define MAXN 5000
#define MAXM 5000
struct edge{int t,w,nx;}e[MAXM+5];
int f[MAXN+5][MAXN+5],ff[MAXN+5][MAXN+5];
int h[MAXN+5],en,r[MAXN+5],q[MAXN+5],qn,ans[MAXN+5];
inline void ins(int x,int y,int w)
{
	e[++en]=(edge){y,w,h[x]};
	h[x]=en;
}
int main()
{
	int n,m,t,x,y,w,i,j,k,p;
	n=read();m=read();t=read();
	while(m--)
	{
		x=read();y=read();w=read();
		ins(x,y,w);r[y]++;
	}
	for(i=1;i<=n;i++)for(j=1;j<=n;j++)f[i][j]=t+1;
	f[1][1]=0;
	for(i=1;i<=n;i++)if(!r[i])q[qn++]=i;
	for(i=0;q[i]!=n;i++)
	{
		x=q[i];
		for(j=h[x];j;j=e[j].nx)
		{
			y=e[j].t;
			for(k=1;k<n;k++)if(f[x][k]+e[j].w<f[y][k+1])
			{
				f[y][k+1]=f[x][k]+e[j].w;
				ff[y][k+1]=x;
			}
			if(--r[y]==0)q[qn++]=y;
		}
	}
	for(i=n;;i--)if(f[n][i]<=t)
	{
		printf("%d\n",i);
		for(j=i,p=n;j;p=ff[p][j],j--)ans[j]=p;
		for(j=1;j<=i;j++)printf("%d ",ans[j]);
		break;
	}
}