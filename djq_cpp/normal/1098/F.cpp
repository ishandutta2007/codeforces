//zabana, zibile
/*can be solved in O(n log n) with the substring border algorithm and some casework
but I'll never write that unless I'm given the whole String Template Library*/
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

namespace IO
{
	const int BSIZ = 4096;
	char bufi[4105], bufo[4105];
	int posi = BSIZ, poso;
	void getC(char& ch)
	{
		if(posi == BSIZ) {
			memset(bufi, 0, sizeof(bufi));
			fread(bufi, 1, BSIZ, stdin); posi = 0;
		}
		ch = bufi[posi ++];
	}
	template<typename T>
	void getU(T& x)
	{
		char ch; x = 0;
		do getC(ch);
		while(ch < '0' || ch > '9');
		do {
			x = x * 10 + (ch - '0'); getC(ch);
		} while(ch >= '0' && ch <= '9');
	}
	void getS(char s[], int& len)
	{
		char ch; len = 0;
		do getC(ch);
		while(ch < 'a' || ch > 'z');
		do {
			s[len ++] = ch; getC(ch);
		} while(ch >= 'a' && ch <= 'z');
	}
	void putC(char ch)
	{
		if(ch == EOF || poso == BSIZ) {
			fwrite(bufo, 1, poso, stdout); poso = 0;
		}
		if(ch != EOF) bufo[poso ++] = ch;
	}
	char buf[25];
	template<typename T>
	void putU(T x)
	{
		int len = 0;
		do {
			buf[len ++] = x % 10 + '0'; x /= 10;
		} while(x != 0);
		for(int i = len - 1; i >= 0; i --) putC(buf[i]);
	}
}
using namespace IO;

int n, q, ql[200005], qr[200005];
char S[200005];
LL ans[200005];

namespace SAM
{
	int dep[400005], par[400005], nxt[400005][26], cnt;
	void init()
	{
		cnt = 1;
		memset(dep, 0, sizeof(dep));
		memset(par, -1, sizeof(par)); memset(nxt, -1, sizeof(nxt));
	}
	int append(int v, int ch) 
	{
		int ret = cnt ++;
		dep[ret] = dep[v] + 1;
		for(; v != -1 && nxt[v][ch] == -1; v = par[v]) nxt[v][ch] = ret;
		if(v == -1) par[ret] = 0;
		else {
			int ov = nxt[v][ch];
			if(dep[ov] == dep[v] + 1) par[ret] = ov;
			else {
				int nv = cnt ++;
				dep[nv] = dep[v] + 1;
				par[nv] = par[ov]; par[ret] = par[ov] = nv;
				rep(i, 26) nxt[nv][i] = nxt[ov][i];
				for(; v != -1 && nxt[v][ch] == ov; v = par[v]) nxt[v][ch] = nv;
			}
		}
		return ret;
	}
}
using namespace SAM;
vector<int> T[400005];
int ver[200005], id[400005];
vector<int> qy[200005];

bool del[400005];
vector<int> hv[400005];
int dfn[400005], dfo[400005], dseq[400005], tot, grp[400005];
void dfs(int v, int par)
{
	dfn[v] = tot; dseq[tot ++] = v;
	rep(i, T[v].size()) {
		int u = T[v][i];
		if(u == par || del[u]) continue;
		dfs(u, v);
	}
	dfo[v] = tot;
}

vector<int> V;
LL psum[200005];
void calc0(int coef, int ld)
{
	int len = V.size();
	psum[0] = 0;
	rep(i, len) psum[i + 1] = psum[i] + V[i];
	rep(i, len) rep(j, qy[V[i]].size()) {
		int cq = qy[V[i]][j];
		int i0 = max((int)(lower_bound(V.begin(), V.end(), qr[cq] + 1 - ld) - V.begin()), i), 
			i1 = lower_bound(V.begin(), V.end(), qr[cq] + 1) - V.begin();
		ans[cq] += coef * (1LL * (i0 - i) * ld + psum[i0] - psum[i] + 1LL * (i1 - i0) * (qr[cq] + 1));
	}
}

template<typename T>
struct fwt
{
	T sum, dat[400005];
	void add(int id, T val)
	{
		sum += val;
		for(id ++; id < 400005; id += id & -id) dat[id] += val; 
	}
	T query(int id)
	{
		T ret = 0;
		for(id ++; id > 0; id -= id & -id) ret += dat[id];
		return ret;
	}
};
fwt<int> tre0;
fwt<LL> tre1;

