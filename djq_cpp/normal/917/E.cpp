#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
 
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;
 
int n, m, q;
int pos[100005];
char ch[100005];
vector<pair<int, char> > G[100005]; 
int qu[100005], qv[100005], qt[100005];
int ans[100005];
int ql[100005], qr[100005];
 
struct SAM
{
	int cnt, ver[100005];
	int nxt[200005][26];
	int par[200005], len[200005];
	int dfn[200005], dfo[200005], dcnt;
	
	int append(int cv, char ch)
	{
		cnt ++;
		len[cnt - 1] = len[cv] + 1;
		for(; cv != -1 && nxt[cv][ch] == -1; cv = par[cv]) nxt[cv][ch] = cnt - 1;
		if(cv == -1) {
			par[cnt - 1] = 0;
			return cnt - 1;
		}
		if(len[nxt[cv][ch]] == len[cv] + 1) {
			par[cnt - 1] = nxt[cv][ch];
			return cnt - 1;
		}
		int nv = cnt ++, ov = nxt[cv][ch];
		rep(i, 26) nxt[nv][i] = nxt[ov][i];
		len[nv] = len[cv] + 1;
		par[nv] = par[ov];
		par[ov] = nv;
		par[cnt - 2] = nv;
		for(; cv != -1 && nxt[cv][ch] == ov; cv = par[cv]) nxt[cv][ch] = nv;
		return cnt - 2;
	}
	
	void init()
	{
		memset(nxt, -1, sizeof(nxt));
		memset(par, -1, sizeof(par));
		memset(len, 0, sizeof(len));
		cnt = 1;
		dcnt = 0;
	}
	
	vector<int> T[200005];
	void dfs(int v)
	{
		dfn[v] = dcnt ++;
		rep(i, T[v].size()) {
			int u = T[v][i];
			dfs(u);
		}
		dfo[v] = dcnt - 1;
	}
	
	void gen_upd()
	{
		rep(i, cnt) T[i].clear();
		rep(i, cnt) if(i > 0) T[par[i]].push_back(i);
		dfs(0);
	}
	
	int adds(int pos, char ch)
	{
		return pos == -1 ? -1 : nxt[pos][ch];
	}
}R, IR;
 
struct ACM
{
	int cnt, ver[100005];
	int fail[100005], nxt[100005][26], rnxt[100005][26];
	vector<int> T[100005];
	int dfn[100005], dfo[100005], dcnt;
	
	void init()
	{
		cnt = 1;
		dcnt = 0;
		fail[0] = -1;
		rep(i, 26) nxt[0][i] = -1;
	}
	
	int append(int cv, char ch)
	{
		if(nxt[cv][ch] == -1) {
			rep(i, 26) nxt[cnt][i] = -1;
			nxt[cv][ch] = cnt ++;
		}
		return nxt[cv][ch];
	}
	
	void dfs(int v)
	{
		dfn[v] = dcnt ++;
		rep(i, T[v].size()) {
			int u = T[v][i];
			dfs(u);
		}
		dfo[v] = dcnt - 1;
	}
	
	void gen_upd()
	{
		queue<int> que;
		que.push(0);
		while(!que.empty()) {
			int v = que.front();
			que.pop();
			rep(i, 26) rnxt[v][i] = nxt[v][i];
			if(fail[v] != -1) rep(i, 26) if(rnxt[v][i] == -1) rnxt[v][i] = rnxt[fail[v]][i];
			rep(i, 26) if(rnxt[v][i] == -1) rnxt[v][i] = 0;
			
			rep(i, 26) {
				int u = nxt[v][i];
				if(u == -1) continue;
				for(fail[u] = fail[v]; fail[u] != -1 && nxt[fail[u]][i] == -1; fail[u] = fail[fail[u]]);
				if(fail[u] == -1) fail[u] = 0;
				else fail[u] = nxt[fail[u]][i];
				que.push(u);
			}
		}
		
		rep(i, cnt) T[i].clear();
		rep(i, cnt) if(fail[i] != -1) T[fail[i]].push_back(i); 
		dfs(0);
	}
	
	int adds(int pos, char ch)
	{
		return rnxt[pos][ch];
	}
}D, ID;
 
bool del[100005];
int siz[100005];
int dv[100005], idv[100005];
void dfs0(int v, int p)
{
	siz[v] = 1;
	rep(i, G[v].size()) {
		int u = G[v][i].first;
		if(del[u] || u == p) continue;
		dfs0(u, v);
		siz[v] += siz[u];
	}
}
 
int cent(int v, int p, int tsiz)
{
	rep(i, G[v].size()) {
		int u = G[v][i].first;
		if(del[u] || u == p) continue;
		if(siz[u] > tsiz / 2) return cent(u, v, tsiz);
	}
	return v;
}
 
