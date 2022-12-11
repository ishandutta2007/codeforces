#include<cstdio>
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=(x<<3)+(x<<1)+c-'0';
	return x;
}
#define MN 150000
struct edge{int nx,t;}e[MN*2+5];
int h[MN+5],en,r[MN+5],u[MN+5];
long long sum,cnt;
inline void ins(int x,int y)
{
	e[++en]=(edge){h[x],y};h[x]=en;++r[x];
	e[++en]=(edge){h[y],x};h[y]=en;++r[y];
}
void dfs(int x)
{
	cnt+=u[x]=1;sum+=r[x];
	for(int i=h[x];i;i=e[i].nx)if(!u[e[i].t])dfs(e[i].t);
}
int main()
{
	int n,m,x,y,i;
	n=read();m=read();
	while(m--)ins(read(),read());
	for(i=1;i<=n;++i)if(!u[i])
	{
		sum=cnt=0;dfs(i);
		if(cnt*(cnt-1)!=sum)return 0*puts("NO");
	}
	puts("YES");
}