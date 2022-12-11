#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<vector>
using namespace std;
struct bian
{
	int to,nxt,va;
}bi[400040];
int n,m,c,q,head[100010],num,tot,f[100010],siz[100010];
vector<int>E[100010];
unordered_map<int,int>mp[100010],color[100010];
void add(int from,int to,int va)
{
	bi[++num].nxt=head[from];
	head[from]=num;
	bi[num].to=to;
	bi[num].va=va;
}
int find(int x)
{
	if(x!=f[x])return f[x]=find(f[x]);
	return x;
}
void merge(int x,int y)
{
	if(siz[x]>siz[y])swap(x,y);
//	printf("%d %d\n",x,y);
	siz[y]+=siz[x],f[x]=y;
	for(auto u:E[x])
	{
		E[y].push_back(u);
		for(int i=head[u];i;i=bi[i].nxt)mp[bi[i].to][y]=1;
	}
	E[x].clear();
}
int main()
{
	scanf("%d %d %d %d",&n,&m,&c,&q);
	int x,y,z;
	for(int i=1;i<=n;++i)siz[i]=1,f[i]=i,E[i].push_back(i);
	for(int i=1;i<=m;++i)
	{
		scanf("%d %d %d",&x,&y,&z);
		mp[x][find(y)]=1;
		mp[y][find(x)]=1;
		add(x,y,z),add(y,x,z);
		if(color[x].count(z))
		{
			if(find(color[x][z])!=find(y))merge(find(color[x][z]),find(y));
		}
		else color[x][z]=y;
		swap(x,y);
		if(color[x].count(z))
		{
			if(find(color[x][z])!=find(y))merge(find(color[x][z]),find(y));
		}
		else color[x][z]=y;		
	}
	char op;
	for(int i=1;i<=q;++i)
	{
		scanf(" %c",&op);
		if(op=='+')
		{
			scanf("%d %d %d",&x,&y,&z);
			mp[x][find(y)]=1;
			mp[y][find(x)]=1;
			add(x,y,z),add(y,x,z);
			if(color[x].count(z))
			{
				if(find(color[x][z])!=find(y))merge(find(color[x][z]),find(y));
			}
			else color[x][z]=y;
			swap(x,y);
			if(color[x].count(z))
			{
				if(find(color[x][z])!=find(y))merge(find(color[x][z]),find(y));
			}
			else color[x][z]=y;	
		}
		else
		{
			scanf("%d %d",&x,&y);
			if(find(x)==find(y)||mp[y][find(x)])printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}