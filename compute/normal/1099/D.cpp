#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
const long long INF=0x3f3f3f3f;
vector<int> G[maxn];
long long sum[maxn];
long long ans[maxn];
long long need[maxn];
long long dfs(int cur)
{
	if(!G[cur].size()) 
	{
		need[cur]=INF;
		if(sum[cur]==-1) return INF;
		else return sum[cur];
	}
	long long se=INF;
	for(int i=0;i<G[cur].size();i++)
	{
		int v=G[cur][i];
		se=min(se,dfs(v));
	}
	if(sum[cur]!=-1) return sum[cur];
	return need[cur]=se;
}
void dfs2(int cur,long long val)
{
	if(sum[cur]==-1)
	{
		ans[cur]=need[cur]-val;
		if(need[cur]>=INF) ans[cur]=0;
	}
	else ans[cur]=sum[cur]-val;
	for(int i=0;i<G[cur].size();i++)
	{
		int v=G[cur][i];
		dfs2(v,val+ans[cur]);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=2,v;i<=n;i++)
	{
		scanf("%d",&v);
		G[v].push_back(i);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&sum[i]);
	}
	dfs(1);
	dfs2(1,0);
	long long outp=0;
	bool ok=1;
	for(int i=1;i<=n;i++)
	{
		outp+=ans[i];
		if(ans[i]<0) ok=0;
	}
	if(ok) printf("%lld\n",outp);
	else puts("-1");
}