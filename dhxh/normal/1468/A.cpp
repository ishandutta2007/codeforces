#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e5 + 5;

int n, m, t;

int a[maxn];
int c[maxn];
int p[maxn];
int f[maxn];

struct stnode {
	int l, r;
	int lc, rc;
	pair <int, int> mx;
	int mn;
};

struct st {
	stnode tree[maxn * 4];
	int tc;
	int root;
	
	int init_tree(int l, int r){
		int mid = (l + r) / 2;
		int pos = ++tc;
		
		tree[pos].l = l;
		tree[pos].r = r;
		
		if(l == r){
			tree[pos].mx = {0, -c[l]};
			tree[pos].mn = 0;
			return pos;
		}
		
		tree[pos].lc = init_tree(l, mid);
		tree[pos].rc = init_tree(mid + 1, r);
		
		tree[pos].mx = max(tree[tree[pos].lc].mx, tree[tree[pos].rc].mx);
		tree[pos].mn = max(tree[tree[pos].lc].mn, tree[tree[pos].rc].mn);
		
		return pos;
	}
	
	pair <int, int> query_tree_max(int pos, int l, int r){
		int mid = (tree[pos].l + tree[pos].r) / 2;
		
		if(tree[pos].l == l and r == tree[pos].r){
			return tree[pos].mx;
		}else{
			if(r <= mid){
				return query_tree_max(tree[pos].lc, l, r);
			}else if(l <= mid){
				return max(query_tree_max(tree[pos].lc, l, mid), query_tree_max(tree[pos].rc, mid + 1, r));
			}else{
				return query_tree_max(tree[pos].rc, l, r);
			}
		}
	}
	
	int query_tree_min(int pos, int l, int r){
		int mid = (tree[pos].l + tree[pos].r) / 2;
		
		if(tree[pos].l == l and r == tree[pos].r){
			return tree[pos].mn;
		}else{
			if(r <= mid){
				return query_tree_min(tree[pos].lc, l, r);
			}else if(l <= mid){
				return max(query_tree_min(tree[pos].lc, l, mid), query_tree_min(tree[pos].rc, mid + 1, r));
			}else{
				return query_tree_min(tree[pos].rc, l, r);
			}
		}
	}
	
	void update_tree(int pos, int p, int x){
		int mid = (tree[pos].l + tree[pos].r) / 2;
		
		if(tree[pos].l == tree[pos].r){
			tree[pos].mx.first = x;
			tree[pos].mn = c[p];
		}else{
			if(p <= mid){
				update_tree(tree[pos].lc, p, x);
			}else{
				update_tree(tree[pos].rc, p, x);
			}
			tree[pos].mx = max(tree[tree[pos].lc].mx, tree[tree[pos].rc].mx);
			tree[pos].mn = max(tree[tree[pos].lc].mn, tree[tree[pos].rc].mn);
		}
	}
	
	pair <int, int> query_max(int l, int r){
		if(l > r) return {0, 0};
		return query_tree_max(root, l, r);
	}
	
	int query_min(int l, int r){
		if(l > r) return 0;
		return query_tree_min(root, l, r);
	}
	
	void update(int p, int x){
		update_tree(root, p, x);
	}
	
	void init(){
		tc = 0;
		root = init_tree(0, n);
	}
} tree;

bool cmp(int x, int y){
	if(a[x] == a[y]) return x < y;
	return a[x] < a[y];
}

int main(){
	int i, j;
	
	scanf("%d", &t);
	
	while(t--){
		scanf("%d", &n);
		
		for(i=1;i<=n;i++){
			scanf("%d", &a[i]);
			c[i] = i;
		}
		
		sort(c + 1, c + n + 1, cmp);
		for(i=1;i<=n;i++){
			p[c[i]] = i;
		}
		
		tree.init();
		int ans = 0;
		
		for(i=1;i<=n;i++){
			auto ret = tree.query_max(0, p[i] - 1);
			int x = tree.query_min(p[i] + 1, n);
			if(x > -ret.second){
				f[i] = ret.first + 2;
			}else{
				f[i] = ret.first + 1;
			}
			tree.update(p[i], f[i]);
			ans = max(ans, f[i]);
		}
		
		printf("%d\n", ans);
	}
	
	return 0;
}