#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, m, q, qu[100005], qv[100005], qs[100005], qr[100005];
vector<pair<int, char> > G[100005];
string T[100005];
int pos[100005];
vector<int> vs[100005], vr[100005];

struct SAM
{
	int cnt, nxt[200005][26], tch[200005][26], par[200005], dep[200005];
	vector<int> G[200005];
	PII vid[200005];
	int dfn[200005], dfo[200005], tot;
	void clear()
	{
		cnt = 1;
		memset(nxt, -1, sizeof(nxt));
		memset(par, -1, sizeof(par));
		memset(dep, 0, sizeof(dep));
	}
	int append(int x, int ch)
	{	
		if(nxt[x][ch] != -1) return nxt[x][ch];
		int ret = cnt ++;
		dep[ret] = dep[x] + 1;
		for(; x != -1 && nxt[x][ch] == -1; x = par[x]) nxt[x][ch] = ret;
		if(x == -1) par[ret] = 0;
		else if(dep[x] + 1 == dep[nxt[x][ch]]) par[ret] = nxt[x][ch];
		else {
			int nr = cnt ++, fr = nxt[x][ch];
			dep[nr] = dep[x] + 1;
			par[nr] = par[fr]; par[fr] = nr;
			rep(i, 26) nxt[nr][i] = nxt[fr][i];
			par[ret] = nr;
			for(; x != -1 && nxt[x][ch] == fr; x = par[x]) nxt[x][ch] = nr;
		}
		return ret;
	}
	void dfs(int v, int coef)
	{
		dfn[v] = ++ tot;
		rep(i, 26) tch[v][i] = -1;
		rep(i, G[v].size()) {
			dfs(G[v][i], coef); vid[v] = vid[G[v][i]];
			tch[v][T[vid[v].first][vid[v].second + coef * dep[v]]] = G[v][i];
		}
		dfo[v] = tot;
	}
	void getre(int coef)
	{
		rep1(i, cnt - 1) G[par[i]].push_back(i);
		dfs(0, coef);
	}
}S, R;

PII gnxtS(PII cur, int ch, const SAM& X, int coef)
{
	if(cur.first == -1) return MP(-1, cur.second + 1);
	if(X.dep[cur.first] == cur.second) return MP(X.tch[cur.first][ch], cur.second + 1);
	else return MP(T[X.vid[cur.first].first][X.vid[cur.first].second + coef * cur.second] == ch ? cur.first : -1, cur.second + 1);
}

queue<int> que;
void gen_sam(SAM& cur, vector<int> ver[])
{
	cur.clear();
	rep(i, m) {
		pos[i] = 0; ver[i].push_back(0);
		que.push(i);
	}
	while(!que.empty()) {
		int id = que.front(); que.pop();
		int cv = ver[id].back();
		ver[id].push_back(cur.append(cv, T[id][pos[id] ++]));
		if(pos[id] < (int)T[id].length()) que.push(id);
	}
}

bool del[100005];
int siz[100005], cid[100005];
PII ps[100005], pr[100005];
vector<int> hv[100005];
void dfs0(int v, int p)
{
	siz[v] = 1;
	rep(i, G[v].size()) {
		int u = G[v][i].first;
		if(del[u] || u == p) continue;
		dfs0(u, v); siz[v] += siz[u];
	}
}
int dfs1(int v, int p, int tsz)
{
	rep(i, G[v].size()) {
		int u = G[v][i].first;
		if(del[u] || u == p) continue;
		if(siz[u] * 2 > tsz) return dfs1(u, v, tsz);
	}
	return v;
}

