#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

struct tnode
{
	int val;
	tnode* lson,* rson;
	tnode(int num = 0)
	{
		val = num; lson = rson = NULL;
	}
};
tnode* newt(int pos, int cl = 0, int cr = 262143)
{
	if(cl == cr) return new tnode(1);
	int mid = (cl + cr) >> 1;
	tnode* ret = new tnode(1);
	if(pos <= mid) ret->lson = newt(pos, cl, mid);
	else ret->rson = newt(pos, mid + 1, cr);
	return ret;
}
int queryt(tnode* cur, int l, int r, int cl = 0, int cr = 262143)
{
	if(cur == NULL) return 0;
	if(r < cl || l > cr) return 0;
	if(l <= cl && r >= cr) return cur->val;
	int mid = (cl + cr) >> 1;
	int ret = queryt(cur->lson, l, r, cl, mid) + queryt(cur->rson, l, r, mid + 1, cr);
	return ret;
}
void merget(tnode*& u, tnode* v, int cl = 0, int cr = 262143)
{
	if(v == NULL) return;
	else if(u == NULL) u = v;
	else {
		u->val += v->val;
		if(cl == cr) return;
		int mid = (cl + cr) >> 1;
		merget(u->lson, v->lson, cl, mid);
		merget(u->rson, v->rson, mid + 1, cr);
	}
}

int n, m, k, x[150005], y[150005], t[150005], tx[150005], ty[150005], grp[150005], cnt;
vector<int> hv[150005];
vector<int> G[150005];
int pre[150005][20], dep[150005], dfn[150005], dfo[150005], dseq[150005], tot;
void dfs(int v, int par)
{
	dseq[++ tot] = v;
	dfn[v] = tot;
	dep[v] = dep[par] + 1;
	rep(i, 20) pre[v][i] = i == 0 ? par : pre[pre[v][i - 1]][i - 1];
	rep(i, G[v].size()) {
		int u = G[v][i];
		if(u == par) continue;
		dfs(u, v);
	}
	dfo[v] = tot;
}
int lca(int u, int v, int &p, int& q)
{
	for(int i = 19; i >= 0; i --) if(dep[pre[u][i]] > dep[v]) u = pre[u][i];
	for(int i = 19; i >= 0; i --) if(dep[pre[v][i]] > dep[u]) v = pre[v][i];
	if(u == v) {
		p = q = -1; return u;
	} else if(pre[u][0] == v) {
		p = u; q = -1; return v;
	} else if(pre[v][0] == u) {
		p = -1; q = v; return u;
	}
	if(dep[u] > dep[v]) u = pre[u][0];
	if(dep[v] > dep[u]) v = pre[v][0];
	for(int i = 19; i >= 0; i --) if(pre[u][i] != pre[v][i]) {
		u = pre[u][i]; v = pre[v][i];
	}
	p = u; q = v;
	return pre[u][0];
}
int getkth(int v, int k)
{
	for(int i = 19; i >= 0; i --) if(k >> i & 1) v = pre[v][i];
	return v;
}

int cval[150005];
void addp(int f, int g, int len)
{
	if(dep[f] - dep[g] < len) return;
	g = getkth(f, dep[f] - dep[g] - len + 1);
	cval[f] ++; cval[g] --;
}
void dfs1(int v, int par)
{
	rep(i, G[v].size()) {
		int u = G[v][i];
		if(u == par) continue;
		dfs1(u, v);
		cval[v] += cval[u];
	}
}
LL solve0(int len)
{
	rep1(i, n) cval[i] = 0;
	rep(i, m) {
		addp(x[i], t[i], len); addp(y[i], t[i], len);
	}
	dfs1(1, -1);
	LL ret = 0;
	rep1(i, n) ret += 1LL * cval[i] * (cval[i] - 1) / 2;
	return ret;
}

