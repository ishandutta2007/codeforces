#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int maxn=4e5+7;
struct Query{
	int op,x,y;
	int e0,e1;
}q[maxn];
int fa[maxn],sz[maxn];
int n,m;
void init()
{
	for(int i=0;i<=n;i++) fa[i]=i,sz[i]=1;
}
int Find(int x)
{
	return x==fa[x]?x:Find(fa[x]);
}
vector<int> used;
void Union(int x,int y)
{
	x=Find(x),y=Find(y);
	if(x==y) return;
	if(sz[x]>sz[y]) swap(x,y);
	fa[x]=y;
	sz[y]+=sz[x];
	used.push_back(x);
}
int ans[maxn];
int var;
bool vis[maxn*2],state[maxn*2];
set<int> cur;
PII edge[maxn*2];
void rebuild(int l)
{
	init();
	cur.clear();
	memset(vis,0,sizeof(vis));
	memset(state,0,sizeof(state));
	for(int i=l;i<min(l+var,m);i++)
	{
		if(q[i].op==1)
		{
			vis[q[i].e1]=1;
			vis[q[i].e0]=1;
		}
	}
	for(int i=0;i<l;i++)
	{
		if(q[i].op==2) continue;
		int e=ans[i]?q[i].e1:q[i].e0;
		state[e]^=1;
	}
	for(int i=0;i<l;i++)
	{
		if(q[i].op==1)
		{
			int e=ans[i]?q[i].e1:q[i].e0;
			if(state[e]&&!vis[e])
				Union(edge[e].first,edge[e].second);
			else if(state[e])
				cur.insert(e);
		}
	}
	used.clear();
}
void rollback()
{
	reverse(used.begin(),used.end());
	for(auto u:used)
	{
		sz[fa[u]]-=sz[u];
		fa[u]=u;
	}
	used.clear();
}
map<PII,int> num;
int cnt;
int getid(int x,int y)
{
	if(x>y) swap(x,y);
	if(!num.count(make_pair(x,y)))
	{
		num[make_pair(x,y)]=++cnt;
		edge[cnt]=make_pair(x,y);
	}
	return num[make_pair(x,y)];
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	string op;
	cin>>n>>m;
	var=sqrt(m);
	for(int i=0;i<m;i++)
		cin>>q[i].op>>q[i].x>>q[i].y;
	for(int i=0;i<m;i++)
	{
		int u=(q[i].x-1)%n+1,v=(q[i].y-1)%n+1;
		q[i].e0=getid(u,v);
		u=q[i].x%n+1,v=q[i].y%n+1;
		q[i].e1=getid(u,v);
	}
	for(int i=0;i<m;i+=var)
	{
		rebuild(i);
		for(int j=i;j<min(m,i+var);j++)
		{
			int e=ans[j]?q[j].e1:q[j].e0;
			if(q[j].op==1)
			{
				rollback();
				auto it=find(cur.begin(),cur.end(),e);
				if(it==cur.end())
					cur.insert(e);
				else cur.erase(it);
				ans[j+1]=ans[j];
			}
			else{
				for(auto u:cur)
					Union(edge[u].first,edge[u].second);
				ans[j+1]=(Find(edge[e].first)==Find(edge[e].second));
				op+=ans[j+1]+'0';
			}
		}
	}
	cout<<op<<endl;

}