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
#include <bitset>
#include <cmath>
using namespace std;
#define ll long long
#define pb push_back
#define mkp make_pair
#define ite iterator
#define fi first
#define se second
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define ROF(i, r, l) for(int i = r; i >= l; i--)
#define mid ((l + r) >> 1)
#define ls (t << 1)
#define rs ((t << 1) | 1)
#define L ls, l, mid
#define R rs, mid + 1, r

typedef bitset<1000> mybit;
const int maxn = 100100, M = 131072;
int n, m, x, y, q, ty, tt, a[maxn], dfn[maxn], end[maxn], re[maxn], tag[300000];
mybit tr[300000], aim, cnt, get, high;
vector<int> g[maxn];

void pre(){
	FOR(i, 2, m - 1){
		bool ok = 1;
		for(int j = 2; j <= (int)sqrt(i + .5); j++)
			if(i % j == 0) { ok = 0; break; }
		if(ok) aim[i] = 1;
	}
}

void dfs(int x, int fa){
	re[dfn[x] = ++tt] = x;
	for(int i = 0; i < (int)g[x].size(); i++)
		if(g[x][i] != fa)
			dfs(g[x][i], x);
	end[x] = tt;
}

void build(int t, int l, int r){
	if(l == r){
		tr[t][a[re[l]]] = 1;
		return;
	}
	build(L), build(R);
	tr[t] = tr[ls] | tr[rs];
}

void change(int t, int v){
	tag[t] = (tag[t] + v) % m;
	tr[t] = ((tr[t] << v) | (tr[t] >> (m - v)));
}

void push_down(int t, int l, int r){
	if(l == r || !tag[t]) return;
	change(ls, tag[t]);
	change(rs, tag[t]);
	tag[t] = 0;
}

void modify(int t, int l, int r, int x, int y, int v){
	if(x <= l && y >= r){
		change(t, v);
		return;
	}
	push_down(t, l, r);
	if(x <= mid) modify(L, x, y, v);
	if(y > mid) modify(R, x, y, v);
	tr[t] = tr[ls] | tr[rs];
}

void query(int t, int l, int r, int x, int y){
	if(x <= l && y >= r){
		get = get | tr[t];
		return;
	}
	push_down(t, l, r);
	if(x <= mid) query(L, x, y);
	if(y > mid) query(R, x, y);
	tr[t] = tr[ls] | tr[rs];
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	cin >> n >> m;
	pre(); FOR(i, 0, m - 1) high[i] = 1;
	FOR(i, 1, n) scanf("%d", a + i), a[i] %= m;
	FOR(i, 2, n) scanf("%d%d", &x, &y), g[x].pb(y), g[y].pb(x);
	dfs(1, 0);
	build(1, 1, M);
	cin >> q;
	while(q--){
		scanf("%d%d", &ty, &x);
		if(ty == 1){
			scanf("%d", &y); y %= m;
			modify(1, 1, M, dfn[x], end[x], y);
		}else{
			get.reset();
			query(1, 1, M, dfn[x], end[x]);
			get = get & aim;
			printf("%d\n", (int)get.count());
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