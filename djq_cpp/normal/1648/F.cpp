//https://acm.nflsoj.com/submission/53170

#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int MOD = 998244353;

mt19937 rng(time(0));
uniform_int_distribution<ULL> dis(0ULL, -1ULL);

int n, m, q, eu[500005], ev[500005];
pair<ULL, int> seq[500005];
vector<PII> G[500005];
ULL xe[500005], xv[500005];
bool vis[500005], tp[500005];
void dfs0(int v, int pe)
{
	vis[v] = true;
	rep(i, G[v].size()) {
		int u = G[v][i].first, e = G[v][i].second;
		if(e == pe) continue;
		if(!vis[u]) {
			if(eu[e] == v) swap(eu[e], ev[e]); 
			dfs0(u, e);
		} else if(!tp[e]) {
			if(eu[e] == u) swap(eu[e], ev[e]);
			tp[e] = true;
		}
	}
}
void dfs1(int v, int pe)
{
	vis[v] = true;
	rep(i, G[v].size()) {
		int u = G[v][i].first, e = G[v][i].second;
		if(e == pe) continue;
		if(!vis[u]) {
			dfs1(u, e);
			xe[e] = xv[u]; xv[v] ^= xv[u];
		}
	}
}
void dfs2(int v, int pe)
{
	vis[v] = true;
	rep(i, G[v].size()) {
		int u = G[v][i].first, e = G[v][i].second;
		if(e == pe) continue;
		if(!vis[u]) {
			xv[u] ^= xv[v]; dfs2(u, e);
		}
	}
}

vector<int> E;
int rt[500005];
int root(int x)
{
	return x == rt[x] ? x : rt[x] = root(rt[x]);
}

vector<int> H[500005], T[1000005];
int dep[1000005], mdep[500005], cnt;
bool gd[1000005];
stack<int> sta;
void dfs(int v, int par, int cd)
{
	vis[v] = true;
	sta.push(v);
	mdep[v] = dep[v] = cd;
	int g = 0;
	rep(i, H[v].size()) {
		int u = H[v][i];
		if(u == par) g ++;
		if(!vis[u]) {
			dfs(u, v, cd + 1);
			mdep[v] = min(mdep[v], mdep[u]);
		} else mdep[v] = min(mdep[v], dep[u]);
	}
	if(mdep[v] == dep[v] - 1) {
		cnt ++;
		int cv = -1;
		do {
			cv = sta.top();
			T[cnt].push_back(cv); T[cv].push_back(cnt);
			sta.pop();
		} while(cv != v);
		T[cnt].push_back(par); T[par].push_back(cnt);
		gd[cnt] = (int)T[cnt].size() == 2 && g == 1;
	}
}

vector<pair<int, PII> > mx1;
int mx2;
PII d2[2];

int pre[1000005][20], id[1000005];
void dfs3(int v, int p)
{
	dep[v] = dep[p] + 1;
	pre[v][0] = p;
	rep1(i, 19) pre[v][i] = pre[pre[v][i - 1]][i - 1];
	
	rep(i, T[v].size()) {
		int u = T[v][i];
		if(u == p) {
			rotate(T[v].begin(), T[v].begin() + i + 1, T[v].end()); break;
		}
	}
	rep(i, (int)T[v].size() - (p >= 1)) {
		id[T[v][i]] = i; dfs3(T[v][i], v);
	}
}

vector<PII> hvt[1000005];
int lca(int u, int v)
{
	if(dep[u] < dep[v]) swap(u, v);
	for(int i = 19; i >= 0; i --) if((dep[u] - dep[v]) >> i) u = pre[u][i];
	if(u == v) return u;
	for(int i = 19; i >= 0; i --) if(pre[u][i] != pre[v][i]) {
		u = pre[u][i]; v = pre[v][i];
	}
	if(pre[u][0] > n) hvt[pre[u][0]].push_back(MP(min(id[u], id[v]), max(id[u], id[v])));
	return pre[u][0];
}

