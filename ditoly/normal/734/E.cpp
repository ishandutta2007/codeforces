#include<cstdio>
int read()
{
	int x=0;char c;
	while((c=getchar())<'0'||c>'9');
	for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
	return x;
}
#include<queue>
#include<algorithm>
using namespace std;
#define MAXN 200000
struct edge{int nx,t;}e[MAXN*2+5];
int h[MAXN+5],en,c[MAXN+5],r[MAXN+5],f[MAXN+5];
struct node
{
	int x;
	friend bool operator<(node a,node b){return f[a.x]>f[b.x];}
};
priority_queue<node> pq;
int main()
{
	int n=read(),i,x,y;
	for(i=1;i<=n;i++)c[i]=read();
	for(i=1;i<n;i++)
	{
		r[x=read()]++;r[y=read()]++;
		e[++en]=(edge){h[x],y};h[x]=en;
		e[++en]=(edge){h[y],x};h[y]=en;
	}
	for(i=1;i<=n;i++)if(r[i]==1)pq.push((node){i});
	while(pq.size())
	{
		r[x=pq.top().x]--;pq.pop();
		for(i=h[x];i;i=e[i].nx)if(r[y=e[i].t])
		{
			f[y]=max(f[y],f[x]+(c[x]!=c[y]));
			if(--r[y]<2)pq.push((node){y});
		}
	}
	printf("%d",f[x]);
}