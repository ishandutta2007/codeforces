#include<bits/stdc++.h>
using namespace std;
const int maxn=2005;
int far[maxn];
char op[maxn][maxn];
int deg[maxn];
vector<int> G[maxn];
void init()
{
	for(int i=0;i<maxn;i++)
		far[i]=i;
}
int Find(int x)
{
	if(x==far[x]) return x;
	return far[x]=Find(far[x]);
}
int num;
void Union(int x,int y)
{
	x=Find(x),y=Find(y);
	deg[x]+=deg[y];
	if(x!=y) num--;
	far[y]=x;
}
int dp[maxn];
int topo[maxn];
int vis[maxn];
int tot=0;
int n,m;
bool toposort()
{
	queue<int> q;
	for(int i=0;i<n+m;i++)
	{
		if(deg[Find(i)]==0&&!vis[Find(i)])
		{
			vis[Find(i)]=1;
			q.push(Find(i));
		}
	}
	while(!q.empty())
	{
		int cur=q.front();q.pop();
		topo[++tot]=cur;
		for(int i=0;i<G[cur].size();i++)
		{
			int v=G[cur][i];
			deg[v]--;
			if(!deg[v]) q.push(v);
		}
	}
	return tot==num;
}
int main()
{
	init();
	scanf("%d%d",&n,&m);
	num=n+m;
	for(int i=0;i<n;i++) 
	{
		scanf("%s",op[i]);
		for(int j=0;j<m;j++)
		{
			if(op[i][j]=='=')
			{
				Union(i,j+n);
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(op[i][j]=='>')
			{
				deg[Find(i)]++;
				G[Find(j+n)].push_back(Find(i));
			}
			else if(op[i][j]=='<'){
				deg[Find(j+n)]++;
				G[Find(i)].push_back(Find(j+n));
			}
		}
	}
	if(!toposort()) puts("NO");
	else{
		puts("YES");
		for(int i=0;i<=n+m;i++)
			dp[i]=1;
		for(int i=1;i<=num;i++)
		{
			int cur=topo[i];
			for(int j=0;j<G[cur].size();j++)
			{
				int v=G[cur][j];
				dp[v]=max(dp[v],dp[cur]+1);
			}
		}
		for(int i=0;i<n;i++)
			printf("%d ",dp[Find(i)]);
		puts("");
		for(int i=0;i<m;i++)
			printf("%d ",dp[Find(i+n)]);
		puts("");
	}
}