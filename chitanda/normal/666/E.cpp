//int!
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define ROF(i, r, l) for(int i = r; i >= l; i--)
#define all(a) a.begin(), a.end()
#define mid ((l + r) >> 1)
inline int ckmax(int &a, int b) { return a < b ? a = b, 1 : 0; }
inline int ckmin(int &a, int b) { return a > b ? a = b, 1 : 0; }

const int LOG = 21;
const int maxn = 2e6;
int tot, root, last, par[maxn], go[maxn][27], len[maxn], size[maxn];
int fa[maxn][LOG];
vector<int> son[maxn];
vector<pair<int, pair<int, int> > >query[maxn];

inline void extend(int w){
	int p = last, np;
	if(!go[p][w]){
		np = ++tot; len[np] = len[p] + 1;
		while(p && !go[p][w]) go[p][w] = np, p = par[p];
		if(!p) par[np] = root;
		else{
			int q = go[p][w];
			if(len[p] + 1 == len[q]) par[np] = q;
			else{
				int nq = ++tot; len[nq] = len[p] + 1;
				memcpy(go[nq], go[q], sizeof(go[q]));
				par[nq] = par[q];
				par[q] = par[np] = nq;
				while(p && go[p][w] == q) go[p][w] = nq, p = par[p];
			}
		}
		last = np;
	}else{
		int q = go[p][w];
		if(len[p] + 1 == len[q]) last = q;
		else{
			int nq = ++tot; len[nq] = len[p] + 1;
			memcpy(go[nq], go[q], sizeof(go[q]));
			par[nq] = par[q];
			par[q] = nq;
			while(p && go[p][w] == q) go[p][w] = nq, p = par[p];
			last = nq;
		}
	}
}

const int maxm = 50100;
int n, m, q;
string s, t[maxm];
int re_s[maxn];
pair<int, int> ans[maxm * 10];

const int maxp = 4e6;
int tt;
int val[maxp], rt[maxn], ls[maxp], rs[maxp];
pair<int, int> maxv[maxp];

inline void insert(int &t, int l, int r, int p){
	if(!t) t = ++tt;
	if(l == r){
		val[t]++;
		maxv[t] = mkp(val[t], -p);
		return;
	}
	if(p <= mid) insert(ls[t], l, mid, p);
	else insert(rs[t], mid + 1, r, p);
	maxv[t] = max(maxv[ls[t]], maxv[rs[t]]);
}

inline int merge(int u, int v, int l, int r){
	if(!u || !v) return u | v;
	if(l == r){
		val[u] += val[v];
		maxv[u] = mkp(val[u], -l);
		return u;
	}
	ls[u] = merge(ls[u], ls[v], l, mid);
	rs[u] = merge(rs[u], rs[v], mid + 1, r);
	maxv[u] = max(maxv[ls[u]], maxv[rs[u]]);
	return u;
}

inline pair<int, int> ask(int t, int l, int r, int x, int y){
	if(!t || x > r || y < l) return mkp(-1, 0);
	if(x <= l && y >= r) return maxv[t];
	return max(ask(ls[t], l, mid, x, y), ask(rs[t], mid + 1, r, x, y));
}

inline void dfs(int t){
	for(auto v : son[t]){
		dfs(v);
		rt[t] = merge(rt[t], rt[v], 0, m - 1);
	}
	for(auto e : query[t])
		ans[e.fi] = max(ans[e.fi], ask(rt[t], 0, m - 1, e.se.fi, e.se.se));
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("e.in", "r", stdin);
	freopen("e.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	last = tot = root = 1;
	maxv[0] = mkp(-1, 0);
	cin >> s;
	n = s.size();
	for(int i = 0; i < n; ++i){
		extend(s[i] - 'a');
		re_s[i] = last;
	}
	cin >> m;
	for(int i = 0; i < m; ++i){
		cin >> t[i];
		last = root;
		for(int j = 0; j < t[i].size(); ++j){
			extend(t[i][j] - 'a');
			insert(rt[last], 0, m - 1, i);
		}
	}
	for(int i = 2; i <= tot; ++i){
		son[par[i]].pb(i);
		fa[i][0] = par[i];
	}
	for(int j = 1; j < LOG; ++j)
		for(int i = 1; i <= tot; ++i)
			fa[i][j] = fa[fa[i][j - 1]][j - 1];
	
	cin >> q;
	for(int i = 0; i < q; ++i){
		int l, r, sl, sr;
		cin >> l >> r >> sl >> sr;
		--l, --r, --sl, --sr;
		int u = re_s[sr];
		for(int j = LOG - 1; j >= 0; --j)
			if(len[fa[u][j]] >= sr - sl + 1) u = fa[u][j];
		ans[i] = mkp(0, -l);
		query[u].pb(mkp(i, mkp(l, r)));
	}
	dfs(1);
	for(int i = 0; i < q; ++i)
		cout << -ans[i].se + 1 << ' ' << ans[i].fi << endl;
  return 0;
}
/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                BUG
*/