int s0[1000005];
void dfs4(int v, int p)
{
	rep(i, T[v].size()) {
		int u = T[v][i];
		if(u == p) continue;
		dfs4(u, v);
		s0[v] += s0[u];
	}
}

struct segt
{
	pair<LL, int> dat[1048576];
	LL tag[1048576];
	segt()
	{
		rep(i, 524288) dat[i | 524288] = MP(0, i);
		for(int i = 524287; i >= 1; i --) dat[i] = max(dat[i << 1], dat[i << 1 | 1]);
	}
	void add(int l, int r, int val, int cv = 1, int cl = 0, int cr = 524287)
	{
		if(r < cl || l > cr) return;
		if(l <= cl && r >= cr) {
			tag[cv] += val; dat[cv].first += val; return;
		}
		int mid = (cl + cr) >> 1;
		add(l, r, val, cv << 1, cl, mid);
		add(l, r, val, cv << 1 | 1, mid + 1, cr);
		dat[cv] = max(dat[cv << 1], dat[cv << 1 | 1]); dat[cv].first += tag[cv];
	}
	pair<LL, int> query(int l, int r, int cv = 1, int cl = 0, int cr = 524287)
	{
		if(r < cl || l > cr) return MP(0, 0);
		if(l <= cl && r >= cr) return dat[cv];
		int mid = (cl + cr) >> 1;
		pair<LL, int> ret = max(query(l, r, cv << 1, cl, mid), query(l, r, cv << 1 | 1, mid + 1, cr));
		ret.first += tag[cv];
		return ret;
	}
}tre;

int len;
vector<PII> cq[500005];
void calc(int cur)
{
	len = (int)T[cur].size();
	rep(i, len) cq[i].clear();
	rep(i, hvt[cur].size()) {
		int u = hvt[cur][i].first, v = hvt[cur][i].second;
		cq[u].push_back(MP(v, 1));
		cq[v].push_back(MP(u, 1));
		tre.add(u + 1, v, 1);
		s0[T[cur][u]] --; s0[T[cur][v]] --;
	}
	rep(i, len - 1) if(s0[T[cur][i]]) {
		cq[i].push_back(MP(len - 1, s0[T[cur][i]]));
		cq[len - 1].push_back(MP(i, s0[T[cur][i]]));
		tre.add(i + 1, len - 1, s0[T[cur][i]]);
	}
	
	rep(i, len) {
		pair<LL, int> ca = tre.query(0, len - 1);
		if(ca.first > mx2) {
			mx2 = ca.first;
			d2[0] = MP(T[cur][(i - 1 + len) % len], T[cur][i]);
			d2[1] = MP(T[cur][(ca.second - 1 + len) % len], T[cur][ca.second]);
		}
		rep(j, cq[i].size()) {
			int k = cq[i][j].first;
			if(k > i) {
				tre.add(0, 524287, cq[i][j].second);
				tre.add(i + 1, k, -2 * cq[i][j].second);
			} else {
				tre.add(0, 524287, -cq[i][j].second);
				tre.add(k + 1, i, 2 * cq[i][j].second);
			}
		}
	}
	
	rep(i, len) rep(j, cq[i].size()) {
		int k = cq[i][j].first;
		if(k > i) tre.add(i + 1, k, -cq[i][j].second);
	}
}

