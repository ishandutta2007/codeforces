#include<bits/stdc++.h>
using namespace std;
const int N=100005,E=2000005;
int n,i,p,k=1,ch[5000005][2],a[300005],j;
long long ans=0,qa[35],qb[35],s;
vector<int> g[5000005];
void dfs(int i,int y)
{
	if(i<0)
		return;
	if(!y)
		return;
	dfs(i-1,ch[y][0]);
	dfs(i-1,ch[y][1]);
	int l1=0,l2=0;
	int a=ch[y][0],b=ch[y][1];
	long long s=0;
	while(l1<g[a].size()&&l2<g[b].size())
		if(g[a][l1]<g[b][l2])
			g[y].push_back(g[a][l1++]);
		else
		{
			s+=g[a].size()-l1;
			g[y].push_back(g[b][l2++]);
		}
	while(l1<g[a].size())
		g[y].push_back(g[a][l1++]);
	while(l2<g[b].size())
		g[y].push_back(g[b][l2++]);
	qa[i]+=s,qb[i]+=1ll*g[a].size()*g[b].size()-s;
	
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		p=1;
		for(j=30;j>=0;--j)
		{
			if(!ch[p][(a[i]>>j)&1])
				ch[p][(a[i]>>j)&1]=++k;
			p=ch[p][(a[i]>>j)&1];
		}
		g[p].push_back(i);
	}
	dfs(30,1);
	for(i=0;i<=30;++i)
	{
		if(qa[i]>qb[i])
			s|=1<<i;
		ans+=min(qa[i],qb[i]);
	}
	cout<<ans<<' '<<s;
}