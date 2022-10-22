#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e5+10;
int get_query(int x)
{
	printf("? %d\n",x);
	fflush(stdout);
	scanf("%d",&x);
	return x;
}
struct edge{
	int next,to;
}e[N<<1];
int first[N],len,p[N],d[N],x,y,col[N],cnt,T,vis[N],n;
void add(int a,int b)
{
	e[++len]=edge{first[a],b};
	first[a]=len;
}
void dfs(int x)
{
	col[x]=cnt;
	for(int i=first[x],y;i;i=e[i].next)
		if(!col[y=e[i].to]) dfs(y);
}
bool cmp(int a,int b){return d[a]>d[b];}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&d[i]),p[i]=i;
		sort(p+1,p+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			x=p[i];
			if(vis[x]) continue;
			vis[x]=1;
			for(int j=1;j<=d[x];j++)
			{
				y=get_query(x);
				add(x,y),add(y,x);
				if(vis[y]) break;
				else vis[y]=1;
			}
		}
		for(int i=1;i<=n;i++)
			if(!col[i]) cnt++,dfs(i);
		printf("!");
		for(int i=1;i<=n;i++) printf(" %d",col[i]);
		printf("\n");
		fflush(stdout);
		for(int i=1;i<=n;i++) first[i]=vis[i]=col[i]=0;
		len=cnt=0;
	}
}