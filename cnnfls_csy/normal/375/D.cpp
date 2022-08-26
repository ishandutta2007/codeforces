#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
using namespace std;
int n,m,i,j,x,y,ycol[100005],col[100005],cntcol[100005],first[100005],last[100005],cl=1,cr,ti,num[100005];
int lowbit(int x) {return x&(-x);}
void add(int x,int y)
{
	int i;
	for (i=x;i<=100000;i+=lowbit(i)) num[i]+=y;
}
int sum(int x)
{
	int s=0,i;
	for (i=x;i>0;i-=lowbit(i)) s+=num[i];
	return s;
}
struct query
{
	int ql,qr,ans,id,ll;
}qu[100005];
vector<int> bi[100005];
bool cmpq(query x,query y)
{
	return x.ql/320*100000+x.qr<y.ql/320*100000+y.qr;
}
bool cmpid(query x,query y)
{
	return x.id<y.id;
}
void dfs(int x,int fa)
{
	first[x]=++ti;
	col[ti]=ycol[x];
	int i;
	for (i=0;i<bi[x].size();i++)
	{
		if (bi[x][i]!=fa)
		{
			dfs(bi[x][i],x);
		}
	}
	last[x]=ti;
}
void update(int x,int y)
{
	add(cntcol[x]+1,-1);
	cntcol[x]+=y;
	add(cntcol[x]+1,1);
}
int main()
{
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&ycol[i]);
	}
	for (i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		bi[x].push_back(y);
		bi[y].push_back(x);
	}
	dfs(1,0);
	for (i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		qu[i]={first[x],last[x],0,i,y};
	}
	sort(qu+1,qu+m+1,cmpq);
	for (i=1;i<=m;i++)
	{
		while (cl>qu[i].ql)
		{
			cl--;
			update(col[cl],1);
		}
		while (cr<qu[i].qr)
		{
			cr++;
			update(col[cr],1);
		}
		while (cl<qu[i].ql)
		{
			update(col[cl],-1);
			cl++;
		}
		while (cr>qu[i].qr)
		{
			update(col[cr],-1);
			cr--;
		}
		qu[i].ans=sum(100001)-sum(qu[i].ll);
	}
	sort(qu+1,qu+m+1,cmpid);
	for (i=1;i<=m;i++)
	{
		printf("%d\n",qu[i].ans);
	}
	return 0;
}