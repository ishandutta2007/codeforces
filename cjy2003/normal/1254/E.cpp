#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int mod=1000000007;
vector<pair<int,int> >E[500010];
vector<int>up[500050],l[500050],r[500050];
int n,f[500050],f1[500050],f2[500050],dep[500050],num[500050];
int used[500050],jc[500050],ans=1;
int find(int a,int x)
{
	if(up[a][x]!=x)return up[a][x]=find(a,up[a][x]);
	return x;
}
inline void add(int x,int y)
{
	E[x].push_back(make_pair(y,E[y].size()));
	E[y].push_back(make_pair(x,E[x].size()-1));
}
void dfs(int v,int fa)
{
	dep[v]=dep[fa]+1;
	for(int i=0,u;i<E[v].size();++i)
	{
		u=E[v][i].first;
		if(u==fa)continue;
		f[u]=v;f1[u]=E[v][i].second;f2[u]=i;
		dfs(u,v);
	}
}
int lca(int x,int y)
{
	while(x!=y)
	{
		if(dep[x]>dep[y])x=f[x];
		else y=f[y];
	}
	return x;
}
bool merge(int a,int x,int y)
{
	if(x!=r[a][find(a,x)]||y!=l[a][find(a,y)])return 0;
	x=find(a,x),y=find(a,y);
	if(x==y)return 0;
	up[a][x]=y;l[a][y]=l[a][x];
	++num[a];
	if(find(a,0)==find(a,E[a].size()+1)&&num[a]!=E[a].size()+1)return 0;
	return 1;
}
int st[500050][3];
void work(int x,int y)
{
//	printf("%d %d\n",x,y);
	int l=lca(x,y);
//	printf("%d\n",l);
	int h=1,t=dep[x]+dep[y]-2*dep[l]+1,cnt=t;
	while(x!=l)st[h][0]=x,st[h][2]=f1[x],st[h+1][1]=f2[x],x=f[x],++h;
	while(y!=l)st[t][0]=y,st[t][1]=f1[y],st[t-1][2]=f2[y],y=f[y],--t;
	st[h][0]=l;st[1][1]=-1,st[cnt][2]=E[st[cnt][0]].size();
//	for(int i=1;i<=cnt;++i)printf("%d %d %d\n",st[i][0],st[i][1],st[i][2]);
	for(int i=1;i<=cnt;++i)
		if(!merge(st[i][0],st[i][1]+1,st[i][2]+1))
		{
			printf("0");
			exit(0);
		}
}
int main()
{
	scanf("%d",&n);
	int x,y;
	for(int i=1;i<n;++i)
	{
		scanf("%d %d",&x,&y);
		add(x,y);
	}
	for(int i=1;i<=n;++i)
		for(int j=0;j<=E[i].size()+1;++j)
			up[i].push_back(j),l[i].push_back(j),r[i].push_back(j);
	dfs(1,0);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&x);
		if(x)work(x,i),++used[x],++used[i];
	}
	jc[0]=1;
	for(int i=1;i<=n;++i)jc[i]=1ll*jc[i-1]*i%mod;
	for(int i=1;i<=n;++i)if(E[i].size()>num[i])ans=1ll*ans*jc[E[i].size()-num[i]]%mod;
	printf("%d",ans);
	return 0;
}