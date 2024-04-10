#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int i,n,k,m,p,ch[N][26],id[N],dp[N],siz[N],x[N];
char c;
void dfs(int i,int x)
{
	int j;
	if(id[i])
	{
		siz[i]=1;
		dp[i]=min(dp[i],x+1);
	}
	for(j=0;j<26;++j)
		if(ch[i][j])
		{
			dp[ch[i][j]]=dp[i]+1;
			dfs(ch[i][j],min(dp[i],x)+siz[i]);
			siz[i]+=siz[ch[i][j]];
		}
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d %c",&p,&c);
		ch[p][c-'a']=i;
	}
	scanf("%d",&m);
	for(i=1;i<=m;++i)
	{
		scanf("%d",&x[i]);
		id[x[i]]=i;
	}
	dfs(0,0);
	for(i=1;i<=m;++i)
		printf("%d ",dp[x[i]]);
}