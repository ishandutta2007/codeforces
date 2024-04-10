#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
struct node
{
	ll x,y;
	node(ll nx=0,ll ny=0){x=nx;y=ny;}	
};
ll n,m,x,y,l,r,qq,dist[200005],vis[200005];
int cp=0,cnt=0,dfn[200005],low[200005],st[200005],in[200005];
int scc=0,ins[200005];
ll nw=0,a[200005];
vector<node>s[200005];
vector<int>ss[200005];
vector<int>seq;
ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
void dfs(int p)
{
	in[p]=1;
	vis[p]=1;
	seq.push_back(p);
	for(int i=0;i<s[p].size();i++)
	{
		node v=s[p][i];
		if(ins[v.x]!=ins[p])continue;
		if(vis[v.x])
		{
			if(in[v.x])nw=gcd(nw,dist[p]-dist[v.x]+v.y);
			else nw=gcd(nw,dist[p]+v.y+nw-(dist[v.x]%nw));
			continue;
		}
		dist[v.x]=dist[p]+v.y;
		dfs(v.x);
	}
	in[p]=0;
}
void tarjan(int p)
{
	dfn[p]=low[p]=++cnt;
	in[p]=1;
	st[++cp]=p;
	for(int i=0;i<s[p].size();i++)
	{
		int v=s[p][i].x;
		if(!dfn[v])
		{
			tarjan(v);
			low[p]=min(low[p],low[v]);
		}
		else if(in[v])low[p]=min(low[p],dfn[v]);
	}
	if(low[p]==dfn[p])
	{
		scc++;
		int tmp;
		while(cp&&st[cp]!=p)ins[tmp=st[cp--]]=scc,in[tmp]=0;
		ins[tmp=st[cp--]]=scc;in[tmp]=0;
	}
}
int main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&x,&y,&l);
		s[x].push_back(node(y,l));
		ss[y].push_back(x);
	}
	for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i);
	for(int i=1;i<=n;i++)if(!vis[i])
	{
		nw=0;
		seq.clear();
		dfs(i);
		for(int j=0;j<seq.size();j++)a[seq[j]]=nw;
	}
	//printf("@%lld %d\n",a[4],dir[4]);
	scanf("%d",&qq);
	for(int i=1;i<=qq;i++)
	{
		ll v,s,t;
		scanf("%lld%lld%lld",&v,&s,&t);
		ll tmp=gcd(a[v],t);
		//printf("%lld\n",tmp);
		if(s%tmp==0)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}