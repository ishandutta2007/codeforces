#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
inline int read()
{
	int x,f=1;char c;
	while((c=getchar())<'0'||c>'9')if(c=='-')f=0;
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=(x<<3)+(x<<1)+c-'0';
	return f?x:-x;
}
#define MN 300000
#define N 524288
struct edge{int nx,t;}e[MN*2+5];
int t[N*2+5],h[MN+5],en;
inline void ins(int x,int y)
{
	e[++en]=(edge){h[x],y};h[x]=en;
	e[++en]=(edge){h[y],x};h[y]=en;
}
void add(int k,int x){for(t[k+=N]+=x;k>>=1;)t[k]=max(t[k<<1],t[k<<1|1]);}
int main()
{
	int n=read(),i,j,ans=0x7FFFFFFF;
	memset(t,128,sizeof(t));
	for(i=1;i<=n;++i)t[i+N]=read()+2;
	for(i=N;--i;)t[i]=max(t[i<<1],t[i<<1|1]);
	for(i=1;i<n;++i)ins(read(),read());
	for(i=1;i<=n;++i)
	{
		add(i,-2);
		for(j=h[i];j;j=e[j].nx)add(e[j].t,-1);
		ans=min(ans,t[1]);
		add(i,2);
		for(j=h[i];j;j=e[j].nx)add(e[j].t,1);
	}
	printf("%d",ans);
}