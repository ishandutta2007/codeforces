#include <bits/stdc++.h>

using namespace std;

int n, m, k;

long long a[55][20005];
long long sum[55][20005];

long long f[55][20005];

int z;

struct stnode {
	int l, r;
	int lc, rc;
	long long lazy;
	long long maxx;
};
 
struct st {
	stnode tree[20005 * 4];
	int tc;
	int root;
	
	int init_tree(int l, int r){
		int mid = (l + r) / 2;
		int pos = ++tc;
		
		tree[pos].l = l;
		tree[pos].r = r;
		tree[pos].lazy = tree[pos].maxx = 0;
		
		if(l == r){
			tree[pos].maxx = f[z][l];
			return pos;
		}
		
		tree[pos].lc = init_tree(l, mid);
		tree[pos].rc = init_tree(mid + 1, r);
		
		tree[pos].maxx = max(tree[tree[pos].lc].maxx, tree[tree[pos].rc].maxx);
		
		return pos;
	}
	
	int pushdown(int pos){
		tree[tree[pos].lc].maxx += tree[pos].lazy;
		tree[tree[pos].rc].maxx += tree[pos].lazy;
		tree[tree[pos].lc].lazy += tree[pos].lazy;
		tree[tree[pos].rc].lazy += tree[pos].lazy;
		tree[pos].lazy = 0;
		
		return 0;
	}
	
	int update_tree(int pos, int l, int r, long long x){
		int mid = (tree[pos].l + tree[pos].r) / 2;
		
		if(tree[pos].l == l and r == tree[pos].r){
			tree[pos].lazy += x;
			tree[pos].maxx += x;
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
			tree[pos].maxx = max(tree[tree[pos].lc].maxx, tree[tree[pos].rc].maxx);
		}
		return 0;
	}
	
	long long query(){
		return tree[root].maxx;
	}
	
	int update(int l, int r, long long x){
		update_tree(root, l, r, x);
		return 0;
	}
	
	int init(int x){
		tc = 0;
		root = init_tree(1, x);
		return 0;
	}
} tree;

int main(){
	int i, j;
	
	scanf("%d%d%d", &n, &m, &k);
	
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf("%lld", &a[i][j]);
			sum[i][j] = sum[i][j - 1] + a[i][j];
		}
	}
	
	for(j=1;j<=m-k+1;j++){
		f[1][j] = sum[1][j + k - 1]  - sum[1][j - 1];
		f[1][j] += sum[2][j + k - 1]  - sum[2][j - 1];
	}
	
	for(i=2;i<=n;i++){
		z = i - 1;
		tree.init(m - k + 1);
		for(j=1;j<=k;j++){
			tree.update(1, min(j, m - k + 1), -a[i][j]);
		}
		for(j=1;j<=m-k+1;j++){
			f[i][j] = sum[i][j + k - 1]  - sum[i][j - 1];
			f[i][j] += sum[i + 1][j + k - 1]  - sum[i + 1][j - 1];
			f[i][j] += tree.query();
			tree.update(max(1, j - k + 1), j, a[i][j]);
			if(j + 1 <= m - k + 1) tree.update(j + 1, min(m - k + 1, j + k), -a[i][j + k]);
		}
	}
	
	long long ans = 0;
	for(j=1;j<=m-k+1;j++){
		ans = max(ans, f[n][j]);
	}
	
	printf("%lld\n", ans);
	
	return 0;
}