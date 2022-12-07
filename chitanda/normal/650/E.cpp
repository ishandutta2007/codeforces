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

const int maxn = 500100, maxm = 4 * maxn;
int n, u, v, tot, ans;
vector<int> g[maxn], f[maxn];
int fa[maxm], x[maxm], y[maxm], son[maxm][2], MAX[maxm], val[maxm], rev[maxm], size[maxm];

inline void down(int x){
	if(!x) return;
	if(rev[x]){
		swap(son[x][0], son[x][1]);
		if(son[x][0]) rev[son[x][0]] ^= 1;
		if(son[x][1]) rev[son[x][1]] ^= 1;
	}
	rev[x] = 0;
}

inline void update(int x){
	//down(son[x][0]), down(son[x][1]);
	size[x] = size[son[x][0]] + size[son[x][1]] + 1;
	MAX[x] = x;
	if(son[x][0] && val[MAX[son[x][0]]] > val[MAX[x]]) MAX[x] = MAX[son[x][0]];
	if(son[x][1] && val[MAX[son[x][1]]] > val[MAX[x]]) MAX[x] = MAX[son[x][1]];	 
}

inline bool truefa(int x){
	return (fa[x] && (x == son[fa[x]][0] || x == son[fa[x]][1]));
}

inline void rotate(int x){
	int y = fa[x], z = fa[y], k = x == son[y][1];
	if(truefa(y)) son[z][y == son[z][1]] = x; fa[x] = z;
	if(son[x][k ^ 1]) fa[son[x][k ^ 1]] = y; son[y][k] = son[x][k ^ 1];
	son[x][k ^ 1] = y, fa[y] = x; update(y);
}

inline void splay(int x){
	while(truefa(x)){
		int y = fa[x], z = fa[y];
		if(!truefa(y)) down(y), down(x), rotate(x);else{
			down(z), down(y), down(x);
			if((x == son[y][0]) ^ (y == son[z][0])) rotate(x), rotate(x);
			else rotate(y), rotate(x);
		}
	}down(x), update(x);
}

inline int access(int x){
	int p = x, q = 0;
	for(; p; p = fa[q]) splay(p), son[p][1] = q, update(q = p);
	return q;
}

inline int findroot(int x){
	for(x = access(x); down(x), update(x), son[x][0]; x = son[x][0]);
	splay(x); return x;
}

inline void makeroot(int x){
	int p = access(x); rev[p] ^= 1; splay(x);
}

inline void link(int x, int y){
	if(findroot(x) == findroot(y)) return;
	makeroot(x); fa[x] = y; access(x);
}

inline void cut(int x, int y){
	if(findroot(x) != findroot(y)) return;
	makeroot(x); access(y); splay(y);
	fa[son[y][0]] = 0, son[y][0] = 0; update(y);
}

inline int get(int x, int y){
	makeroot(x); access(y); splay(x);
	return MAX[x];
}

char ch;
void read(int &rt){
	rt = 0; ch = getchar();
	while(ch > '9'|| ch < '0') ch = getchar();
	while(ch <= '9' && ch >= '0') rt = rt * 10 + ch - '0', ch = getchar();
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	read(n);
	for(int i = 1; i < n; i++){
		read(u), read(v);
		if(u > v) swap(u, v);
		g[u].pb(v);
	}
	for(int i = 1; i < n; i++){
		read(u), read(v);
		if(u > v) swap(u,v);
		f[u].pb(v);
	}
	tot = n; FOR(i, 1, n) MAX[i] = i;
	for(int i = 1; i <= n; i++){
		sort(g[i].begin(), g[i].end()), sort(f[i].begin(), f[i].end());
		for(int j = 0, k = 0; j < (int)g[i].size(); j++){
			while(k + 1 < (int)f[i].size() && f[i][k] < g[i][j]) k++;
			x[++tot] = i, y[tot] = g[i][j];
			if(f[i].size() == 0 || f[i][k] != g[i][j]) val[tot] = 1, ans++;
			MAX[tot] = tot;
			link(i, tot), link(tot, g[i][j]);
		}
	}
	cout << ans << endl;
	for(int i = 1; i <= n; i++){
		for(int j = 0, k = 0; k < (int)f[i].size(); k++){
			while(j + 1 < (int)g[i].size() && g[i][j] < f[i][k]) j++;
			if(g[i].size() > 0 && f[i][k] == g[i][j]) continue;
			u = i, v = f[i][k];
			int t = get(u, v);
			cut(t, x[t]), cut(t, y[t]);
			x[++tot] = u, y[++tot] = v;
			val[tot] = 0, MAX[tot] = tot;
			link(u, tot), link(v, tot);
			printf("%d %d %d %d\n", x[t], y[t], u, v);
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