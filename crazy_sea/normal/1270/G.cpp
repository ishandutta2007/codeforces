#include<cstdio>
using namespace std;
const int N=1e6+10; 
int T,n,to[N],x,len,t[N],vis[N];
void dfs(int x)
{
	t[vis[x]=++len]=x;
	if(vis[to[x]])
	{
		printf("%d\n",len-vis[to[x]]+1);
		for(int i=vis[to[x]];i<=len;i++) printf("%d ",t[i]);
		printf("\n");
	}
	else dfs(to[x]);
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&x),to[i]=i-x;
		len=0,dfs(1),len=0;
		for(int i=1;i<=n;i++) vis[i]=0;
	}
}