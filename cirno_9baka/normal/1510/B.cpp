#include<bits/stdc++.h>
using namespace std;
const int N=10005,E=1010105,inf=1010111;
int head[N],Next[E],adj[E],cap[E],cost[E];
int q[N*20],pre[N],vis[N],now[N];
int flow,S,T,num=1;
long long d[N];
void addedge(int u,int v,int f,int w)
{
	//cout<<u<<' '<<v<<endl;
	Next[++num]=head[u],head[u]=num,adj[num]=v,cap[num]=f,cost[num]=w;
	Next[++num]=head[v],head[v]=num,adj[num]=u,cap[num]=0,cost[num]=-w;
}
bool SPFA()
{
	int i,l,r;
	q[l=r=1]=S;
	vis[S]=1;
	memset(d,0x7f,sizeof(d));
	d[S]=0;
	while(l<=r)
	{
		for(i=head[q[l]];i;i=Next[i])
			if(cap[i]&&d[adj[i]]>d[q[l]]+cost[i])
			{
				d[adj[i]]=d[q[l]]+cost[i];
				if(!vis[adj[i]])
				{
					vis[adj[i]]=1;
					q[++r]=adj[i];
				}
			}
		vis[q[l]]=0;
		++l;
	}
	return (d[T]<1<<30);
}
bool dfs(int i,int f)
{
	if(i==T)
	{
		flow=f;
		return true;
	}
	if(vis[i])
		return false;
	int j;
	vis[i]=1;
	for(j=now[i];j;now[i]=j=Next[j])
		if(cap[j]&&d[adj[j]]==d[i]+cost[j]&&dfs(adj[j],min(f,cap[j])))
		{
			cap[j]-=flow;
			cap[j^1]+=flow;
			vis[i]=0;
			return true;
		}
	vis[i]=0;
	return false;
}
long long ans,ansf;
void minmax()
{
	while(SPFA())
	{
		if(d[T]>0)
			break;
		memcpy(now,head,sizeof(now));
		while(dfs(S,inf))
			ans+=flow*d[T],ansf+=flow;
	}
}
int a[N],e,n,i,nex[N],vi[N],j;
char c[2005];
vector<int> as;
void dfs(int i)
{
	int j;
	if(nex[i])
		dfs(nex[i]);
	int s=a[nex[i]]^a[i];
	//cout<<i<<' '<<s<<endl;
	for(j=0;j<e;++j)
		if(s>>j&1)
			as.push_back(j);
}
int main()
{
	scanf("%d %d",&e,&n);
	for(i=1;i<=n;++i)
	{
		scanf("%s",c);
		int s=0;
		for(j=0;c[j];++j)
			s=s+(c[j]-'0'?1<<j:0);
		a[i]=s;
		ans+=__builtin_popcount(a[i])+1;
	}
	--ans;
	S=0,T=2*n+1;
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
			if(i!=j)
				if((a[i]&a[j])==a[j])
					addedge(i,j+n,1,-__builtin_popcount(a[j])-1);
	for(i=1;i<=n;++i)
	{
		addedge(S,i,1,0);
		addedge(i+n,T,1,0);
	}
	minmax();
	cout<<ans<<endl;
	for(i=1;i<=n;++i)
		for(j=head[i];j;j=Next[j])
			if(adj[j]>=n+1&&adj[j]<=2*n&&!cap[j])
				nex[i]=adj[j]-n;
	for(i=1;i<=n;++i)
		vi[nex[i]]=1;
	for(i=1;i<=n;++i)
		if(!vi[i])
		{
			dfs(i);
			as.push_back(e);
		}
	as.pop_back();
	for(auto it:as)
		if(it==e)
			printf("R ");
		else
			printf("%d ",it);
}
/*#include<bits/stdc++.h>
using namespace std;
int n,i,j,vis[2005],l[2005],r[2005],nx[2005][4],al[2005],ar[2005];
int dp[2005][4];
bool cmp(int a,int b)
{
	return l[a]<l[b];
}
int p[2005],k,ct[2005];
vector<int> g[2005];
void dfs(int i)
{
	int k=0;
	for(auto j:g[i])
		dfs(j);
	for(auto j:g[i])
		p[++k]=j;
	if(k==0)
	{
		dp[i][0]=dp[i][1]=dp[i][2]=dp[i][3]=r[i]-l[i];
		return;
	}
	p[0]=p[k+1]=0;
	int j,s=0,e,m;
	l[0]=r[i];
	r[0]=l[i];
	for(j=0;j<4;++j)
	{
		ct[1]=j&1;
		ct[k]|=j&2;
		for(e=0;e<=k;++e)
		{
			int t1=ct[e],t2=ct[e+1];
			ct[e]|=2;
			ct[e+1]|=1;
			int s=l[p[e+1]]-r[p[e]]+((j&1)&&e!=0?l[p[1]]-l[i]:0)+((j&2)&&e!=k?r[i]-r[p[k]]:0);
			//cout<<j<<' '<<s<<' '<<l[p[e+1]]-r[p[e]]<<endl;
			for(m=1;m<=k;++m)
				s+=dp[p[m]][ct[m]];
			if(s>dp[i][j])
			{
				dp[i][j]=s;
				nx[i][j]=e;
			}
			ct[e]=t1,ct[e+1]=t2;
		}
	}
	cout<<i<<' '<<dp[i][0]<<' '<<dp[i][1]<<' '<<dp[i][2]<<' '<<dp[i][3]<<endl;
}
void Gans(int i,int t,int u,int v)
{
	int c[2005],k=0,p[2005],uu[2005],vv[2005];
	memset(c,0,sizeof(c));
	memset(uu,0,sizeof(uu));
	memset(vv,0,sizeof(vv));
	for(auto j:g[i])
		p[++k]=j;
	if(k==0)
	{
		ar[u]=l[i];
		al[v]=r[i];
		al[i]=l[i],ar[i]=r[i];
		return;
	}
	c[1]=t&1,c[k]=t&2;
	uu[1]=u,vv[k]=v;
	c[nx[i][t]]|=2;
	vv[nx[i][t]]=uu[nx[i][t]]=i;
	c[nx[i][t]+1]|=1;
	if(nx[i][t]==0)
		ar[u]=l[i];
	if(nx[i][t]==k)
		al[v]=r[i];
	int j;
	for(j=1;j<=k;++j)
		Gans(p[j],c[j],uu[j],vv[j]);
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    scanf("%d",&n);
    for(i=1;i<=n;++i)
    	scanf("%d %d",&l[i],&r[i]);
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
			if(l[i]<l[j]&&r[i]>r[j])
			{
				g[i].push_back(j);
				vis[j]=1;
			}
	for(i=1;i<=n;++i)
		sort(g[i].begin(),g[i].end(),cmp);
	int ans=0;
	for(i=1;i<=n;++i)
		if(!vis[i])
		{
			dfs(i);
			ans+=dp[i][0];
			Gans(i,0,0,0);
		}
	printf("%d\n",ans);
	for(i=1;i<=n;++i)
		printf("%d %d\n",al[i],ar[i]);
}*/