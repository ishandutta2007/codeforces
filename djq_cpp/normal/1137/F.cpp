#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 1e9 + 7;

int n, q;
vector<int> G[200005];
int siz[200005], par[200005], dep[200005];
int hson[200005], rt[200005];

void dfs1(int v)
{
	siz[v] = 1;
	rep(i, G[v].size()) {
		int u = G[v][i];
		if(u == par[v]) continue;
		par[u] = v;
		dep[u] = dep[v] + 1;
		dfs1(u);
		siz[v] += siz[u];
	}
	
	hson[v] = -1;
	rep(i, G[v].size()) {
		int u = G[v][i];
		if(u == par[v]) continue;
		if(hson[v] == -1 || siz[u] > siz[hson[v]]) hson[v] = u;
	}
}

void dfs2(int v)
{
	if(par[v] == -1 || v != hson[par[v]]) rt[v] = v;
	else rt[v] = rt[par[v]];
	rep(i, G[v].size()) {
		int u = G[v][i];
		if(u == par[v]) continue;
		dfs2(u);
	}
}

void gen_info()
{
	par[1] = -1;
	dep[1] = 0;
	dfs1(1);
	dfs2(1);
}

struct fwt
{
	int dat[400005];
	void upd(int id, int v)
	{
		while(id <= 400000) {
			dat[id] += v;
			id += id & -id;
		}
	}
	int sum(int id)
	{
		int ret = 0;
		while(id > 0) {
			ret += dat[id];
			id -= id & -id;
		}
		return ret;
	}
}arr;

void t_modify(int id, int v)
{
	arr.upd(id, v);
}

int dist(int u, int v)
{
	int ret = 0;
	while(rt[u] != rt[v]) {
		if(dep[rt[u]] < dep[rt[v]]) swap(u, v);
		int maxd = dep[u];
		u = par[rt[u]];
		ret += maxd - dep[u];
	}

	if(dep[u] < dep[v]) swap(u, v);
	ret += dep[u] - dep[v];
	return ret;
}

set<pair<PII, int> > st[200005];
void update(int u, int v, int val)
{
	while(rt[u] != rt[v]) {
		if(dep[rt[u]] < dep[rt[v]]) swap(u, v);
		
		int maxd = dep[u];
		u = rt[u];
		
		set<pair<PII, int> >::iterator it;
		while(!st[u].empty() && (it = st[u].begin())->first.second <= maxd) {
			t_modify(it->second, it->first.first - it->first.second - 1);
			st[u].erase(it);
		}
		if(!st[u].empty() && (it = st[u].begin())->first.first <= maxd) {
			pair<PII, int> cur = *it;
			t_modify(cur.second, cur.first.first - maxd - 1);
			cur.first.first = maxd + 1;
			st[u].erase(it);
			st[u].insert(cur);
		}
		t_modify(val, maxd - dep[u] + 1);
		st[u].insert(MP(MP(dep[u], maxd), val));
		u = par[u];
	}
	
	if(dep[u] < dep[v]) swap(u, v);
	
	int du = dep[u], dv = dep[v];
	u = rt[u];
	
	set<pair<PII, int> >::iterator it;
	while((it = st[u].lower_bound(MP(MP(dv, dv), -1))) != st[u].end()) {
		if(it->first.first > du) break;
		else if(it->first.second > du) {
			pair<PII, int> cur = *it;
			t_modify(cur.second, cur.first.first - du - 1);
			cur.first.first = du + 1;
			st[u].erase(it);
			st[u].insert(cur);
			it = st[u].find(cur);
			break;
		} else {
			t_modify(it->second, it->first.first - it->first.second - 1);
			st[u].erase(it);
		}
	}
	if(it != st[u].begin()) {
		it --;
		if(it->first.second >= dv)  {
			pair<PII, int> cur = *it;
			t_modify(cur.second, dv - cur.first.second - 1);
			cur.first.second = dv - 1;
			st[u].erase(it);
			st[u].insert(cur);
		}
	}
	t_modify(val, du - dv + 1);
	st[u].insert(MP(MP(dv, du), val));
}

int prv, cnt;
int ver[400005];

int query_t(int t)
{
	set<pair<PII, int> >::iterator it = st[rt[t]].lower_bound(MP(MP(dep[t] + 1, -1), -1));
	it --;
	return it->second;
}

int query(int t)
{
	int idx = query_t(t);
	int ret = arr.sum(cnt) - arr.sum(idx - 1);
	ret -= dist(t, ver[idx]);
	return ret;
}

char buf[10];
int main()
{
	scanf("%d%d", &n, &q);
	rep(i, n - 1) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	gen_info();
	rep1(i, n) update(i, min(i + 1, n), i);
	rep1(i, n) ver[i] = i; 
	prv = cnt = n;
	
	rep(i, q) {
		scanf("%s", buf);
		if(buf[0] == 'u') {
			int v;
			scanf("%d", &v);
			update(prv, v, cnt);
			update(v, v, cnt + 1);
			prv = v;
			cnt ++;
			ver[cnt] = v;
		} else if(buf[0] == 'w') {
			int v;
			scanf("%d", &v);
			printf("%d\n", n + 1 - query(v));
		} else if(buf[0] == 'c') {
			int u, v;
			scanf("%d%d", &u, &v);
			printf("%d\n", query(u) > query(v) ? u : v);
		}
	}
	return 0;
}