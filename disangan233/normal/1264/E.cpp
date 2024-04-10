#include<bits/stdc++.h>
using namespace std;
#define re register int
#define in inline
#define ak *
#define inf 1e9
in char getch()
{
	static char buf[1<<12],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<12,stdin),p1==p2)?EOF:*p1++;
}
char qwq;
#define gc() getch()
in int read()
{
	re cz=0,ioi=1;qwq=gc();
	while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=gc();
	while(qwq>='0'&&qwq<='9') cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=gc();
	return cz ak ioi;
}
const int N=2e4+5,M=1e6+5;
int col,cnt=1,sum,tot,n,m,s,t;
int h[N],dis[N],l,r,q[N],pre[N],vis[N],ans,maxflow,a[105][105];
struct did{int u,next,to,f,w;}e[M];
in void add(re a,re b,re c,re d)
{
	e[++cnt]=(did){a,h[a],b,c,d},h[a]=cnt;
	e[++cnt]=(did){b,h[b],a,0,-d},h[b]=cnt;
}
int spfa()
{
	memset(pre,0,sizeof(pre));memset(vis,0,sizeof(vis));
	for(re i=s;i<=t;i++) dis[i]=i==s?0:inf;
	queue<int>q;q.push(s);vis[s]=1;
	while(!q.empty())
	{
		re i=q.front();vis[i]=0;q.pop();
		for(re j=h[i],k;k=e[j].to,j;j=e[j].next)
		if(e[j].f&&dis[k]>dis[i]+e[j].w)
		{
			dis[k]=dis[i]+e[j].w;pre[k]=j;
			if(!vis[k]) q.push(k),vis[k]=1;
		}
	}
	return dis[t]<inf;
}
in void solve()
{
	re delta=inf;
	for(re i=t,p;p=pre[i],i!=s;i=e[p^1].to)
	delta=min(delta,e[p].f);
	for(re i=t,p;p=pre[i],i!=s;i=e[p^1].to)
	e[p].f-=delta,e[p^1].f+=delta;
	maxflow+=delta;ans+=delta*dis[t];
}
in void mcmf() {while(spfa()) solve();}
in int f(re x,re y) {return n*(x-1)+y;}
int main()
{
	n=read();s=0,t=(n+1)*n+1;
	for(re i=1;i<=n;i++) for(re j=1;j<=n;j++) a[i][j]=2;
	int m=read(),ax,bx;while(m--) ax=read(),bx=read(),a[ax][bx]=1,a[bx][ax]=0;
	for(re i=1;i<=n;i++) for(re j=1;j<=n;j++)
	{
		if(i>=j) continue;
		switch(a[i][j])
		{
			case 0: add(s,n*n+i,1,0);break;
			case 1: add(s,n*n+j,1,0);break;
			case 2: add(s,f(i,j),1,0);add(f(i,j),n*n+i,1,0);add(f(i,j),n*n+j,1,0);break;
		}
	}
	for(re i=1;i<=n;i++) for(re j=0;j<n;j++) add(n*n+i,t,1,j);
	mcmf();
	for(re i=1;i<=n;i++) for(re j=1;j<=n;j++)
	{
		if(a[i][j]!=2) continue;
		for(re k=h[f(i,j)];k;k=e[k].next)
		if(e[k].to&&!e[k].f) a[i][j]=(e[k].to-n*n==j),a[j][i]=a[i][j]^1;
	}
	for(re i=1;i<=n;i++)
	{
		for(re j=1;j<=n;j++) printf("%d",a[i][j]>=2?0:a[i][j]);
		puts("");
	}
}