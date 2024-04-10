//int!
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
using namespace std;
#define ll long long
#define pb push_back
#define mkp make_pair
#define ite iterator
#define fi first
#define se second
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define ROF(i, r, l) for(int i = r; i >= l; i--)
#define ls (t << 1)
#define rs ((t << 1) | 1)
#define mid ((l + r) >> 1)
#define L ls, l, mid
#define R rs, mid + 1, r

const int maxn = 400100, maxm = 8 * 400100;
int n, m, tot, x, y, type, c[maxn], re[maxn], pos[maxn], end[maxn], tag[maxm];
ll tr[maxm];
vector<int> g[maxn];

void dfs(int t, int fa){
	re[pos[t] = ++tot] = t;
	for(int i = 0; i < g[t].size(); i++)
		if(g[t][i] != fa) dfs(g[t][i], t);
	end[t] = tot;
}

void build(int t, int l, int r){
	if(l == r){
		tr[t] = 1LL << (c[re[l]] - 1);
		return;
	}
	build(L);
	build(R);
	tr[t] = tr[ls] | tr[rs];
}

void push_down(int t){
	if(!tag[t]) return;
	tr[ls] = 1LL << (tag[t] - 1);
	tr[rs] = 1LL << (tag[t] - 1);
	tag[ls] = tag[t];
	tag[rs] = tag[t];
	tag[t] = 0;
}

void modify(int t, int l, int r, int x, int y, int v){
	push_down(t);
	if(x <= l && y >= r){
		tr[t] = 1LL << (v - 1);
		tag[t] = v;
		return;
	}
	if(x <= mid) modify(L, x, y, v);
	if(y > mid) modify(R, x, y, v);
	tr[t] = tr[ls] | tr[rs];
}

ll query(int t, int l, int r, int x, int y){
	push_down(t);
	if(x <= l && y >= r){
		return tr[t];
	}
	ll ans = 0;
	if(x <= mid) ans = query(L, x, y);
	if(y > mid) ans |= query(R, x, y);
	tr[t] = tr[ls] | tr[rs];
	return ans;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", c + i);
	for(int i = 1; i < n; i++){
		scanf("%d%d", &x, &y);
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(1, 0);
	build(1, 1, n);
	for(int i = 1; i <= m; i++){
		scanf("%d%d", &type, &x);
		if(type == 1){
			scanf("%d", &y);
			modify(1, 1, n, pos[x], end[x], y);
		}else{
			ll mask = query(1, 1, n, pos[x], end[x]);
			int ans = 0;
			for(; mask; mask -= mask & -mask, ans++);
			printf("%d\n", ans);
		}
	}
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