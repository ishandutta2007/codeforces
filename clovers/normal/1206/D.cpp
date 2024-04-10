#include<bits/stdc++.h>
using namespace std;
const int N=205;
const int inf=(int)1e9;

int dis[N],E[N][N],vis[N];
int n=1,t,ans=inf;
long long a[N];

int bfs(int from,int to)
{
	for(int i=1;i<=n;i++) dis[i]=inf,vis[i]=0;
	queue<int> q;
	q.push(from); dis[from]=0; vis[from]=1;
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		for(int i=1;i<=n;i++)
		{
			if(i==to&&u!=from&&E[u][i]) return dis[u]+2;
			if(vis[i]||!E[u][i]||i==to) continue;//1 
			dis[i]=dis[u]+1;
			q.push(i); vis[i]=1;
		}
	}
	return inf;
}

int main()
{
	scanf("%d",&t);
	for(int i=1;i<=t;i++) 
	{
		scanf("%lld",&a[n]);
		if(a[n]) n++;
		if(n>200)
		{
			puts("3");
			return 0;
		}
	}
	n--;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			if(a[i]&a[j]) E[i][j]=1,E[j][i]=1;
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++) cout<<E[i][j]; cout<<endl;
//	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{	
			if(!E[i][j]) continue;//DP 
			int tmp=bfs(i,j);
			if(tmp<ans) ans=tmp;
		}
	}
	if(ans==inf) puts("-1");
	else cout<<ans<<endl;
	return 0;
}