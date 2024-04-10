#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#define LL long long
#define maxn 100010
using namespace std;
struct node1
{
	int father,son,sum,dep,top;
}tree[maxn];
struct node
{
	int l,r,sum,p;
}st[maxn*5];
vector<int> g[maxn];
int ru[maxn],chu[maxn],seq[maxn],tot;
int w[maxn],father[maxn],sum[maxn];
int fa[maxn];
int n,q;
int getfather(int x)
{
	if (x==fa[x])return x;
	fa[x]=getfather(fa[x]);
	return fa[x];
}
void dfs1(int x,int pre)
{
	int son;
	tree[x].sum=1;
	tree[x].son=0;
	int cnt=g[x].size();
	for(int i=0;i<cnt;i++)
	{
		son=g[x][i];
		if (son==pre)continue;
		tree[son].father=x;
		tree[son].dep=tree[x].dep+1;
		dfs1(son,x);
		tree[x].sum+=tree[son].sum;
		if (tree[x].son==0||tree[tree[x].son].sum<tree[son].sum)tree[x].son=son;
	}
}
void dfs2(int x,int pre)
{
	int son;
	ru[x]=++tot;
	seq[tot]=x;
	if (tree[x].son!=0)
	{
		tree[tree[x].son].top=tree[x].top;
		dfs2(tree[x].son,x);
	}
	int cnt=g[x].size();
	for(int i=0;i<cnt;i++)
	{
		son=g[x][i];
		if (son==tree[x].son||son==pre)continue;
		tree[son].top=son;
		dfs2(son,x);
	}
	chu[x]=tot;
}
void prepare()
{
	tree[1].dep=0;
	tree[1].top=1;
	tree[1].father=0;
	dfs1(1,0); //get tree info
	tot=0;
	dfs2(1,0); // get tree heavyson
	memset(st,0,sizeof(st));
}
int getlca(int x,int y)
{
	while (tree[x].top!=tree[y].top)
	{
		if (tree[tree[x].top].dep>tree[tree[y].top].dep)
		{
			x=tree[tree[x].top].father;
		}
		else
		{
			y=tree[tree[y].top].father;
		}
	}
	if (tree[x].dep<tree[y].dep)return x; 
	else return y;
}
int getsum(int x,int y)
{
	int ans=0;
	while (tree[x].top!=tree[y].top)
	{
		if (tree[tree[x].top].dep>tree[tree[y].top].dep)
		{
			ans=ans-sum[ru[tree[x].top]-1]+sum[ru[x]];
			x=tree[tree[x].top].father;
		}
		else
		{
			ans=ans-sum[ru[tree[y].top]-1]+sum[ru[y]];
			y=tree[tree[y].top].father;
		}
	}
	if (tree[x].dep>tree[y].dep)swap(x,y);
	ans=ans-sum[ru[x]-1]+sum[ru[y]]; 
	return ans;
}
int main()
{
	scanf("%d",&n);	
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&father[i],&w[i]);
		if (father[i]==-1)w[i]==0;
		if (father[i]!=-1){ g[father[i]].push_back(i); fa[getfather(i)]=getfather(father[i]); }
	}
	tot=0;
	for(int i=1;i<=n;i++)
		if (father[i]==-1)
		{
			tree[i].dep=0;
			tree[i].top=i;
			tree[i].father=0;
			dfs1(i,0); //get tree info
			dfs2(i,0); // get tree heavyson
		}
		
	memset(sum,0,sizeof(sum));
	for(int i=1;i<=n;i++)sum[ru[i]]=w[i];
	for(int i=1;i<=n;i++)sum[i]+=sum[i-1];
	scanf("%d",&q);
	
	for(int i=1;i<=q;i++)
	{
		int t,x,y;
		scanf("%d%d%d",&t,&x,&y);
		if (getfather(x)!=getfather(y) || x==y)
		{
			puts("NO");
			continue;
		}
		if (t==1)
		{
			int lca=getlca(x,y);
			int sum=getsum(x,y)-w[lca];
			if (lca!=x || sum!=0)puts("NO");
			else puts("YES"); 
		}
		else
		if (t==2)
		{
			int lca=getlca(x,y);
			int sum1=getsum(x,lca)-w[lca];
			int sum2=getsum(lca,y)-w[lca];
			if (sum1==0 && sum2==tree[y].dep-tree[lca].dep && sum2>0)puts("YES");
			else puts("NO");
		}
	}
}