#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

const int N = 300000;

pair<vi,int> adj[N+2];
int ans[N+2];
int lab[N+2];
int lab2[N+2];
set<int> adj2[N+2];
vector<ii> edges;

struct DSU
{
	int S;
	
	struct node
	{
		int p; ll sum;
	};
	vector<node> dsu;
	
	DSU(int n)
	{
		S = n;
		for(int i = 0; i < n; i++)
		{
			node tmp;
			tmp.p = i; tmp.sum = 0;
			dsu.pb(tmp);
		}
	}
	
	void reset(int n)
	{
		dsu.clear();
		S = n;
		for(int i = 0; i < n; i++)
		{
			node tmp;
			tmp.p = i; tmp.sum = 0;
			dsu.pb(tmp);
		}
	}
	
	int rt(int u)
	{
		if(dsu[u].p == u) return u;
		dsu[u].p = rt(dsu[u].p);
		return dsu[u].p;
	}
	
	void merge(int u, int v)
	{
		u = rt(u); v = rt(v);
		if(u == v) return ;
		if(rand()&1) swap(u, v);
		dsu[v].p = u;
		dsu[u].sum += dsu[v].sum;
	}
	
	bool sameset(int u, int v)
	{
		if(rt(u) == rt(v)) return true;
		return false;
	}
	
	ll getstat(int u)
	{
		return dsu[rt(u)].sum;
	}
};

deque<int> chain;

void dfs(int u, int p, bool type)
{
	if(type) chain.pb(u);
	else chain.push_front(u);
	int c=0;
	for(sit it = adj2[u].begin(); it != adj2[u].end(); it++)
	{
		int v = (*it);
		if(v==p) continue;
		if(p!=-1)
		{
			dfs(v,u,type);
		}
		else
		{
			dfs(v,u,c);
			c++;
		}
	}
}

int main()
{
	int n, m; scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++)
	{
		int u, v; scanf("%d %d", &u, &v);
		u--; v--;
		adj[u].fi.pb(v);
		adj[v].fi.pb(u);
		edges.pb(mp(u,v));
	}
	for(int i = 0; i < n; i++)
	{
		adj[i].fi.pb(i);
		adj[i].se = i;
		sort(adj[i].fi.begin(),adj[i].fi.end());
	}
	sort(adj,adj+n);
	int cnt = 1;
	for(int i = 0; i < n; i++)
	{
		if(i==0) 
		{
			lab[adj[i].se] = cnt;
		}
		else
		{
			if(adj[i].fi==adj[i-1].fi)
			{
				lab[adj[i].se]=cnt;
			}
			else
			{
				lab[adj[i].se]=++cnt;
			}
		}
	}
	if(cnt==1)
	{
		printf("YES\n");
		for(int i = 0; i < n; i++)
		{
			printf("%d ",lab[i]);
		}
		printf("\n");
		return 0;
	}
	DSU dsu(cnt+1);
	for(int i = 0; i < m; i++)
	{
		int u = edges[i].fi; int v = edges[i].se;
		if(lab[u]!=lab[v])
		{
			adj2[lab[u]].insert(lab[v]);
			adj2[lab[v]].insert(lab[u]);
			dsu.merge(lab[u],lab[v]);
		}
	}
	bool pos = 1;
	for(int i = 1; i <= cnt; i++)
	{
		if(dsu.rt(i)!=dsu.rt(1))
		{
			pos=0;
			break;
		}
	}
	if(!pos)
	{
		printf("NO\n");
		return 0;
	}
	int d1 = 0;
	for(int i = 1; i <= cnt; i++)
	{
		if(adj2[i].size()>2)
		{
			printf("NO\n");
			return 0;
		}
		if(adj2[i].size()==1) d1++;
		else assert(adj2[i].size()==2);
	}
	if(d1==2)
	{
		printf("YES\n");
		dfs(1,-1,0);
		for(int i = 0; i < chain.size(); i++)
		{
			lab2[chain[i]] = i+1;
		}
		for(int i = 0; i < n; i++)
		{
			printf("%d ",lab2[lab[i]]);
		}
		printf("\n");
	}
	else
	{
		printf("NO\n");
		return 0;
	}
}