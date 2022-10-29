#include<bits/stdc++.h>
using namespace std;
const int N=200005;

int n,f[N],color[N],tot=0;
vector<int> v[N];

void dfs(int u)
{
	int now=0;
	for(int i=0;i<(int)v[u].size();i++)
	{
		int to=v[u][i];
		if(to==f[u]) continue;
		f[to]=u;
		now++;
		while(now==color[u]||now==color[f[u]]) now++;
		color[to]=now;
		dfs(to);
	}
	tot=max(tot,now);
}

int main()
{
	scanf("%d",&n);//
	for(int i=1;i<n;i++) 
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	color[1]=1; tot=1;
	dfs(1);
	printf("%d\n",tot);
	for(int i=1;i<=n;i++) printf("%d ",color[i]);
	return 0;
}