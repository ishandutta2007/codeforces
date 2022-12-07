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
#define M 1000000007
#define mid ((l + r) >> 1)
#define ls (t << 1)
#define rs ((t << 1) | 1)
#define L ls, l, mid
#define R rs, mid + 1, r

const int maxn = 200100;
int n, q, tot;
int v[maxn], ty[maxn], p[maxn], dfn[maxn], ed[maxn], fa[maxn], d[maxn], re[maxn];
int val[maxn * 4], tag[maxn * 4];
vector<int> g[maxn];

inline void mul(int &a, int b) { a = (ll)a * b % M; }

int pow(int a, int b){
	int ans = 1;
	for(; b; mul(a, a), b >>= 1)
		if(b & 1) mul(ans, a);
	return ans;
}

void dfs(int t){
	re[dfn[t] = ++tot] = t;
	for(auto v : g[t]) dfs(v);
	ed[t] = tot;
}

void update(int t){
	val[t] = (val[ls] + val[rs]) % M;
}

void build(int t, int l, int r){
	tag[t] = 1;
	if(l == r){
		if(l == 1) val[t] = v[1];
		return;
	}
	build(L);
	build(R);
	update(t);
}

void down(int t){
	if(tag[t] != 1){
		mul(val[ls], tag[t]);
		mul(val[rs], tag[t]);
		mul(tag[ls], tag[t]);
		mul(tag[rs], tag[t]);
		tag[t] = 1;
	}
}

void modify_seg(int t, int l, int r, int x, int y, int v){
	if(l != r) down(t);
	if(x <= l && y >= r){
		mul(tag[t], v);
		mul(val[t], v);
		return;
	}
	if(x <= mid) modify_seg(L, x, y, v);
	if(y > mid) modify_seg(R, x, y, v);
	update(t);
}

void modify_poi(int t, int l, int r, int x){
	if(l != r) down(t);
	else{
		val[t] = (ll)v[re[x]] * tag[t] % M;
		return;
	}
	if(x <= mid) modify_poi(L, x);
	else modify_poi(R, x);
	update(t);
}

int query(int t, int l, int r, int x, int y){
	if(l != r) down(t);
	if(x <= l && y >= r) return val[t];
	if(y <= mid) return query(L, x, y);
	else if (x > mid) return query(R, x, y);
	else return (query(L, x, y) + query(R, x, y)) % M;
}

int ask(int t, int l, int r, int x){
	if(!x) return 1;
	if(l != r) down(t);
	else return tag[t];
	if(x <= mid) return ask(L, x);
	else return ask(R, x);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	cin >> v[n = 1] >> q;
	FOR(i, 1, q){
		scanf("%d%d", &ty[i], &p[i]);
		if(ty[i] == 1){
			scanf("%d", &v[++n]);
			fa[n] = p[i];
			g[p[i]].pb(n);
			p[i] = n;
		}
	}
	dfs(1); d[1] = 1;
	build(1, 1, n);
	FOR(i, 1, q){
		if(ty[i] == 1){
			modify_seg(1, 1, n, dfn[fa[p[i]]], ed[fa[p[i]]], (ll)(d[fa[p[i]]] + 1) * pow(d[fa[p[i]]], M - 2) % M);
			d[fa[p[i]]]++; d[p[i]]++;
			modify_poi(1, 1, n, dfn[p[i]]);
		}else{
			printf("%d\n", int((ll)query(1, 1, n, dfn[p[i]], ed[p[i]]) * pow(ask(1, 1, n, dfn[fa[p[i]]]), M - 2) % M));
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