int qcnt;
PII sw[600005];
int gd[400005];
void solve(int r)
{
	tot = 0; dfs(r, -1);
	int v = r;
	rep(i, tot) if((dfo[dseq[i]] - i) * 2 > tot) v = dseq[i];
	swap(hv[r], hv[v]);
	
	rep(i, tot) grp[dseq[i]] = r;
	grp[v] = v;
	rep(i, T[v].size()) {
		int u = T[v][i];
		if(dfn[u] < dfn[v] || del[u]) continue;
		for(int j = dfn[u]; j < dfo[u]; j ++) grp[dseq[j]] = u;
	}
	rep(i, hv[v].size()) if(hv[v][i] != v) hv[grp[hv[v][i]]].push_back(hv[v][i]);
	
	rep(i, T[v].size()) {
		int u = T[v][i];
		if(dfn[u] < dfn[v] || del[u]) continue;
		V.resize(hv[u].size());
		rep(j, hv[u].size()) V[j] = id[hv[u][j]];
		calc0(-1, dep[v]);
	}
	V.clear(); V.reserve(hv[v].size() - (v == r ? 0 : hv[r].size()));
	rep(i, hv[v].size()) if(r == v || grp[hv[v][i]] != r) V.push_back(id[hv[v][i]]);
	calc0(1, dep[v]);
	
	if(v != r) {
		rep(i, tot) gd[dseq[i]] = dep[r];
		for(int i = v; i != r; i = par[i]) gd[i] = dep[i];
		rep(i, tot) gd[dseq[i]] = max(gd[dseq[i]], gd[par[dseq[i]]]);
		rep(i, hv[r].size()) {
			int u = hv[r][i], cv = id[u];
			rep(j, qy[cv].size()) {
				int cq = qy[cv][j];
				int i0 = lower_bound(V.begin(), V.end(), cv) - V.begin(),
					i1 = max((int)(lower_bound(V.begin(), V.end(), qr[cq] + 1 - gd[u]) - V.begin()), i0),
					i2 = lower_bound(V.begin(), V.end(), qr[cq] + 1) - V.begin();
				ans[cq] += 1LL * (i1 - i0) * gd[u] + psum[i1] - psum[i0] + 1LL * (i2 - i1) * (qr[cq] + 1);
			}
		}
		
		qcnt = 0;
		rep(i, hv[r].size()) sw[qcnt ++] = MP(id[hv[r][i]], ~min(id[hv[r][i]] + gd[hv[r][i]], n));
		rep(i, V.size()) rep(j, qy[V[i]].size()) {
			int cq = qy[V[i]][j];
			sw[qcnt ++] = MP(ql[cq] - 1, cq << 1 | 1);
			sw[qcnt ++] = MP(qr[cq], cq << 1);
		}
		sort(sw, sw + qcnt);
		rep(i, qcnt) {
			int tmp = sw[i].second;
			if(tmp < 0) {
				tmp = ~tmp;
				tre0.add(tmp, 1); tre1.add(tmp, tmp);
			} else {
				int coef = tmp & 1 ? -1 : 1; tmp >>= 1;
				ans[tmp] += coef * (1LL * (tre0.sum - tre0.query(qr[tmp])) * (qr[tmp] + 1) + tre1.query(qr[tmp]));
			}
		}
		rep(i, qcnt) {
			int tmp = sw[i].second;
			if(tmp < 0) {
				tmp = ~tmp;
				tre0.add(tmp, -1); tre1.add(tmp, -tmp);
			}
		}
	}
	
	del[v] = true;
	if(r != v) solve(r);
	rep(i, T[v].size()) {
		int u = T[v][i];
		if(dfn[u] < dfn[v] || del[u]) continue;
		solve(u);
	}
}

int main()
{
	getS(S, n); getU(q);
	rep(i, n) S[i] -= 'a';
	rep(i, q) {
		getU(ql[i]); getU(qr[i]);
		ql[i] --; qr[i] --;
	}
	init();
	for(int i = n - 1; i >= 0; i --) ver[i] = append(ver[i + 1], S[i]);
	
	rep(i, cnt) id[i] = -1;
	rep(i, n) id[ver[i]] = i;
	rep1(i, cnt - 1) {
		T[par[i]].push_back(i); T[i].push_back(par[i]);
	}
	
	rep(i, q) qy[ql[i]].push_back(i);
	rep(i, n) hv[0].push_back(ver[i]);
	solve(0);
	rep(i, q) ans[i] -= 1LL * (ql[i] + qr[i]) * (qr[i] - ql[i] + 1) / 2;
	rep(i, q) {
		putU(ans[i]); putC('\n');
	}
	putC(EOF);
	return 0;
}