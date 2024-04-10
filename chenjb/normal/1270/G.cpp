#include <cstdio>
#include <iostream>	
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
#define LL long long 
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=1;i<=n;++i)
#define x0 gtmshb
#define x1 gtmjtjl
#define y0 gtmsub
#define y1 gtmsf
#define M 1100000
#define N 1100000
#define stack stck
struct EDGE { int adj, next; } edge[2*M];
int n, m, top, tot,gh[N];
int dfn[N], low[N], cnt, ind, stop, instack[N], stack[N], belong[N];
vector<int> q[N];
void addedge(int x, int y) {
	edge[++top].adj = y;
	edge[top].next = gh[x];
	gh[x] = top;
}
void tarjan(int x) {
	dfn[x] = low[x] = ++ind;
	instack[x] = 1; stack[++stop] = x;
	for (int p=gh[x]; p; p=edge[p].next)
		if (!dfn[edge[p].adj]) {
			tarjan(edge[p].adj);
			low[x] = min(low[x], low[edge[p].adj]);
		} else if (instack[edge[p].adj]) {
			low[x] = min(low[x], dfn[edge[p].adj]);
		}
	if (dfn[x] == low[x]) {
		++cnt; int tmp=0;
		q[cnt].clear();
		while (tmp!=x) {
			tmp = stack[stop--];
			belong[tmp] = cnt;
			instack[tmp] = 0;
			q[cnt].pb(tmp);
		}
	}
}
int a[N],b[N],father[N],ans[N];
int flag;
void dfs(int x,int pre)
{
	dfn[x]=++tot;
	father[x]=pre;
	for(int p=gh[x];p;p=edge[p].next)
	if(edge[p].adj!=pre)
	{
		if(!dfn[edge[p].adj])
		{
			father[edge[p].adj]=x;
			dfs(edge[p].adj,x);
		}
		else
		{
			if(flag)break;
			int cnt=0;
			for(int now=x;now!=edge[p].adj;now=father[now])ans[++cnt]=now;
			ans[++cnt]=edge[p].adj;
			flag=1;
			printf("%d\n",cnt);
			rep(j,cnt)printf("%d%c",n-ans[j]+1," \n"[j==cnt]);
			break;
		}
	}
}
int main()
{
	int T;
	cin>>T;
	while (T--)
	{
		scanf("%d",&n);
		
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);

		for(int i=1;i<=n;i++)b[i]=a[i]+n-i+1;
		reverse(b+1,b+n+1);
		flag=0;
		for(int i=1;i<=n;i++)
			if (b[i]==i)
			{
				printf("1\n%d\n",n-i+1);
				flag=1; 
				break;
			}
		if (flag)continue;
		for(int i=1;i<=n;i++)
			if (b[b[i]]==i)
			{
				printf("2\n%d %d\n",n-i+1,n-b[i]+1);
				flag=1;
				break;
			}
		if (flag)continue;

		for(int i=1;i<=n+10;i++)gh[i]=0; top=0;
		for(int i=1;i<=n;i++)addedge(i,b[i]),addedge(b[i],i);
		for(int i=1;i<=n;i++)dfn[i]=0;
		tot=0;
		for(int i=1;i<=n;i++)
			if (!dfn[i])
			{
				dfs(i,0);
				if (flag)break;
			}

	}
}