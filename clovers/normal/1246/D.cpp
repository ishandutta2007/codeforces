#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
using namespace std;
const int N=1e5+100;
int n,de[N],dfn[N],w,fa[N],f[N];
vector <int> e[N],ans;
void dfs(int x)
{
	for (int i=0;i<(int)e[x].size();i++)
	{
		int u=e[x][i];
		de[u]=de[x]+1;
		dfs(u);
	}
	for (int i=0;i<(int)e[x].size();i++)
	{
		int u=e[x][i];
		de[x]=max(de[x],de[u]);
	}
}
void dfs1(int x)
{
	dfn[w++]=x;
	for (int i=0;i<(int)e[x].size();i++)
	{
		int u=e[x][i];
		dfs1(u);
	}
}
bool cmp(int a,int b){return de[a]<de[b];}
signed main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		scanf("%d",&fa[i]);
		e[fa[i]].push_back(i);
	}
	dfs(0);
	for (int i=0;i<n;i++) sort(e[i].begin(),e[i].end(),cmp);
	dfs1(0);
	for (int i=0;i<n;i++) printf("%d ",dfn[i]);
	printf("\n");
	for (int i=1;i<n;i++) f[dfn[i]]=dfn[i-1];
	for (int i=1;i<n;i++)
	{
		while (f[dfn[i]]!=fa[dfn[i]])
		{
			f[dfn[i]]=f[f[dfn[i]]];
			ans.push_back(dfn[i]);
		}
	}
	printf("%d\n",(int)ans.size());
	for (int i=0;i<(int)ans.size();i++) printf("%d ",ans[i]);
	printf("\n");
}