#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<cassert>
using namespace std;
const long long inf=0x3f3f3f3f3f3f3f3fll;
vector<pair<int,int> >E[500050];
multiset<long long>dval[250050];
multiset<long long>now[250050];
int n,d[250050],p[250050];
long long dp[250050][2],ans,sum[250050];
bool cmp(pair<int,int>a,pair<int,int>b){return d[a.first]>d[b.first];}
bool cmp1(int a,int b){return d[a]>d[b];}
bool vis[250050];
void ins(int x,int w,int lim)
{
	dval[x].insert(w);
	sum[x]+=w;
}
void dfs(int v,int fa,int lim)
{
	int ned=d[v]-lim;	
	while(dval[v].size()>ned)
	{
		auto it=dval[v].end();
		--it;
		sum[v]-=*it;
		dval[v].erase(it);
	}
//	printf("%d ",v);
	vis[v]=1;
	long long tot=0;
	vector<long long>now,del,add;
	for(auto u:E[v])
	{
		if(d[u.first]<=lim)break;
		if(u.first==fa)continue;
		dfs(u.first,v,lim);
		if(dp[u.first][1]+u.second<=dp[u.first][0])--ned,tot+=dp[u.first][1]+u.second;
		else now.push_back(dp[u.first][1]+u.second-dp[u.first][0]),tot+=dp[u.first][0];
	}
	if(ned<=0)
	{
		dp[v][0]=dp[v][1]=tot;
		return ;
	}
	dp[v][0]=dp[v][1]=inf;
	sort(now.begin(),now.end());
	while(dval[v].size()>ned)
	{
		auto it=dval[v].end();--it;
		sum[v]-=*it;del.push_back(*it);dval[v].erase(it);
	}
	for(auto x:now)
	{
		if(dval[v].size()<ned)
		{
			sum[v]+=x;
			add.push_back(x);dval[v].insert(x);
		}
		else
		{
			auto it=dval[v].end();--it;
			if(x<*it)
			{
				sum[v]-=*it;
				del.push_back(*it),dval[v].erase(it);
				sum[v]+=x;
				dval[v].insert(x),add.push_back(x); 
			}	
		}
	}
	if(dval[v].size()==ned)
	{
		dp[v][0]=sum[v]+tot;
		auto it=dval[v].end();--it;
		dp[v][1]=sum[v]-*it+tot;
	}
	if(dval[v].size()==ned-1)dp[v][1]=sum[v]+tot;
	for(auto x:add)sum[v]-=x,dval[v].erase(dval[v].lower_bound(x));
	for(auto x:del)sum[v]+=x,dval[v].insert(x);
}
int main()
{
	scanf("%d",&n);
	int x,y,w;
	for(int i=1;i<n;++i)
	{
		scanf("%d %d %d",&x,&y,&w);
		E[x].push_back(make_pair(y,w));
		E[y].push_back(make_pair(x,w));
		++d[x],++d[y];
	}
	for(int i=1;i<=n;++i)
		sort(E[i].begin(),E[i].end(),cmp),p[i]=i;
	sort(p+1,p+1+n,cmp1);
	int last=n;
	for(int i=0;i<n;++i)
	{
		ans=0;
		while(d[p[last]]<=i&&last>0)
		{
			for(auto u:E[p[last]])
				if(d[u.first]>i)ins(u.first,u.second,d[u.first]-i);	
			--last;		
		}
		for(int j=1;d[p[j]]>i&&j<=n;++j)
			if(!vis[p[j]])dfs(p[j],0,i),ans+=dp[p[j]][0];
	//	printf("%d\n",i);
	//	printf("!");
	//	for(int j=1;j<=n;++j)
	//		printf("%lld %lld\n",dp[j][0],dp[j][1]);
		for(int j=1;d[p[j]]>i&&j<=n;++j)vis[p[j]]=0;
		printf("%lld ",ans);
	}
	return 0;
}