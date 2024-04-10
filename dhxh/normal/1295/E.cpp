#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;

int n, m;

int t;

int p[maxn];
int b[maxn];
long long a[maxn];


struct stnode {
	int l, r;
	int lc, rc;
	long long lazy;
	long long minx;
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
		tree[pos].lazy = tree[pos].minx = 0;
		
		if(l == r){
			tree[pos].minx = 0;
			return pos;
		}
		
		tree[pos].lc = init_tree(l, mid);
		tree[pos].rc = init_tree(mid + 1, r);
		
		return pos;
	}
	
	int pushdown(int pos){
		tree[tree[pos].lc].minx += tree[pos].lazy;
		tree[tree[pos].rc].minx += tree[pos].lazy;
		tree[tree[pos].lc].lazy += tree[pos].lazy;
		tree[tree[pos].rc].lazy += tree[pos].lazy;
		tree[pos].lazy = 0;
		
		return 0;
	}
	
	int update_tree(int pos, int l, int r, long long x){
		int mid = (tree[pos].l + tree[pos].r) / 2;
		
		if(tree[pos].l == l and r == tree[pos].r){
			tree[pos].lazy += x;
			tree[pos].minx += x;
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
			tree[pos].minx = min(tree[tree[pos].lc].minx, tree[tree[pos].rc].minx);
		}
		return 0;
	}
	
	long long query(){
		return tree[root].minx;
	}
	
	int update(int l, int r, long long x){
		update_tree(root, l, r, x);
		return 0;
	}
	
	int init(int x){
		tc = 0;
		root = 1;
		
		init_tree(1, x);
		
		return 0;
	}
} tree;

int main(){
	long long i, j;
	
	scanf("%d", &n);
	
	for(i=1;i<=n;i++){
		scanf("%d", &p[i]);
		b[p[i]] = i;
	}
	
	for(i=1;i<=n;i++){
		scanf("%lld", &a[i]);
	}
	
	long long ans = min(a[1], a[n]);
	tree.init(n - 1);
	
	long long sum = 0;
	for(i=1;i<n;i++){
		sum += a[i];
		tree.update(i, i, sum);
	}
	
	for(i=1;i<n;i++){
		if(b[i] < n) tree.update(b[i], n - 1, -a[b[i]]);
		if(b[i] > 1) tree.update(1, b[i] - 1, a[b[i]]);
		ans = min(ans, tree.query());
	}
	
	printf("%lld\n", ans);
	
	return 0;
}