#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
#include<set>
#include<map>
#include<vector>
using namespace std;
typedef long long ll;
const ll M=998244353;
const int N=1000005;
int i,j,u,v,k,head[500005],Next[1000005],adj[1000005],q[1000005];
ll dp[500005],ans=100000000000000ll,siz[500005],n;
void Push(int u,int v)
{
	Next[++k]=head[u];
	head[u]=k;
	adj[k]=v;
}
void dfs(int i,int f)
{
	int j;
	siz[i]=1;
	for(j=head[i];j!=0;j=Next[j])
		if(adj[j]!=f)
		{
			dfs(adj[j],i);
			siz[i]+=siz[adj[j]];
		}
}
struct str{
	ll k,b;
}p[500005];
bool cmp(str a,str b)
{
	return a.k<b.k;
}
bool kus(int a,int b,int c,int d)
{
	return ((p[b].b-p[a].b))*(p[d].k-p[c].k)>=(p[d].b-p[c].b)*(p[b].k-p[a].k);
}
void dfs2(int i,int f)
{
	int j,tt=0;
	dp[i]=100000000000000ll;
	for(j=head[i];j!=0;j=Next[j])
		if(adj[j]!=f)
		{
			dfs2(adj[j],i);
			ll t=siz[i]-siz[adj[j]];
			dp[i]=min(dp[i],dp[adj[j]]+1ll*t*(t-1)/2);
			ans=min(ans,dp[adj[j]]+1ll*(n-siz[adj[j]])*(n-siz[adj[j]]-1)/2);
			tt=1;
		}
	if(tt==0)
		dp[i]=0;
	for(j=head[i];j!=0;j=Next[j])
		if(adj[j]!=f)
			dp[adj[j]]=2*dp[adj[j]]-2ll*siz[adj[j]]*n+siz[adj[j]]+1ll*siz[adj[j]]*siz[adj[j]];
	int k=0,l,r;
	ll s=100000000000000ll;
	for(j=head[i];j!=0;j=Next[j])
		if(adj[j]!=f)
			p[++k]=(str){siz[adj[j]],dp[adj[j]]};
	sort(p+1,p+1+k,cmp);
	l=1;
	r=0;
	for(j=1;j<=k;j++)
	{
		while(l<r&&p[q[l]].b+2*p[q[l]].k*p[j].k>=p[q[l+1]].b+2*p[q[l+1]].k*p[j].k)
			l++;
		if(l<=r)
			s=min(s,p[q[l]].b+2*p[q[l]].k*p[j].k+p[j].b);
		while(l<r&&kus(q[r],j,q[r],q[r-1]))
			r--;
		q[++r]=j;
	}
	ans=min(ans,(s+1ll*n*(n-1))/2);
}
int main()
{
	cin>>n;
	for(i=1;i<n;i++)
	{
		scanf("%d %d",&u,&v);
		Push(u,v);
		Push(v,u);
	}
	dfs(1,0);
	dfs2(1,0);
	cout<<1ll*n*(n-1)-ans;
}