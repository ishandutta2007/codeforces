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
#define mid ((l + r) >> 1)
#define LS son[t][0], l, mid
#define RS son[t][1], mid + 1, r

const int M = 800000, maxn = 400100, maxm = maxn * 22 * 2;
int n, m, tot, a[maxn], b[maxn], tmax, h[maxn], Lroot[maxn], Rroot[maxn], L[maxn], R[maxn];
bool imp[maxn];
int son[maxm][2], val[maxm];
vector<int> q[maxn], p;

inline int query(int t, int l, int r, int x, int y){
	if(x > y || !t) return 0;
	if(x <= l && y >= r) return val[t];
	if(y <= mid) return query(LS, x, y);
	else if(x > mid) return query(RS, x, y);
	else return max(query(LS, x, y), query(RS, x, y));
}

inline int insert(int ot, int l, int r, int x, int v){
	int t = ++tot; memcpy(son[t], son[ot], sizeof(son[ot]));
	if(l == r) { val[t] = v; return t; }
	if(x <= mid) son[t][0] = insert(LS, x, v);
	else son[t][1] = insert(RS, x, v);
	val[t] = max(val[son[t][0]], val[son[t][1]]);
	return t;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	cin >> n >> m;
	FOR(i, 1, n) scanf("%d", h + i), p.pb(h[i]);
	FOR(i, 1, m) scanf("%d%d", a + i, b + i), p.pb(b[i]);
	sort(p.begin(), p.end());
	FOR(i, 1, n) h[i] = lower_bound(p.begin(), p.end(), h[i]) - p.begin() + 1;
	FOR(i, 1, m) b[i] = lower_bound(p.begin(), p.end(), b[i]) - p.begin() + 1;
	FOR(i, 1, n){
		L[i] = query(Lroot[i - 1], 1, M, 1, h[i] - 1) + 1;
		Lroot[i] = insert(Lroot[i - 1], 1, M, h[i], L[i]);
		tmax = max(tmax, L[i]);
	}
	ROF(i, n, 1){
		R[i] = query(Rroot[i + 1], 1, M, h[i] + 1, M) + 1;
		Rroot[i] = insert(Rroot[i + 1], 1, M, h[i], R[i]);
	}
	FOR(i, 1, n)
		if(L[i] + R[i] == tmax + 1)
			q[L[i]].pb(i);
	FOR(i, 1, tmax)
		if(q[i].size() == 1) imp[q[i][0]] = 1;
	FOR(i, 1, m){
		int ans = query(Lroot[a[i] - 1], 1, M, 1, b[i] - 1) + query(Rroot[a[i] + 1], 1, M, b[i] + 1, M) + 1;
		ans = max(ans, imp[a[i]] ? tmax - 1 : tmax);
		printf("%d\n", ans);
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