#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;

int n, m;

long long a[maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

struct node {
	int l, r;
	int lc, rc;
	int cnt;
	long long sum;
	long long left, right;
	long long lazy;
};

struct st {
	int root;
	int tc;
	node tree[maxn * 4];
	
	int pushdown(int pos){
		int mid = (tree[pos].l + tree[pos].r) >> 1;
		
		tree[tree[pos].lc].sum += 1ll * (mid - tree[pos].l + 1) * tree[pos].lazy;
		tree[tree[pos].rc].sum += 1ll * (tree[pos].r - mid) * tree[pos].lazy;
		
		tree[tree[pos].lc].left += tree[pos].lazy;
		tree[tree[pos].rc].left += tree[pos].lazy;
		
		tree[tree[pos].lc].right += tree[pos].lazy;
		tree[tree[pos].rc].right += tree[pos].lazy;
		
		tree[tree[pos].lc].lazy += tree[pos].lazy;
		tree[tree[pos].rc].lazy += tree[pos].lazy;
		
		tree[pos].lazy = 0;
		
		return 0;
	}
	
	int query_tree_cnt(int pos, int x){
		int mid = (tree[pos].l + tree[pos].r) >> 1;
		
		if(tree[pos].l == x){
			return tree[pos].cnt;
		}
		
		if(tree[pos].lazy){
			pushdown(pos);
		}
		
		if(x > mid){
			return query_tree_cnt(tree[pos].rc, x);
		}else{
			int l = query_tree_cnt(tree[pos].lc, x);
			
			if(l == mid - x + 1 and tree[tree[pos].lc].right + a[tree[tree[pos].lc].r] == tree[tree[pos].rc].left){
				return l + query_tree_cnt(tree[pos].rc, mid + 1);
			}else{
				return l;
			}
		}
	}
	
	long long query_tree(int pos, int l, int r){
		int mid = (tree[pos].l + tree[pos].r) >> 1;
		
		if(tree[pos].l == l and r == tree[pos].r){
			return tree[pos].sum;
		}
		
		if(tree[pos].lazy){
			pushdown(pos);
		}
		
		if(r <= mid){
			return query_tree(tree[pos].lc, l, r);
		}else if(l <= mid){
			return query_tree(tree[pos].lc, l, mid) + query_tree(tree[pos].rc, mid + 1, r);
		}else{
			return query_tree(tree[pos].rc, l, r);
		}
	}
	
	int update_tree(int pos, int l, int r, long long x){
		int mid = (tree[pos].l + tree[pos].r) >> 1;
		
		if(tree[pos].l == l and r == tree[pos].r){
			tree[pos].sum += 1ll * (r - l + 1) * x;
			tree[pos].lazy += x;
			tree[pos].left += x;
			tree[pos].right += x;
			return 0;
		}
		
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
		
		tree[pos].left = tree[tree[pos].lc].left;
		tree[pos].right = tree[tree[pos].rc].right;
		tree[pos].sum = tree[tree[pos].lc].sum + tree[tree[pos].rc].sum;
		
		if(tree[tree[pos].lc].cnt == mid - tree[pos].l + 1){
			if(tree[tree[pos].lc].right + a[tree[tree[pos].lc].r] == tree[tree[pos].rc].left){
				tree[pos].cnt = tree[tree[pos].lc].cnt + tree[tree[pos].rc].cnt;
			}else{
				tree[pos].cnt = tree[tree[pos].lc].cnt;
			}
		}else{
			tree[pos].cnt = tree[tree[pos].lc].cnt;
		}
		
		return 0;
	}
	
	int init_tree(int l, int r){
		int mid = (l + r) >> 1;
		int pos = ++tc;
		
		tree[pos].l = l;
		tree[pos].r = r;
		tree[pos].lazy = 0;
		tree[pos].cnt = 1;
		
		if(l == r){
			tree[pos].sum = tree[pos].left = tree[pos].right = read();
		}else{
			tree[pos].lc = init_tree(l, mid);
			tree[pos].rc = init_tree(mid + 1, r);
			tree[pos].sum = tree[tree[pos].lc].sum + tree[tree[pos].rc].sum;
			tree[pos].left = tree[tree[pos].lc].left;
			tree[pos].right = tree[tree[pos].rc].right;
		}
		
		return pos;
	}
	
	long long query(int l, int r){
		return query_tree(root, l, r);
	}
	
	int update(long long x, long long y){
		int pos;
		int l;
		
		update_tree(root, x, x, y);
		pos = x;
		
		while(pos < n and (x = query_tree(root, pos, pos)) + a[pos] > (y = query_tree(root, pos + 1, pos + 1))){
			l = query_tree_cnt(root, pos + 1);
			update_tree(root, pos + 1, pos + l, x + a[pos] - y);
			pos = pos + l;
		}
		
		return 0;
	}
	
	int init(){
		tc = 0;
		
		root = init_tree(1, n);
		
		return 0;
	}
};

st tree;

int main(){
	int i, j;
	long long x, y, l = 0;
	char ch;
	
	n = read();
	
	tree.init();
	
	for(i=1;i<n;i++){
		a[i] = read();
	}
	
	m = read();
	
	while(m--){
		scanf(" %c", &ch);
		x = read();
		y = read();
		
		if(ch == 's'){
			printf("%lld\n", tree.query(x, y));
		}else{
			tree.update(x, y);
		}
	}
	
	return 0;
}