void dfs2(int v, int p, int gr)
{
	cid[v] = gr;
	rep(i, G[v].size()) {
		int u = G[v][i].first;
		if(del[u] || u == p) continue;
		ps[u] = gnxtS(ps[v], G[v][i].second, S, -1);
		pr[u] = gnxtS(pr[v], G[v][i].second, R, 1);
		dfs2(u, v, gr ? gr : u);
	}
}
void solve(int v)
{
	dfs0(v, 0);
	int u = dfs1(v, 0, siz[v]);
	swap(hv[u], hv[v]);
	
	ps[u] = pr[u] = MP(0, 0);
	dfs2(u, 0, 0);

	rep(i, hv[u].size()) {
		int cq = hv[u][i];
		if(cid[qu[cq]] && cid[qv[cq]] && cid[qu[cq]] == cid[qv[cq]]) hv[cid[qu[cq]]].push_back(cq);
		else {
			qs[cq] = ps[qu[cq]].first; qr[cq] = pr[qv[cq]].first;
		}
	}
	
	del[u] = true;
	rep(i, G[u].size()) {
		v = G[u][i].first;
		if(!del[v]) solve(v);
	}
}

struct fwt
{
	int dat[262145];
	void add(int id, int val)
	{
		for(id ++; id > 0; id -= id & -id) dat[id] += val;
	}
	int query(int id)
	{
		int ret = 0;
		for(id ++; id <= 262144; id += id & -id) ret += dat[id];
		return ret;
	}
	int query(int l, int r)
	{
		return query(l) - query(r + 1);
	}
}tre;
int ans[100005];
vector<PII> qy[100005];

vector<pair<int, PII> > calc(int l, int r)
{
	if(l == r) {
		vector<pair<int, PII> > ret;
		rep(i, vs[l].size()) ret.push_back(MP(S.dfn[vs[l][i]], MP(0, R.dfn[vr[l][i]])));
		rep(i, qy[l].size()) {
			int cq = qy[l][i].first;
			if(qy[l][i].second == -1) {
				ret.push_back(MP(S.dfn[qs[cq]] - 1, MP(1, cq)));
				ret.push_back(MP(S.dfo[qs[cq]] + 1, MP(-1, cq)));
			} else {
				ret.push_back(MP(S.dfn[qs[cq]], MP(-1, cq)));
				ret.push_back(MP(S.dfo[qs[cq]], MP(1, cq)));
			}
		}
		sort(ret.begin(), ret.end());
		return ret;
	}
	
	int mid = (l + r) >> 1;
	vector<pair<int, PII> > A = calc(l, mid), B = calc(mid + 1, r), C;
	C.resize(A.size() + B.size());
	
	int i = 0, j = 0, k = 0;
	while(i < A.size() || j < B.size()) {
		pair<int, PII> cur;
		if(j == B.size() || (i < A.size() && A[i] < B[j])) {
			C[k ++] = cur = A[i ++];
			if(cur.second.first == 0) tre.add(cur.second.second, 1);
		} else {
			C[k ++] = cur = B[j ++];
			if(cur.second.first != 0) {
				int cq = cur.second.second, cc = cur.second.first;
				ans[cq] += cc * tre.query(R.dfn[qr[cq]], R.dfo[qr[cq]]);
			}
		}
	}
	rep(i, C.size()) if(C[i].second.first == 0) tre.add(C[i].second.second, -1);
	return C;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> q;
	rep(i, n - 1) {
		int u, v; char c;
		cin >> u >> v >> c; c -= 'a';
		G[u].push_back(MP(v, c));
		G[v].push_back(MP(u, c));
	}
	rep(i, m) cin >> T[i];
	rep(i, m) rep(j, T[i].size()) T[i][j] -= 'a';
	rep(i, q) {
		int l, r;
		cin >> qu[i] >> qv[i] >> l >> r;
		qy[l - 1].push_back(MP(i, -1));
		qy[r].push_back(MP(i, 1));
	}
	
	gen_sam(S, vs);
	rep(i, m) reverse(T[i].begin(), T[i].end());
	gen_sam(R, vr);
	rep(i, m) {
		reverse(T[i].begin(), T[i].end()); reverse(vr[i].begin(), vr[i].end());
	}
	
	rep(i, m) rep(j, T[i].length()) S.vid[vs[i][j + 1]] = R.vid[vr[i][j]] = MP(i, j);
	S.getre(-1); R.getre(1);
	
	rep(i, q) hv[1].push_back(i);
	solve(1);
	
	calc(0, m);
	rep(i, q) cout << ans[i] << '\n';
	return 0;
}