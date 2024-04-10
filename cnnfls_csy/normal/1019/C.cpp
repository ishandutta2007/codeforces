#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
#define fz1(i,n) for (i=1;i<=n;i++)
#define fd1(i,n) for (i=n;i>=1;i--)
#define fz0g(i,n) for (i=0;i<=n;i++)
#define fd0g(i,n) for (i=n;i>=0;i--)
#define fz0k(i,n) for (i=0;i<n;i++)
#define fd0k(i,n) for (i=(long long)(n-1);i>=0;i--)
#define fz(i,x,y) for (i=x;i<=y;i++)
#define fd(i,y,x) for (i=y;i>=x;i--)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len) {char ss[len];scanf("%s",ss);(st)=ss;}
using namespace std;
int n,m,i,j,col[1000005],dfn[1000005],low[1000005],ti,vis[1000005],x,y,st[1000005],top,cnt2,rd[1000005];
vector<int> bi[1000005],bi2[1000005],ans,seq[1000005],zbi[1000005],zrd,tuopu;
/*void tarjan(int x)
{
	dfn[x]=++ti;
	low[x]=dfn[x];
	st[++top]=x;
	int i;
	for (i=0;i<bi[x].size();i++)
	{
		if (!dfn[bi[x][i]])
		{
			tarjan(bi[x][i]);
			low[x]=min(low[x],low[bi[x][i]]);
		}
		else if (!col[bi[x][i]]) 
			low[x]=min(low[x],dfn[bi[x][i]]);
	}
	if (low[x]==dfn[x])
	{
		cnt2++;
		col[x]=cnt2;
		seq[cnt2].push_back(x);
		while (top&&st[top]!=x)
		{
			seq[cnt2].push_back(st[top]);
			col[st[top]]=cnt2;top--;
		}
		if (top&&st[top]==x) top--;
	}
}*/
void dfs(int x)
{
	if (x>n) return;
	if (vis[x])
	{
		dfs(x+1);
		return;
	}
	vis[x]=1;
	ff(bi[x],it) vis[*it]=1;
	dfs(x+1);
	ff(bi2[x],it) if (vis[*it]==2) vis[x]=0;
	vis[x]++;
}
int main()
{
	scanf("%d%d",&n,&m);
	fz1(i,m)
	{
		scanf("%d%d",&x,&y);
		bi[x].push_back(y);
		//bi2[x].push_back(y);
		bi2[y].push_back(x);
	}
	//fz1(i,n) if (!dfn[i]) dfs(i);
/*	fz1(i,n)
	{
		ff(bi[i],it)
		{
			if (col[*it]!=col[i])
			{
				zbi[col[i]].push_back(col[*it]);
				rd[col[*it]]++;
			}
		}
	}
	fz1(i,cnt2) if (!rd[i]) zrd.push_back(i);
	ff(zrd,it) dfs(*it);
	ff(tuopu,it)
	{
		//cerr<<*it<<' ';
		ff(seq[*it],it2)
		{
			if (vis[*it2]) continue;
			vis[*it2]=2;
			ff(bi2[*it2],it3) vis[*it3]=1;
		}
	}*/
	dfs(1);
	fz1(i,n) if (vis[i]==2) ans.push_back(i);
	printf("%d\n",(int)ans.size());
	ff(ans,it) printf("%d ",*it);
	return 0;
}