int qcnt, qtp[100005];
int dep[100005];
vector<int> cq[100005];
vector<int> tq[100005], itq[100005];
void dfs1(int v, int p, int d, int cval)
{
	qtp[v] = cval;
	dep[v] = d;
	tq[v].clear();
	itq[v].clear();
	rep(i, G[v].size()) {
		int u = G[v][i].first;
		if(del[u] || u == p) continue;
		dfs1(u, v, d + 1, cval);
	}
}
 
struct fwt
{
	int dat[262145];
	void add(int id, int val)
	{
		while(id <= 262144) {
			dat[id] += val;
			id += id & -id;
		}
	}
	
	int query(int id)
	{
		int ret = 0;
		while(id > 0) {
			ret += dat[id];
			id -= id & -id;
		}
		return ret;
	}
}tre, itre;
 
struct segt
{
	int spos[12000005], sdat[12000005], scnt;
	int dat[524288];
	
	void clear()
	{
		while(scnt > 0) {
			scnt --;
			dat[spos[scnt]] = sdat[scnt];
		}
	}
	
	void modify_v(int v, int d)
	{
		spos[scnt] = v;
		sdat[scnt] = dat[v];
		dat[v] = d;
		scnt ++;
	}
	
	void modify(int l, int r, int d)
	{
		l += 262144; r += 262144;
		while(l < r) {
			if(l & 1) modify_v(l, d);
			if(!(r & 1)) modify_v(r, d);
			l = l + 1 >> 1;
			r = r - 1 >> 1;
		}
		if(l == r) modify_v(l, d);
	}
	
	int query(int pos)
	{
		pos += 262144;
		int ret = 0;
		while(pos > 0) {
			ret = max(ret, dat[pos]);
			pos >>= 1;
		}
		return ret;
	}
	
	void undo(int id)
	{
		while(scnt > 0 && dat[spos[scnt - 1]] == id) {
			scnt --;
			dat[spos[scnt]] = sdat[scnt];
		}
	}
}st;
 
void dfs2(int v, int p, int cdv, int cidv)
{
	dv[v] = cdv;
	idv[v] = cidv;
	tre.add(D.dfn[dv[v]] + 1, 1);
	itre.add(ID.dfn[idv[v]] + 1, 1);
	rep(i, tq[v].size()) ans[tq[v][i]] += tre.query(D.dfo[D.ver[qt[tq[v][i]]]] + 1) - tre.query(D.dfn[D.ver[qt[tq[v][i]]]]);
	rep(i, itq[v].size()) ans[itq[v][i]] += itre.query(ID.dfo[ID.ver[qt[itq[v][i]]]] + 1) - itre.query(ID.dfn[ID.ver[qt[itq[v][i]]]]);
	
	rep(i, G[v].size()) {
		int u = G[v][i].first;
		if(del[u] || u == p) continue;
		dfs2(u, v, D.adds(cdv, G[v][i].second), ID.adds(cidv, G[v][i].second));
	}
	tre.add(D.dfn[dv[v]] + 1, -1);
	itre.add(ID.dfn[idv[v]] + 1, -1);
}
 
void dfs3(int v, int p, int crv)
{
	dv[v] = crv;
	if(crv != -1) st.modify(R.dfn[crv], R.dfo[crv], dep[v]);
	rep(i, tq[v].size()) qr[tq[v][i]] = st.query(R.dfn[R.ver[qt[tq[v][i]]]]);
	
	rep(i, G[v].size()) {
		int u = G[v][i].first;
		if(del[u] || u == p) continue;
		dfs3(u, v, R.adds(crv, G[v][i].second));
	}
	st.undo(dep[v]);
}
 
void dfs4(int v, int p, int cirv)
{
	idv[v] = cirv;
	if(cirv != -1) st.modify(IR.dfn[cirv], IR.dfo[cirv], dep[v]);
	rep(i, itq[v].size()) ql[itq[v][i]] = st.query(IR.dfn[IR.ver[qt[itq[v][i]]]]);
	
	rep(i, G[v].size()) {
		int u = G[v][i].first;
		if(del[u] || u == p) continue;
		dfs4(u, v, IR.adds(cirv, G[v][i].second));
	}
	st.undo(dep[v]);
}
 
