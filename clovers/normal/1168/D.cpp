#include <bits/stdc++.h>
using namespace std;
const int N=160005;
char color[N];
int id[N],n,q,fa[N],dis[N],sum[N];
vector<int> v[N],G[N];

void dfs(int u)
{
	dis[u]=0;
	for(int i=0;i<(int)v[u].size();i++)
	{
		int to=v[u][i];
		dfs(to);
		if(dis[u]&&dis[u]!=dis[to]+1)
		{
			while(q--) puts("Fou");
			exit(0);
		}
		dis[u]=dis[to]+1;
		id[u]=id[to];
	}
	
	if((int)v[u].size()!=1||!u)
	{
		id[u]=u;
		for(int i=0;i<(int)v[u].size();i++)
		{
			int to=v[u][i];
			fa[id[to]]=u;
			G[u].push_back(id[to]);
		}
	}
}

int C[N][26],bl=0,dp[N][26],ttt=0; 
void update(int pos,int c,int num)
{
	C[pos][c]+=num;
	while(fa[pos]!=-1)
	{
		int pre=fa[pos];
		bl-=(sum[pre]>dis[pre]);
		sum[pre]-=dp[pre][c]; dp[pre][c]=0;
		//if(ttt==4) cout<<pre<<" "<<sum[pre]<<endl;
		for(int i=0;i<(int)G[pre].size();i++)
		{
			int to=G[pre][i];
			dp[pre][c]=max(dp[pre][c],dp[to][c]+C[to][c]);
		}
		sum[pre]+=dp[pre][c];
		bl+=(sum[pre]>dis[pre]);
		pos=fa[pos];
	}
}

int main() 
{
	scanf("%d%d",&n,&q);
	for(int i=2;i<=n;i++)
	{
		int x;char c;
		scanf("%d",&x); getchar();
		c=getchar();
		color[i]=c; v[x].push_back(i);
	}
	v[0].push_back(1);
	dfs(0); dis[0]=dis[1]; fa[0]=-1;
	for(int i=2;i<=n;i++) if(color[i]!='?') update(id[i],color[i]-'a',1);
	while(q--)
	{
		ttt++;
		int x; char c;
		scanf("%d",&x); getchar(); 
		c=getchar();
		if(color[x]!='?') update(id[x],color[x]-'a',-1);
		if(c!='?') update(id[x],c-'a',1);
		color[x]=c;
		if(bl)
		{
			puts("Fou");
			continue;
		}
		int ans=0;
		for(int i=0;i<26;i++) ans+=(i+1)*(dis[0]-sum[0]+dp[0][i]);
		printf("Shi ");
		printf("%d\n",ans);
	}
	return 0;
}