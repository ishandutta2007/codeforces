#include <bits/stdc++.h>
using namespace std;
const int N=1000005;
int n,k,sum=0,dep[N],father[N][22],bl[N],tot;
vector<int> v[N];

void dfs(int u,int f)
{
	for(int i=0;i<(int)v[u].size();i++)
	{
		int to=v[u][i];
		if(to==f) continue;
		father[to][0]=u; dep[to]=dep[u]+1;
		for(int j=1;j<=20;j++) father[to][j]=father[father[to][j-1]][j-1];
		dfs(to,u);
	}
}

int check(int x)
{
	int now=x;
	for(int i=20;i>=0;i--) 
	{
		if(bl[father[now][i]]==0) now=father[now][i]; 
	}
	return dep[x]-dep[now]+1;
}

void update(int x)
{
	while(!bl[x]) bl[x]=1,x=father[x][0];
}

int main() 
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	bl[0]=1; bl[n]=1;
	dfs(n,0);
	tot=1;
	for(int i=n-1;i>=1;i--)
	{
		if(tot==n-k) break;
		if(bl[i]) continue;
		if(tot+check(i)>n-k) continue;
		tot+=check(i);
		update(i);
	}
	for(int i=1;i<=n;i++) if(!bl[i]) printf("%d ",i);
	return 0;
}