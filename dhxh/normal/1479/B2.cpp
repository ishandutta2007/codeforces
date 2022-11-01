#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

int n, m, t;

struct stnode {
	int l, r;
	int lc, rc;
	int lazy;
	int mx;
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
		tree[pos].lazy = 0;
		tree[pos].mx = 0x3f3f3f3f;
		
		if(l == r){
			if(l == 0) tree[pos].mx = 1;
			return pos;
		}
		tree[pos].lc = init_tree(l, mid);
		tree[pos].rc = init_tree(mid + 1, r);
		tree[pos].mx = min(tree[tree[pos].lc].mx, tree[tree[pos].rc].mx);
		return pos;
	}
	
	int pushdown(int pos){
		tree[tree[pos].lc].mx += tree[pos].lazy;
		tree[tree[pos].rc].mx += tree[pos].lazy;
		
		tree[tree[pos].lc].lazy += tree[pos].lazy;
		tree[tree[pos].rc].lazy += tree[pos].lazy;
		
		tree[pos].lazy = 0;
		
		return 0;
	}
	
	int query_tree(int pos, int l, int r){
		int mid = (tree[pos].l + tree[pos].r) / 2;
		
		if(tree[pos].l == l and r == tree[pos].r){
			return tree[pos].mx;
		}else{
			if(tree[pos].lazy){
				pushdown(pos);
			}
			if(r <= mid){
				return query_tree(tree[pos].lc, l, r);
			}else if(l <= mid){
				return min(query_tree(tree[pos].lc, l, mid), query_tree(tree[pos].rc, mid + 1, r));
			}else{
				return query_tree(tree[pos].rc, l, r);
			}
		}
	}
	
	int update_tree(int pos, int l, int r, int x){
		int mid = (tree[pos].l + tree[pos].r) / 2;
		
		if(tree[pos].l == l and r == tree[pos].r){
			tree[pos].lazy += x;
			tree[pos].mx += x;
		}else{
			if(tree[pos].lazy){
				pushdown(pos);
			}
			if(r <= mid){
				update_tree(tree[pos].lc, l, r, x);
			}else if(l <= mid){
				update_tree(tree[pos].lc, l, mid, x);
				update_tree(tree[pos].rc, mid + 1, r, x);
			}else{
				update_tree(tree[pos].rc, l, r, x);
			}
			tree[pos].mx = min(tree[tree[pos].lc].mx, tree[tree[pos].rc].mx);
		}
		return 0;
	}
	
	int query(int l, int r){
		if(r < l or r > n or l > n) return 0x3f3f3f3f;
		return query_tree(root, l, r);
	}
	
	int update(int l, int r, int x){
		update_tree(root, l, r, x);
		return 0;
	}
	
	int init(int x){
		tc = 0;
		root = init_tree(0, x);
		return 0;
	}
} tree;

int a[maxn];

int main(){
	int i, j;
	
	scanf("%d", &n);
	
	for(i=1;i<=n;i++){
		scanf("%d", &a[i]);
	}
	
	tree.init(n);
	
	for(i=2;i<=n;i++){
		int x = min(tree.query(0, a[i] - 1) + 1, tree.query(a[i] + 1, n) + 1);
		x = min(x, tree.query(a[i], a[i]));
		if(a[i] != a[i - 1]){
			tree.update(0, n, 1);
		}
		int y = tree.query(a[i - 1], a[i - 1]);
		
		if(x < y){
			tree.update(a[i - 1], a[i - 1], x - y);
		}
	}
	
	printf("%d\n", tree.query(0, n));
	
	return 0;
}