#include<cstdio>
#include<vector>
#define N 200010
using namespace std;
struct edge{
	int next,to;
}e[N<<1];
int first[N],len,dep[N],p[N],x,y,ans[N],T,n;
void add(int a,int b)
{e[++len]=(edge){first[a],b},first[a]=len;}
vector<int>v[2];
void dfs(int x)
{
	v[dep[x]&1].push_back(x);
	for(int i=first[x];i;i=e[i].next)
		if(!dep[y=e[i].to]) dep[y]=dep[x]+1,dfs(y);
}
void work(int x)
{
	for(int i=(1<<x);i<(1<<(x+1));i++)
		ans[v[0][y++]]=i,p[i]=1;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) first[i]=dep[i]=p[i]=0;
		for(int i=1;i<n;i++)
			scanf("%d%d",&x,&y),add(x,y),add(y,x);
		dep[1]=1; dfs(1);
		if(v[0].size()>v[1].size()) v[0].swap(v[1]);
		x=v[0].size(); y=0;
		for(int i=0;(1<<i)<=x;i++)
			if(x&(1<<i)) work(i);
		v[0].clear();
		for(int i=1;i<=n;i++)
			if(!p[i]) v[0].push_back(i);
		for(int i=0;i<v[0].size();i++)
			ans[v[1][i]]=v[0][i];
		v[0].clear(),v[1].clear();
		for(int i=1;i<=n;i++) printf("%d ",ans[i]);
		putchar('\n');
	}
}