#include<cstdio>
#define N 150010
using namespace std;
struct edge{
	int next,to;
}e[N];
int first[N],len;
int n,m,s[N],t[N];
void Add(int a,int b)
{
	e[++len]=(edge){first[a],b};
	first[a]=len;
}
void add(int a,int b,int x)
{
	if(t[b-2]-t[a]>0) return;
	if(b>x) Add(a+1,b);
	else Add(b,a+1);
}
namespace init
{
	int a[N],b[N];
	void main()
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<n;i++) s[i]=1;
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&a[i],&b[i]);
			if(b[i]==a[i]+1) s[a[i]]=0;
		}
		for(int i=1;i<=n;i++) t[i]=t[i-1]+s[i];
	}
	void work(int x)
	{
		for(int i=2;i<=n;i++) add(0,i,x);
		for(int i=1;i<n;i++) add(i,n+1,x);
		for(int i=1;i<=m;i++)
			if(b[i]!=a[i]+1) add(a[i],b[i],x);
	}
}
int vis[N][2];
void dfs(int x,bool p)
{
	vis[x][p]=1;
	p^=1;
	for(int i=first[x];i;i=e[i].next)
		if(!vis[e[i].to][p]) dfs(e[i].to,p);
}
long long s1[4],s2[4];
void work()
{
	init::main();
	if(t[n]==0){printf("%lld",1ll*n*(n-1)/2);return;}
	int x=1,y=n;
	while(!s[x]) x++;x++;
	while(!s[y]) y--;y++;
	init::work(x);
	dfs(x,0);len=0;
	for(int i=0;i<4;i++) s1[i]=s2[i]=0;
	for(int i=1;i<=x;i++) s1[vis[i][0]*2+vis[i][1]]++;
	for(int i=y;i<=n+1;i++) s2[vis[i][1]*2+vis[i][0]]++;
	printf("%lld",s1[1]*(s2[2]+s2[3])+s1[2]*(s2[1]+s2[3])+s1[3]*(s2[1]+s2[2]+s2[3])-(t[n]==1));
}
int T;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		work();
		putchar('\n');
		for(int i=0;i<=n+1;i++) s[i]=t[i]=vis[i][0]=vis[i][1]=0;
		for(int i=0;i<=n+1;i++) first[i]=0;
	}
}