vector<int> cv, ce;
vector<int> T[150005], R[150005];
int siz[150005];
bool cmp(int i, int j)
{
	return dfn[i] < dfn[j];
}
void buildt()
{
	sort(cv.begin(), cv.end(), cmp);
	for(int i = (int)cv.size() - 2; i >= 0; i --) cv.push_back(lca(cv[i], cv[i + 1], tx[m], ty[m]));
	sort(cv.begin(), cv.end(), cmp);
	cv.resize(unique(cv.begin(), cv.end()) - cv.begin());
	
	rep(i, cv.size()) T[cv[i]].clear();
	vector<int> st;
	for(int i = (int)cv.size() - 1; i >= 0; i --) {
		int v = cv[i];
		while(!st.empty() && dfo[v] >= dfo[st.back()]) {
			int u = st.back();
			T[u].push_back(v); T[v].push_back(u);
			st.pop_back();
		}
		st.push_back(v);
	}
}

int rd, rk;
tnode* tre[150005];
LL calc(tnode* v, tnode* u, int mind, int cl = 0, int cr = 262143)
{
	if(u == NULL || v == NULL) return 0;
	if(cl == cr) {
		int cur = dseq[cl];
		if(dep[cur] < mind) return 0;
		cur = getkth(cur, dep[cur] - mind);
		return 1LL * v->val * queryt(u, dfn[cur], dfo[cur]);
	}
	int mid = (cl + cr) >> 1;
	int ret = calc(v->lson, u, mind, cl, mid) + calc(v->rson, u, mind, mid + 1, cr);
	return ret;
}
LL merge(tnode*& u, tnode* v, int mind)
{
	if(u == NULL) u = v;
	else if(v != NULL) {
		if(u->val < v->val) swap(u, v);
		LL ret = calc(v, u, mind);
		merget(u, v);
		return ret;
	}
	return 0;
}
LL dfs2(int v, int par)
{
	tre[v] = NULL;
	LL ret = 0;
	rep(i, R[v].size()) ret += merge(tre[v], newt(dfn[R[v][i]]), max(rd * 2 + rk - dep[v], rd));
	rep(i, T[v].size()) {
		int u = T[v][i];
		if(u == par) continue;
		ret += dfs2(u, v);
		ret += merge(tre[v], tre[u], max(rd * 2 + rk - dep[v], rd));
	}
	return ret;
}
LL dfs3(int v, int par)
{
	LL ret = 0;
	rep(i, T[v].size()) {
		int u = T[v][i];
		if(u == par) continue;
		LL cr = dfs3(u, v);
		siz[v] += siz[u];
		if(dep[v] < rd + rk) ret += cr;
	}
	if(dep[v] >= rd + rk) ret += 1LL * siz[v] * (siz[v] - 1) / 2;
	return ret;
}
LL calc(int rt, int len)
{
	if(ce.size() == 1) return 0;
	cv.clear();
	rep(i, ce.size()) {
		cv.push_back(x[ce[i]]); cv.push_back(y[ce[i]]);
	}
	buildt();
	rep(i, cv.size()) {
		siz[cv[i]] = 0; R[cv[i]].clear();
	}
	rep(i, ce.size()) {
		siz[x[ce[i]]] ++; siz[y[ce[i]]] ++; R[x[ce[i]]].push_back(y[ce[i]]);
	}
	return dfs2(rt, -1) - dfs3(rt, -1);
}

PII tmp[150005];
LL solve1(int len)
{
	LL ret = 0;
	rep(i, cnt) {
		ce = hv[i]; rd = dep[tmp[i].first] - 1; rk = len;
		ret += calc(pre[tmp[i].first][0], len);
	}
	return ret;
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	rep(i, n - 1) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	rep(i, m) scanf("%d%d", &x[i], &y[i]);
	
	dfs(1, 0);
	rep(i, m) t[i] = lca(x[i], y[i], tx[i], ty[i]);
	
	rep(i, m) if(tx[i] != -1 && ty[i] != -1) {
		if(tx[i] > ty[i]) {
			swap(x[i], y[i]); swap(tx[i], ty[i]);
		}
		tmp[cnt ++] = MP(tx[i], ty[i]);
	}
	sort(tmp, tmp + cnt);
	cnt = unique(tmp, tmp + cnt) - tmp;
	rep(i, m) if(tx[i] == -1 || ty[i] == -1) grp[i] = -1;
	else {
		grp[i] = lower_bound(tmp, tmp + cnt, MP(tx[i], ty[i])) - tmp;
		hv[grp[i]].push_back(i);
	}
	
	printf("%lld\n", solve0(k) - solve0(k + 1) + solve1(k));
	return 0;
}