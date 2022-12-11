#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<cassert>
using namespace std;
int n,m,k,vx[100],vy[100];
long long sum[100];
bool mp[100][100],used[100],tmp[100],vis[2][100];
int match[100],match1[100];
vector<pair<int,int> >ansseq,curseq;
bool dfs(int v)
{
	for(int i=1;i<=n;++i)
		if(mp[v][i]&&!used[i])
		{
			used[i]=1;
			if(!match[i]||dfs(match[i]))
			{
				match[i]=v;
				return 1;
			}
		}
	return 0;
}
int maxmatch()
{
	int cnt=0;
	for(int i=1;i<=n;++i)
	{
		memset(used+1,0,n);
		cnt+=dfs(i);
	}
	// printf("match %d\n",cnt);
	return cnt;
}
void dfs1(int v)
{
	vis[0][v]=1;
	for(int i=1;i<=n;++i)
		if(mp[v][i]&&!vis[1][i])
		{
			vis[1][i]=1;
			dfs1(match[i]);
		}
}
vector<int>minimum_vertex_cover()
{
	for(int i=1;i<=n;++i)if(match[i])match1[match[i]]=i;
	for(int i=1;i<=n;++i)if(!match1[i])dfs1(i);
	vector<int>res;
	for(int i=1;i<=n;++i)if(match1[i]&&!vis[0][i])res.emplace_back(i);
	for(int i=1;i<=n;++i)if(match[i]&&vis[1][i])res.emplace_back(-i);
	return res;
}
int main()
{
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1,x,y;i<=m;++i)
	{
		scanf("%d %d",&x,&y);
		mp[x][y]=1;
	}
	for(int i=1;i<=k;++i)scanf("%d %d",&vx[i],&vy[i]),sum[i]=sum[i-1]+vx[i];
	int cnt=maxmatch();
	vector<int>mvc=minimum_vertex_cover();
	int mi=0x3f3f3f3f,mip=0,t=0;
	long long ans=-1,cur=0;
	for(int i=1;i<=k;++i)
	{
		if(vy[i]<mi)mi=vy[i],mip=i;
		if(cur+sum[k]-sum[i]>ans)
		{
			ans=cur+sum[k]-sum[i];
			ansseq=curseq;
			for(int j=t;j<(int)mvc.size();++j)ansseq.emplace_back(make_pair(i,mvc[j]));
		}
		cur+=vx[i];
		if(i+cnt==n)
		{
			cur-=mi;
			curseq.emplace_back(make_pair(mip,mvc[t]));++t;
			--cnt;
		}
	}
	if(cur>ans)ans=cur,ansseq=curseq;
	printf("%d\n",(int)ansseq.size()+k);
	t=0;
	for(int i=1;i<=k;++i)
	{
		while(t<(int)ansseq.size()&&ansseq[t].first==i)printf("%d ",ansseq[t].second),++t;
		printf("0 ");
	}
	return 0;
}