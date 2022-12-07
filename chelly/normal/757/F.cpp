#include<bits/stdc++.h>
using namespace std;
const int maxn(333333), N(333333);
int n,m,r;
int parent[maxn],label[maxn],cnt,rel[maxn];
vector<int> edge[maxn],succ[maxn],pred[maxn];
int semi[maxn],idom[maxn],ancestor[maxn],best[maxn];
vector<int> bucket[maxn];
int reldom[maxn];
void dfs(int u) {
	label[u]=++cnt; rel[cnt]=u;
	for(vector<int>::iterator it=edge[u].begin();it!=edge[u].end();++it) {
		int v=*it;if(v==parent[u] || label[v]!=-1) continue;
		parent[v]=u; dfs(v);
	}
}
void link(int v,int w) { ancestor[w]=v; }
void compress(int v) {
	int a=ancestor[v];
	if(ancestor[a]==0) return;
	compress(a);
	if(semi[best[v]]>semi[best[a]]) best[v]=best[a];
	ancestor[v]=ancestor[a];
}

int eval(int v) {
	if(ancestor[v]==0) return v;
	compress(v); return best[v];
}

void dominator() { // clear succ & pred & parent[r],let cnt=0 first
	cnt=0;
	for(int i=1;i<=n;++i){ succ[i].clear(), pred[i].clear(); }
	for(int i=1;i<=n;++i) label[i]=-1;
	parent[r]=-1; dfs(r);// r is root
	for(int u=1;u<=n;++u) {
		for(vector<int>::iterator it=edge[u].begin();it!=edge[u].end();++it) {
			int v=*it;
			if(label[u]!=-1&&label[v]!=-1) {
				succ[label[u]].push_back(label[v]);
				pred[label[v]].push_back(label[u]);
			}
		}
	}
	for(int i=1;i<=n;++i)
		semi[i]=best[i]=i, idom[i]=ancestor[i]=0, bucket[i].clear();
	for(int w=cnt;w >= 2;--w) {
		int p=label[parent[rel[w]]];
		for(vector<int>::iterator it=pred[w].begin();it!=pred[w].end();++it) {
			int v=*it, u=eval(v);
			if(semi[w]>semi[u]) semi[w]=semi[u];
		}
		bucket[semi[w]].push_back(w); link(p,w);
		for(int i=0;i<bucket[p].size();++i) {
			int v=bucket[p][i], u=eval(v);
			idom[v]=(semi[u]<p?u:p);
		}
		bucket[p].clear();
	}
	for(int w=2;w<=cnt;++w) {
		if(idom[w]!=semi[w]) idom[w]=idom[idom[w]];
	}
	idom[1]=0;
	for(int i=1;i<=n;++i) reldom[i]=-1;
	for(int i=2;i<=cnt;++i) {
		int u=rel[idom[i]],v=rel[i];
		// u is immediate dominator of v(i==1?)
		reldom[v]=u;
	}
}
vector<pair<int, int> > adj[N];
vector<int> sons[N];
long long dis[N], inf(1e18);
int siz[N], fa[N];
int main() {
	int m, s;
	scanf("%d%d%d", &n, &m, &s);
	for(int i(1); i <= m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		adj[x].push_back(make_pair(y, z));
		adj[y].push_back(make_pair(x, z));
	}
	fill(dis + 1, dis + 1 + n, inf);
	priority_queue<pair<long long, int> > pq;
	dis[s] = 0;
	pq.push(make_pair(0, s));
	for(;;) {
		while(!pq.empty() && -pq.top().first != dis[pq.top().second])
			pq.pop();
		if(pq.empty()) 
			break;
		int v(pq.top().second);
		pq.pop();
		for(int p(0); p < (int)adj[v].size(); p++) {
			int y(adj[v][p].first);
			if(dis[y] > dis[v] + adj[v][p].second) {
				dis[y] = dis[v] + adj[v][p].second;
				pq.push(make_pair(-dis[y], y));
			}
		}
	}
	for(int i(1); i <= n; i++) {
		for(int p(0); p < (int)adj[i].size(); p++) {
			int y(adj[i][p].first);
			if(dis[i] + adj[i][p].second == dis[y]) {
				edge[i].push_back(y);
			}
		}
	}
	r = s;
	dominator();
	for(int i(1); i <= n; i++) {
		if(reldom[i] != -1) {
			sons[reldom[i]].push_back(i);
		}
	}
	vector<int> q;
	q.push_back(s);
	for(int op(0); op < (int)q.size(); op++) {
		int v(q[op]);
		for(int p(0); p < (int)sons[v].size(); p++) {
			int y(sons[v][p]);
			if(y != fa[v]) {
				fa[y] = v;
				q.push_back(y);
				siz[y] = 1;
			}
		}
	}
	int ans(0);
	for(int i(q.size() - 1); i >= 0; i--) {
		siz[fa[q[i]]] += siz[q[i]];
		if(i != 0)
			ans = max(ans, siz[q[i]]);
	}
	cout << ans << endl;
	
}