void deposit(int v, int id)
{
	dfs0(v, -1);
	int tot = siz[v];
	v = cent(v, -1, tot);
	
	del[v] = true;
	int cqc = qcnt;
	dep[v] = 0;
	qtp[v] = id;
	tq[v].clear();
	itq[v].clear();
	rep(i, G[v].size()) {
		int u = G[v][i].first;
		if(del[u]) continue;
		dfs1(u, v, 1, qcnt ++);
	}
	
	vector<int> chq;
	rep(i, cq[id].size()) if(qtp[qu[cq[id][i]]] != qtp[qv[cq[id][i]]]) chq.push_back(cq[id][i]);
	else cq[qtp[qu[cq[id][i]]]].push_back(cq[id][i]);
	rep(i, chq.size()) {
		itq[qu[chq[i]]].push_back(chq[i]);
		tq[qv[chq[i]]].push_back(chq[i]);
	}
	
	dfs2(v, -1, 0, 0);
	dfs3(v, -1, 0);
	dfs4(v, -1, 0);
	
	rep(i, G[v].size()) {
		int u = G[v][i].first;
		if(del[u]) continue;
		deposit(u, cqc ++);
	}
}
 
vector<int> hv[100005];
int pf[100005], sf[100005];
vector<PII> indf[100005], qdf[100005]; 
 
void solve_s(int cur)
{
	D.init();
	ID.init();
	rep(i, pos[cur + 1] - pos[cur]) pf[i] = D.append(i == 0 ? 0 : pf[i - 1], ch[pos[cur] + i]);
	for(int i = pos[cur + 1] - pos[cur] - 1; i >= 0; i --)
	sf[i] = ID.append(i == pos[cur + 1] - pos[cur] - 1 ? 0 : sf[i + 1], ch[pos[cur] + i]);
	D.gen_upd();
	ID.gen_upd();
	
	rep(i, D.cnt + 1) {
		indf[i].clear();
		qdf[i].clear();
	}
	rep(i, pos[cur + 1] - pos[cur] - 1) {
		indf[D.dfn[pf[i]]].push_back(MP(sf[i + 1], 1));
		indf[D.dfo[pf[i]] + 1].push_back(MP(sf[i + 1], -1));
	}
	rep(i, hv[cur].size()) if(ql[hv[cur][i]] > 0 && qr[hv[cur][i]] > 0)
	qdf[D.dfn[pf[ql[hv[cur][i]] - 1]]].push_back(MP(sf[pos[cur + 1] - pos[cur] - qr[hv[cur][i]]], hv[cur][i]));
	
	rep(i, D.cnt + 1) {
		rep(j, indf[i].size()) {
			int cur = indf[i][j].first;
			tre.add(ID.dfn[cur] + 1, indf[i][j].second);
			tre.add(ID.dfo[cur] + 2, -indf[i][j].second);
		}
		rep(j, qdf[i].size()) {
			int cur = qdf[i][j].first;
			ans[qdf[i][j].second] += tre.query(ID.dfn[cur] + 1);
		}
	}
}
 
int main()
{
	scanf("%d%d%d", &n, &m, &q);
	rep(i, n - 1) {
		int u, v;
		char c;
		scanf("%d%d %c", &u, &v, &c);
		G[u].push_back(MP(v, c - 'a'));
		G[v].push_back(MP(u, c - 'a'));
	}
	rep(i, m) {
		scanf("%s", ch + pos[i]);
		pos[i + 1] = pos[i] + strlen(ch + pos[i]);
	}
	rep(i, pos[m]) ch[i] -= 'a';
	
	R.init();
	IR.init();
	D.init();
	ID.init();
	rep(i, pos[m]) R.ver[i] = R.append(i == 0 ? 0 : R.ver[i - 1], ch[i]);
	for(int i = pos[m] - 1; i >= 0; i --) IR.ver[i] = IR.append(i == pos[m] - 1 ? 0 : IR.ver[i + 1], ch[i]);
	R.gen_upd();
	IR.gen_upd();
	rep(i, pos[m]) R.ver[i] = IR.ver[i] = -1;
	rep(i, m) {
		R.ver[i] = 0;
		for(int j = pos[i]; j < pos[i + 1]; j ++) R.ver[i] = R.adds(R.ver[i], ch[j]);
		IR.ver[i] = 0;
		for(int j = pos[i + 1] - 1; j >= pos[i]; j --) IR.ver[i] = IR.adds(IR.ver[i], ch[j]);
	}
	
	rep(i, m) {
		D.ver[i] = 0;
		for(int j = pos[i]; j < pos[i + 1]; j ++) D.ver[i] = D.append(D.ver[i], ch[j]);
		ID.ver[i] = 0;
		for(int j = pos[i + 1] - 1; j >= pos[i]; j --) ID.ver[i] = ID.append(ID.ver[i], ch[j]);
	}
	D.gen_upd();
	ID.gen_upd();
 
	rep(i, q) {
		scanf("%d%d%d", &qu[i], &qv[i], &qt[i]);
		qt[i] --;
	}
	
	qcnt = 1;
	rep(i, q) cq[0].push_back(i);
	deposit(1, 0);
	
	rep(i, q) hv[qt[i]].push_back(i);
	rep(i, m) solve_s(i);
	
	rep(i, q) printf("%d\n", ans[i]);
	return 0;
}