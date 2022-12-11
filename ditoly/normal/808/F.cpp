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
#define MN 101
#define MX 200000
#define ME 10100
#define S MN+1
#define T MN+2
#define INF 0x7FFFFFFF
struct edge{int nx,t,w;}e[ME*2+5];
int p[MX+5],pn,u[MX+5],pw[MN+5],c[MN+5],lv[MN+5];
int h[MN+5],en,d[MN+5],q[MN+5],qn,cr[MN+5];
inline void ins(int x,int y,int w)
{
	e[++en]=(edge){h[x],y,w};h[x]=en;
	e[++en]=(edge){h[y],x,0};h[y]=en;
}
bool bfs()
{
	int i,j;
	memset(d,0,sizeof(d));
	for(d[q[i=qn=0]=S]=1;i<=qn;++i)for(j=cr[q[i]]=h[q[i]];j;j=e[j].nx)
		if(e[j].w&&!d[e[j].t])d[q[++qn]=e[j].t]=d[q[i]]+1;
	return d[T];
}
int dfs(int x,int r)
{
	if(x==T)return r;
	int k,u=0;
	for(int&i=cr[x];i;i=e[i].nx)if(e[i].w&&d[x]+1==d[e[i].t])
	{
		k=dfs(e[i].t,min(e[i].w,r-u));
		u+=k;e[i].w-=k;e[i^1].w+=k;
		if(u==r)return u;
	}
	return d[x]=0,u;
}
int main()
{
	int n,k,i,j,l=1,r=1,mid,s,ans=-1;
	for(i=2;i<=MX;++i)
	{
		if(!u[i])p[++pn]=i;
		for(j=1;i*p[j]<=MX;++j){u[i*p[j]]=1;if(i%p[j]==0)break;}
	}
	n=read();k=read();
	for(i=1;i<=n;++i)pw[i]=read(),c[i]=read(),r=max(r,lv[i]=read());
	while(l<=r)
	{
		mid=l+r>>1;
		memset(h,0,sizeof(h));en=1;
		for(s=0,i=1;i<=n;++i)if(lv[i]<=mid&&c[i]==1)s=max(s,pw[i]);
		if(s)pw[n+1]=s,c[n+1]=1,lv[n+1]=1;else lv[n+1]=mid+1;
		for(s=0,i=1;i<=n+1;++i)if(lv[i]<=mid&&(c[i]>1||i>n))
		{
			s+=pw[i];
			if(c[i]&1)ins(S,i,pw[i]);else ins(i,T,pw[i]);
			for(j=1;j<i;++j)if(lv[j]<=mid&&(c[j]>1||j>n)&&!u[c[i]+c[j]])
				if(c[i]&1)ins(i,j,INF);else ins(j,i,INF);
		}
		while(bfs())s-=dfs(S,INF);
		if(s<k)l=mid+1;else ans=mid,r=mid-1;
	}
	printf("%d",ans);
}