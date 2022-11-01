#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 2e5 + 5;

long long inf = 0x3f3f3f3f3f3f3f3f;

int n, m;

long long a[maxn];
int ans[maxn];

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
		tree[pos].lazy = 0;
		
		if(l == r){
			tree[pos].minx = a[l];
			return pos;
		}
		
		tree[pos].lc = init_tree(l, mid);
		tree[pos].rc = init_tree(mid + 1, r);
		
		tree[pos].minx = min(tree[tree[pos].lc].minx, tree[tree[pos].rc].minx);
		
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
	
	int query_tree(int pos){
		int mid = (tree[pos].l + tree[pos].r) / 2;
		
		if(tree[pos].l == tree[pos].r){
			return tree[pos].l;
		}else{
			if(tree[pos].lazy){
				pushdown(pos);
			}
			if(tree[tree[pos].rc].minx == 0){
				return query_tree(tree[pos].rc);
			}else{
				return query_tree(tree[pos].lc);
			}
		}
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
	
	int query(){
		int ret = query_tree(root);
		return ret;
	}
	
	int update(int p, int x){
		update_tree(root, p, p, inf);
		update_tree(root, p, n, -x);
		return 0;
	}
	
	int init(int x){
		int i, j;
		tc = 0;
		root = 1;
		
		init_tree(1, x);
		
		return 0;
	}
} tree;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	
	cin >> n;
	
	for(i=1;i<=n;i++){
		cin >> a[i];
	}
	
	tree.init(n);
	
	for(i=1;i<=n;i++){
		int x = tree.query();
		ans[x] = i;
		tree.update(x, i);
	}
	
	for(i=1;i<=n;i++){
		cout << ans[i] << " ";
	}
	cout << endl;
	
	return 0;
}