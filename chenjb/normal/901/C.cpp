#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
#define N 510000
#define M 810000
struct EDGE {int adj,next; }edge[M];
int n,m,q,top,gh[N];
int size[N],dfn[N],low[N],cnt,ind,stop,instack[N],stck[N],belong[N];
void addedge(int x,int y)
{
	edge[++top].adj=y;
	edge[top].next=gh[x];
	gh[x]=top;
}
void tarjan(int x,int pre)
{
	dfn[x]=low[x]=++ind;
	instack[x]=1; stck[++stop]=x;
	for(int p=gh[x];p;p=edge[p].next)
	{
		if (edge[p].adj==pre)continue;
		if (!dfn[edge[p].adj])
		{
			tarjan(edge[p].adj,x);
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
			size[cnt]++;
			tmp=stck[stop--];
			belong[tmp]=cnt;
			instack[tmp]=0;
		}
	}
}
int far[N];
long long mul[N];
void init()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)gh[i]=0;
	top=cnt=ind=stop=0;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		addedge(x,y);
		addedge(y,x);
	}
	for(int i=1;i<=n;i++)dfn[i]=0;
	for(int i=1;i<=n;i++)
		if (dfn[i]==0)tarjan(i,0);
}
int v[N];
void prepare()
{
	
	for(int i=1;i<=n;i++)v[i]=0;
	int tail=1; v[belong[1]]++;
	for(int i=1;i<=n;i++)
	{
		while (tail<n && (v[belong[tail+1]]+1<size[belong[tail+1]]||size[belong[tail+1]]==1)){ v[belong[++tail]]++; }
		far[i]=tail;
		mul[i]=tail-i+1;
		mul[i]+=mul[i-1];
		v[belong[i]]--;
	}
}
int main()
{
	init();
	prepare();
	//for(int i=1;i<=n;i++)printf("%d ",far[i]); puts("");
	//cout<<"cnt="<<cnt<<endl;
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		int left=l; int right=r;
		if (far[l]>r)left=left-1;
		else
		while (left<right)
		{
			int mid=(left+right)/2 + 1;
			if (far[mid]<=r)left=mid; else right=mid-1;
		}
		//cout<<left<<endl;
		long long ans=mul[left]-mul[l-1];
		ans+=(long long)(r-left+1)*(r-left)/2;
		printf("%I64d\n",ans);
	}
}