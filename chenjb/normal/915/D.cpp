#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <cmath>
#define N 700
#define M 210000
using namespace std;
struct EDGE {int adj,id,next;} edge[M];
int n,m,top,gh[N];
int forbidden,tmp,dfn[N],low[N],cnt,ind,stop,size[N],instack[N],stack[N],belong[N],father[N],pre[N];
int used[M];
int a[N];
void addedge(int x,int y,int id)
{
	edge[++top].adj=y;
	edge[top].next=gh[x];
	edge[top].id=id;
	gh[x]=top;
}
void dfs(int x)
{
	dfn[x]=low[x]=++ind;
	instack[x]=1; stack[++stop]=x;
	for(int p=gh[x];p;p=edge[p].next)
	{
		if (edge[p].id==forbidden)continue;
		if (!dfn[edge[p].adj])
		{
			dfs(edge[p].adj);
			low[x]=min(low[x],low[edge[p].adj]);
		}else if (instack[edge[p].adj])
		{
			low[x]=min(low[x],dfn[edge[p].adj]);
		}
	}
	if (dfn[x]==low[x])
	{
		++cnt; int tmp=0;
		size[cnt]=0;
		while (tmp!=x)
		{
			tmp=stack[stop--];
			belong[tmp]=cnt;
			size[cnt]++;
			instack[tmp]=0;
		}
	}
}
bool check()
{
	stop=ind=cnt=0;
	for(int i=1;i<=n;i++)dfn[i]=0;
	for(int i=1;i<=n;i++)
		if (!dfn[i])dfs(i);
	for(int i=1;i<=cnt;i++)
		if (size[i]>1)return 0;
	return 1;
}
void work()
{
	for(int i=1;i<=m;i++)
		if (used[i])
		{
			forbidden=i;
			if (check()){ puts("YES"); exit(0); }
		}
	puts("NO");
	exit(0);
}
void tarjan(int x)
{
	dfn[x]=low[x]=++ind;
	instack[x]=1; stack[++stop]=x;
	for(int p=gh[x];p;p=edge[p].next)
		if (!dfn[edge[p].adj])
		{
			father[edge[p].adj]=x;
			pre[edge[p].adj]=edge[p].id;
			tarjan(edge[p].adj);
			low[x]=min(low[x],low[edge[p].adj]);
		}
		else if (instack[edge[p].adj])
		{
			tmp++;
			low[x]=min(low[x],dfn[edge[p].adj]);
			int pp=x;
			while (pp!=edge[p].adj)
			{
				used[pre[pp]]=1;
				pp=father[pp];
			}
			used[edge[p].id]=1;
			work();
		}
	if (dfn[x]==low[x])
	{
		++cnt; int tmp=0;
		size[cnt]=0;
		while (tmp!=x)
		{
			tmp=stack[stop--];
			belong[tmp]=cnt;
			size[cnt]++;
			instack[tmp]=0;
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)gh[i]=0; 
	stop=cnt=ind=top=0;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		addedge(x,y,i);
		a[i]=0;
	}
	tmp=0;
	memset(used,0,sizeof(used));
	for(int i=1;i<=n;i++)dfn[i]=0;
	for(int i=1;i<=n;i++)
		if (!dfn[i])tarjan(i);

	puts("YES");


}