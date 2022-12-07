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
inline int ckmax(int &a, int b) { return a < b ? a = b, 1 : 0; }
inline int ckmin(int &a, int b) { return a > b ? a = b, 1 : 0; }
#define mid ((l + r) >> 1)

const int maxn = 500100;
//
int tot, root, last, par[maxn], go[maxn][27], val[maxn];
//root=last=tot=1
void extend(int w){
	int p = last, np;
	if(!go[p][w]){
		np = ++tot; val[np] = val[p] + 1;
		while(p && !go[p][w]) go[p][w] = np, p = par[p];
		if(!p) par[np] = root;
		else{
			int q = go[p][w];
			if(val[p] + 1 == val[q]) par[np] = q;
			else{
				int nq = ++tot; val[nq] = val[p] + 1;
				memcpy(go[nq], go[q], sizeof(go[q]));
				par[nq] = par[q];
				par[q] = par[np] = nq;
				while(p && go[p][w] == q) go[p][w] = nq, p = par[p];
			}
		}
		last = np;
	}else{
		int q = go[p][w];
		if(val[p] + 1 == val[q]) last = q;
		else{
			int nq = ++tot; val[nq] = val[p] + 1;
			memcpy(go[nq], go[q], sizeof(go[q]));
			par[nq] = par[q];
			par[q] = nq;
			while(p && go[p][w] == q) go[p][w] = nq, p = par[p];
			last = nq;
		}
	}
}

const int maxv = 4e6;
int tt, num[maxv], ls[maxv], rs[maxv];
int n, q, l, r, k, rt[maxn], ans[maxn], w[maxn];
vector<int> g[maxn];
char s[200100];
vector<pair<int, pair<int, int> > > ask[maxn];

inline void insert(int &t, int l, int r, int x){
	if(!t) t = ++tt;
	if(l == r){
		num[t]++;
		return;
	}
	if(x <= mid) insert(ls[t], l, mid, x);
	else insert(rs[t], mid + 1, r, x);
	num[t] = num[ls[t]] + num[rs[t]];
}

inline int merge(int u, int v, int l, int r){
	if(!u || !v) return u | v;
	if(l == r){
		num[u] += num[v];
		return u;
	}
	ls[u] = merge(ls[u], ls[v], l, mid);
	rs[u] = merge(rs[u], rs[v], mid + 1, r);
	num[u] = num[ls[u]] + num[rs[u]];
	return u;
}

inline int query(int t, int l, int r, int x, int y){
	if(!t || r < x || l > y) return 0;
	if(x <= l && y >= r) return num[t];
	return query(ls[t], l, mid, x, y) + query(rs[t], mid + 1, r, x, y);
}

inline void dfs(int t){
	for(auto v : g[t]){
		dfs(v);
		rt[t] = merge(rt[t], rt[v], 0, n - 1);
	}
	for(auto e : ask[t])
		ans[e.fi] = query(rt[t], 0, n - 1, e.se.fi, e.se.se);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	root = last = tot = 1;
	scanf("%d%d", &n, &q);
	for(int i = 0; i < n; ++i){
		scanf("%s", s);
		int m = strlen(s);
		last = root;
		for(int j = 0; j < m; ++j){
			extend(s[j] - 'a');
			insert(rt[last], 0, n - 1, i);
		}
		w[i] = last;
	}
	for(int i = 2; i <= tot; ++i) g[par[i]].pb(i);
	for(int i = 0; i < q; ++i){
		scanf("%d%d%d", &l, &r, &k);
		--l, --r, --k;
		ask[w[k]].pb(mkp(i, mkp(l, r)));
	}
	dfs(root);
	for(int i = 0; i < q; ++i)
		printf("%d\n", ans[i]);
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