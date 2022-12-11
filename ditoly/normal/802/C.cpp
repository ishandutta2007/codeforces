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
#define MV 80
#define ME 160
#define S MV+1
#define T MV+2
struct edge{int nx,t,w,c;}e[ME*2+5];
int a[MV+5],c[MV+5],ls[MV+5];
int h[MV+5],en=1,q[1000005],qn,inq[MV+5],d[MV+5],r[MV+5];
inline void ins(int x,int y,int w,int c)
{
	e[++en]=(edge){h[x],y,w,c};h[x]=en;
	e[++en]=(edge){h[y],x,0,-c};h[y]=en;
}
bool spfa()
{
	int i,j;
	memset(d,40,sizeof(d));
	for(d[q[i=qn=0]=S]=0;i<=qn;inq[q[i++]]=0)for(j=h[q[i]];j;j=e[j].nx)
		if(e[j].w&&d[q[i]]+e[j].c<d[e[j].t])
		{
			d[e[j].t]=d[q[i]]+e[j].c;r[e[j].t]=j;
			if(!inq[e[j].t])inq[q[++qn]=e[j].t]=1;
		}
	return d[T]<d[0];
}
int main()
{
	int n,k,i,j,ans=0,mn;
	n=read();k=read()-1;
	for(i=1;i<=n;++i)a[i]=read();
	for(i=1;i<=n;++i)c[i]=read();
	ins(S,1,k,0);ins(n,T,k,0);
	for(i=1;i<n;++i)ins(i,i+1,k,0);
	for(i=1;i<=n;++i)
	{
		ans+=c[a[i]];
		if(ls[a[i]])
			if(ls[a[i]]==i-1)ans-=c[a[i]];
			else ins(ls[a[i]]+1,i,1,-c[a[i]]);
		ls[a[i]]=i;
	}
	while(spfa())
	{
		for(mn=1e9,i=T;i!=S;i=e[r[i]^1].t)mn=min(mn,e[r[i]].w);
		for(i=T;i!=S;i=e[r[i]^1].t)e[r[i]].w-=mn,e[r[i]^1].w+=mn;
		ans+=d[T]*mn;
	}
    printf("%d",ans);
}