void solve()
{
	scanf("%d%d", &n, &m);
	rep(i, m) {
		scanf("%d%d", &eu[i], &ev[i]);
		G[eu[i]].push_back(MP(ev[i], i));
		G[ev[i]].push_back(MP(eu[i], i));
	}
	rep1(i, n) vis[i] = false;
	dfs0(1, -1);
	rep(i, m) if(tp[i]) {
		xe[i] = dis(rng);
		xv[eu[i]] ^= xe[i]; xv[ev[i]] ^= xe[i];
	}
	rep1(i, n) vis[i] = false;
	dfs1(1, -1);
	rep1(i, n) xv[i] = 0;
	rep(i, m) seq[i] = MP(xe[i], i);
	sort(seq, seq + m);
	rep(i, m) if(seq[i].first == 0) {
		int ce = seq[i].second;
		xv[eu[ce]] ^= dis(rng);
		E.push_back(ce);
	} else {
		int j = i;
		for(; j + 1 < m && seq[j + 1].first == seq[i].first; j ++) ;
		if(i == j) continue;
		bool hv = false;
		ULL cx = 0;
		for(int k = i; k <= j; k ++) if(tp[seq[k].second]) hv = true;
		else {
			ULL cur = dis(rng);
			xv[eu[seq[k].second]] ^= cur; cx ^= cur;
		}
		if(!hv) xv[eu[seq[i].second]] ^= cx;
		for(int k = i; k <= j; k ++) E.push_back(seq[k].second);
		i = j;
	}
	rep1(i, n) vis[i] = false;
	dfs2(1, -1);
	rep1(i, n) seq[i] = MP(xv[i], i);
	sort(seq + 1, seq + 1 + n);
	
	rep1(i, n) rt[i] = i;
	rep1(i, n - 1) if(seq[i].first == seq[i + 1].first) rt[seq[i + 1].second] = seq[i].second;
	
	rep(i, E.size()) {
		int ce = E[i], u = root(eu[ce]), v = root(ev[ce]);
		H[u].push_back(v);
		H[v].push_back(u);
	}
	
	int r;
	rep1(i, n) if(rt[i] == i) {
		r = i; break;
	}
	rep1(i, n) vis[i] = false;
	cnt = n;
	dfs(r, 0, 0);
	while(!sta.empty()) sta.pop();
	
	dfs3(r, 0);
	scanf("%d", &q);
	rep(i, q) {
		int u, v;
		scanf("%d%d", &u, &v);
		u = root(u); v = root(v);
		s0[u] ++; s0[v] ++; s0[lca(u, v)] -= 2;
	}
	dfs4(r, 0);
	
	mx1.clear(); mx2 = 0;
	rep1(i, cnt) if(gd[i]) {
		mx1.push_back(MP(s0[i], MP(T[i][0], T[i][1])));
		sort(mx1.begin(), mx1.end());
		reverse(mx1.begin(), mx1.end());
		while((int)mx1.size() > 2) mx1.pop_back();
	}
	rep1(i, cnt) if(!gd[i] && i > n) calc(i);

	if((int)mx1.size() >= 2 && mx1[0].first + mx1[1].first > mx2) {
		mx2 = mx1[0].first + mx1[1].first;
		d2[0] = mx1[0].second; d2[1] = mx1[1].second;
	} else if((int)mx1.size() == 1 && mx1[0].first > mx2) {
		mx2 = mx1[0].first;
		d2[0] = d2[1] = mx1[0].second;
	}

	printf("%d\n", mx2);
	int ca[2] = {0, 1};
	if(mx2 > 0) rep(i, 2) rep(j, m) {
		int x = root(eu[j]), y = root(ev[j]);
		if(x == d2[i].first && y == d2[i].second || x == d2[i].second && y == d2[i].first)
		if(i == 0 || j != ca[0]) {
			ca[i] = j; break;
		}
	}
	if(ca[1] == ca[0]) ca[1] = ca[0] ? 0 : 1;
	rep(i, 2) printf("%d %d\n", eu[ca[i]], ev[ca[i]]);
	
	E.clear();
	rep1(i, n) {
		G[i].clear(); H[i].clear();
	}
	rep1(i, cnt) {
		T[i].clear(); hvt[i].clear();
	}
	rep1(i, n) vis[i] = xv[i] = 0;
	rep(i, m) tp[i] = xe[i] = 0;
	rep1(i, cnt) gd[i] = s0[i] = 0;
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}