#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#define INF 1000000000
#define N 200005
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int dp[N],fa[N],lf[N],m;
vector<int> G[N];
void dfs1(int x,int d)
{
	int v,i;
	if(d==1) dp[x]=INF;
	else dp[x]=0;
	for(i=0;i<G[x].size();i++)
	{
		v=G[x][i];
		if(fa[x]!=v)
		{
			lf[x]=1;
			fa[v]=x;
			dfs1(v,d^1);
			if(d==1)
				dp[x]=min(dp[x],dp[v]);
			else dp[x]+=dp[v];
		}
	}
	if(!lf[x])
		dp[x]=1,m++;
}

void dfs2(int x,int d)
{
	int v,i;
	if(d==1) dp[x]=0;
	else dp[x]=INF;
	for(i=0;i<G[x].size();i++)
	{
		v=G[x][i];
		if(fa[x]!=v)
		{
			lf[x]=1;
			fa[v]=x;
			dfs2(v,d^1);
			if(d==1)
				dp[x]+=dp[v];
			else dp[x]=min(dp[x],dp[v]);
		}
	}
	if(!lf[x])
		dp[x]=1;
	//debug(x);
	//debug(dp[x]);
}

int main()
{
	int n,i,a,b;
	cin>>n;
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		G[a].push_back(b);
		//G[b].push_back(a);
	}
	dfs1(1,1);
	cout<<m-dp[1]+1<<' ';
	dfs2(1,1);
	cout<<dp[1]<<endl;
	return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);