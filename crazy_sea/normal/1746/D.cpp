#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=2e5+10;
vector<int> to[N];
int v[N],s[N],dp[N];
long long ans;
bool cmp(int x,int y)
{
	return dp[x]>dp[y];
}
void dfs1(int x,int k)
{
	int len=to[x].size();
	if(len==0)
	{
		dp[x]=s[x];
		return;
	}
	for(int y:to[x]) dfs1(y,k/len);
	sort(to[x].begin(),to[x].end(),cmp);
	dp[x]=dp[to[x][k%len]]+s[x];
}
void dfs2(int x,int k,int a)
{
	if(k==0) return;
	a+=s[x];
	int len=to[x].size();
	if(len==0)
	{
		ans+=1ll*k*a;
		return;
	}
	sort(to[x].begin(),to[x].end(),cmp);
	for(int i=0;i<k%len;i++) dfs2(to[x][i],k/len+1,a);
	for(int i=k%len;i<len;i++) dfs2(to[x][i],k/len,a);
}
int main()
{
	int T,n,m,x;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=2;i<=n;i++)
			scanf("%d",&x),to[x].push_back(i);
		for(int i=1;i<=n;i++) scanf("%d",&s[i]);
		dfs1(1,m);
		dfs2(1,m,0);
		printf("%lld\n",ans);
		for(int i=1;i<=n;i++) to[i].clear();
		ans=0;
	}
}