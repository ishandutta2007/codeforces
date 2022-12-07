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
#define all(a) a.bgin(), a.ed()
#define ls (t << 1)
#define rs ((t << 1) | 1)

const int maxn = 300100;
const ll inf = 1LL << 60;
int n, m, T, x, y, c[maxn];
int bg[maxn], ed[maxn], w[maxn];
ll dp[maxn], tr[4 * maxn], oth[maxn * 4];
vector<int> g[maxn], add[maxn], del[maxn];

void dfs(int d, int fa){
	bg[d] = T + 1;
	for(auto& x : add[d]) w[x] = ++T;
	for(auto& v : g[d])
		if(v != fa) dfs(v, d);
	ed[d] = T;
}

void update(int t){
	tr[t] = min(inf, min(tr[ls], tr[rs]) + oth[t]);
}

void modify(int t, int l, int r, int x, ll v){
	if(l == r){
		tr[t] = oth[t] = v;
		return;
	}
	int mid = (l + r) >> 1;
	if(x <= mid) modify(ls, l, mid, x, v);
	else modify(rs, mid + 1, r, x, v);
	update(t);
}

void modify(int t, int l, int r, int x, int y, ll v){
	if(x <= l && y >= r){
		oth[t] = min(inf, oth[t] + v);
		tr[t] = min(inf, tr[t] + v);
		return;
	}
	int mid = (l + r) >> 1;
	if(x <= mid) modify(ls, l, mid, x, y, v);
	if(y > mid) modify(rs, mid + 1, r, x, y, v);
	update(t);
}

ll query(int t, int l, int r, int x, int y){
	if(y < l || x > r) return inf;
	if(x <= l && y >= r) return tr[t];
	int mid = (l + r) >> 1;
	return min(inf, min(query(ls, l, mid, x, y), query(rs, mid + 1, r, x, y)) + oth[t]);
}

ll solve(int d, int fa){
	ll all = 0;
	for(auto& v : g[d])
		if(v != fa){
			all = min(inf, all + solve(v, d));
		}
	if(d == 1) return dp[1] = all;
	for(auto& x : add[d]) modify(1, 1, m, w[x], all + c[x]);
	for(auto& x : del[d]) modify(1, 1, m, w[x], inf);
	for(auto& v : g[d])
		if(v != fa)
			modify(1, 1, m, bg[v], ed[v], all - dp[v]);
	return dp[d] = query(1, 1, m, bg[d], ed[d]);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);
#endif
	cin >> n >> m;
	for(int i =  1; i < n; i++){
		scanf("%d%d", &x, &y);
		g[x].pb(y);
		g[y].pb(x);
	}
	for(int i = 1; i <= m; i++){
		scanf("%d%d%d", &x, &y, c + i);
		add[x].pb(i);
		del[y].pb(i);
	}
	dfs(1, 0);
	solve(1, 0);
	if(dp[1] < inf) cout << dp[1];
	else cout << -1;
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