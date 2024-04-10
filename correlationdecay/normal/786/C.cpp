#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#define maxn 100009
using namespace std;
int n, tot;
int a[maxn], rt[maxn], vis[maxn], nxt[maxn];

int tree[maxn * 50], ls[maxn * 50], rs[maxn * 50];

void build(int &o, int l, int r){
	o = tot++;
	tree[o] = 0;
	if(l == r)
		return;
	int m = (l + r) >> 1;
	build(ls[o], l, m);
	build(rs[o], m + 1, r);
}

void update(int &o, int last, int l, int r, int x ,int v){
	o = tot++;
	tree[o] = tree[last] + v;
	ls[o] = ls[last];
	rs[o] = rs[last];
	if(l == r)
		return;
	int m = (l + r) >> 1;
	if(x <= m)
		update(ls[o], ls[last], l, m, x, v);
	else
		update(rs[o], rs[last], m + 1, r, x, v);
}

int get_kth(int o, int l, int r, int k){
	if(l == r)
		return l;
	int cnt = tree[ls[o]];
	int m = (l + r) >> 1;
	if(k <= cnt)
		return get_kth(ls[o], l, m, k);
	else
		return get_kth(rs[o], m + 1, r, k - cnt);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	build(rt[n + 1], 1, n);
	memset(vis, -1, sizeof(vis));
	for(int i = n ; i >= 1; i--){
		nxt[i] = vis[a[i]];
		vis[a[i]] = i;
	}

	for(int i = n ; i >= 1; i--){
		if(nxt[i] == -1){
			update(rt[i], rt[i + 1], 1, n, i, 1);
		}
		else{
			int last = 0;
			update(last, rt[i + 1], 1, n, nxt[i], -1);
			update(rt[i], last, 1, n, i, 1);
		}
	}

	int cur = 1;
	for(int i = 1; i <= n; i++){
		int ans = 0;
		cur = 1;
		while(cur <= n){
			ans++;
			if(tree[rt[cur]] <= i)
				break;
			cur = get_kth(rt[cur], 1, n, i + 1);
		}
		printf("%d ", ans);
	}
	return 0;
}