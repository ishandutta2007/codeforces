#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define all(a) a.begin(), a.end()
#define ls t << 1
#define rs t << 1 | 1
#define lss ls, l, mid
#define rss rs, mid + 1, r

const int M = 100100 * 20 * 4;
struct Treap {
	int nodecnt , prior[M];
	int size[M] , c[M][2];
	int key[M];
	int val[M], sum[M];
	void clear() {
		nodecnt = 1;
		prior[0] = -1 << 30;
		c[0][0] = c[0][1] = 0;
		key[0] = size[0] = 0;
	}
	Treap () {
		clear();
	}
	inline void pushup(int p) {
		size[p] = size[c[p][0]] + size[c[p][1]] + 1;
		sum[p] = sum[c[p][0]] + sum[c[p][1]] + val[p];
	}
	inline void rotate (int& x , int t) {
		int y = c[x][t];
		c[x][t] = c[y][!t] , c[y][!t] = x;
		pushup(x) , pushup(y) , x = y;
	}
	inline void newnode(int& p , int w, int v) {
		p = nodecnt ++;
		val[p] = sum[p] = v, size[p] = 1;
		key[p] = w;
		prior[p] = rand() << 15 | rand(), c[p][0] = c[p][1] = 0;
	}
	void insert(int& p , int w, int v) {
		if (!p) {
			newnode(p , w, v);
			return;
		}
		assert(key[p] != w);
		if (key[p] == w)
			val[p] += v;
		else {
			int t = key[p] < w;
			insert(c[p][t] , w, v);
			if (prior[c[p][t]] > prior[p])
				rotate(p , t);
		}
		pushup(p);
	}
	void erase(int& p , int w, int v) {
		if (!p) return;
		if (key[p] == w) {
			if(!c[p][0] && !c[p][1])	p = 0;
			else{
				rotate(p , prior[c[p][0]] < prior[c[p][1]]);
				erase(p , w, v);
			}
		} else
			erase(c[p][key[p] < w] , w, v);
		pushup(p);
	}
	ll range(int p , int l) {
		if (!p) return 0;
		if (key[p] >= l) {
			ll ans = val[p];
			ans += sum[c[p][1]];
			ans += range(c[p][0] , l);
			return ans;
		}else return range(c[p][1] , l);
	}
}T;

int n, m;
int tr[100100 * 4];
ll res;
int a[100100], L[100100], last[100100];
set<int> g[100100];

void insert(int t, int l, int r, int x, int tmp){
	if(tmp != 0) T.insert(tr[t], tmp, x - tmp);
	if(l == r) return;
	int mid = (l + r) >> 1;
	if(x <= mid) insert(lss, x, tmp);
	else insert(rss, x, tmp);
}

void del(int t, int l, int r, int x, int tmp){
	if(tmp != 0) T.erase(tr[t], tmp, x - tmp);
	if(l == r) return;
	int mid = (l + r) >> 1;
	if(x <= mid) del(lss, x, tmp);
	else del(rss, x, tmp);
}

void ask(int t, int l, int r, int x, int y){
	if(x <= l && y >= r){
		res += T.range(tr[t], x);
		return;
	}
	int mid = (l + r) >> 1;
	if(x <= mid) ask(lss, x, y);
	if(y > mid) ask(rss, x, y);
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
		L[i] = last[a[i]];
		g[a[i]].insert(i);
		last[a[i]] = i;
		insert(1, 1, n, i, L[i]);
	}

	while(m--){
		static int ty, x, y;
		scanf("%d%d%d", &ty, &x, &y);
		if(ty == 1){
			if(a[x] == y) continue;
			auto it = g[a[x]].find(x);
			del(1, 1, n, x, L[x]);
			++it;
			if(it != g[a[x]].end()){
				del(1, 1, n, *it, L[*it]);
				L[*it] = L[x];
				insert(1, 1, n, *it, L[*it]);
			}
			g[a[x]].erase(x);										
			
			a[x] = y;
			it = g[y].lower_bound(x);
			if(it != g[y].end()){
				del(1, 1, n, *it, L[*it]);
				L[x] = L[*it];
				L[*it] = x;
				insert(1, 1, n, *it, x);
				insert(1, 1, n, x, L[x]);
			}else{
				int tmp;
				if(it == g[y].begin()) tmp = 0;
				else{
					--it; tmp = *it;
				}
				L[x] = tmp;
				insert(1, 1, n, x, L[x]);
			}
			g[y].insert(x);
		}else{
			res = 0;
			ask(1, 1, n, x, y);
			printf("%lld\n", res);
		}
	}
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}