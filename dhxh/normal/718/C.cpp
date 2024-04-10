#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

long long mod = 1e9 + 7;
const int maxn = 1e5 + 5;

int n, m, t;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

struct matrix {
	long long f[2][2];
	
	matrix(){
		memset(f, 0, sizeof(f));
	};
};

matrix e;
matrix fib;
matrix h;

matrix add(matrix x, matrix y){
	int i, j;
	matrix ret;
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			ret.f[i][j] = (x.f[i][j] + y.f[i][j]) % mod;
		}
	}
	
	return ret;
}

matrix mul(matrix x, matrix y){
	int i, j, k;
	matrix ret;
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			for(k=0;k<2;k++){
				ret.f[i][j] = (ret.f[i][j] + x.f[i][k] * y.f[k][j]) % mod;
			}
		}
	}
	
	return ret;
}

matrix qpow(matrix b, int x){
	matrix ret = e;
	
	while(x){
		if(x & 1){
			ret = mul(ret, b);
		}
		
		b = mul(b, b);
		x >>= 1;
	}
	
	return ret;
}

struct node {
	int l, r;
	int lc, rc;
	matrix sum;
	matrix lazy;
};

struct st {
	int root;
	int tc;
	node tree[maxn * 4];
	
	int pushdown(int pos){
		tree[tree[pos].lc].sum = mul(tree[tree[pos].lc].sum, tree[pos].lazy);
		tree[tree[pos].rc].sum = mul(tree[tree[pos].rc].sum, tree[pos].lazy);
		tree[tree[pos].lc].lazy = mul(tree[tree[pos].lc].lazy, tree[pos].lazy);
		tree[tree[pos].rc].lazy = mul(tree[tree[pos].rc].lazy, tree[pos].lazy);
		tree[pos].lazy = e;
		
		return 0;
	}
	
	matrix query_tree(int pos, int l, int r){
		int mid = (tree[pos].l + tree[pos].r) / 2;
		
		if(tree[pos].l == l and r == tree[pos].r){
			return tree[pos].sum;
		}
		
		pushdown(pos);
		
		if(r <= mid){
			return query_tree(tree[pos].lc, l, r);
		}else if(l <= mid){
			return add(query_tree(tree[pos].lc, l, mid), query_tree(tree[pos].rc, mid + 1, r));
		}else{
			return query_tree(tree[pos].rc, l, r);
		}
	}
	
	int update_tree(int pos, int l, int r, matrix x){
		int mid = (tree[pos].l + tree[pos].r) / 2;
		
		if(tree[pos].l == l and r == tree[pos].r){
			tree[pos].sum = mul(tree[pos].sum, x);
			tree[pos].lazy = mul(tree[pos].lazy, x);
			
			return 0;
		}
		
		pushdown(pos);
		
		if(r <= mid){
			update_tree(tree[pos].lc, l, r, x);
		}else if(l <= mid){
			update_tree(tree[pos].lc, l, mid, x);
			update_tree(tree[pos].rc, mid + 1, r, x);
		}else{
			update_tree(tree[pos].rc, l, r, x);
		}
		
		tree[pos].sum = add(tree[tree[pos].lc].sum, tree[tree[pos].rc].sum);
		
		return 0;
	}
	
	int init_tree(int l, int r){
		int mid = (l + r) / 2;
		int pos = ++tc;
		
		tree[pos].l = l;
		tree[pos].r = r;
		tree[pos].lazy = e;
		
		if(l == r){
			tree[pos].sum = mul(h, qpow(fib, read() - 1));
		}else{
			tree[pos].lc = init_tree(l, mid);
			tree[pos].rc = init_tree(mid + 1, r);
			tree[pos].sum = add(tree[tree[pos].lc].sum, tree[tree[pos].rc].sum);
		}
		
		return pos;
	}
	
	long long query(int l, int r){
		return query_tree(root, l, r).f[0][0];
	}
	
	int update(int l, int r, int x){
		update_tree(root, l, r, qpow(fib, x));
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
	int op, l, r, x;
	
	e.f[0][0] = e.f[1][1] = 1;
	fib.f[0][0] = fib.f[0][1] = fib.f[1][0] = 1;
	h.f[0][0] = 1;
	
	n = read();
	m = read();
	
	tree.init();
	
	for(i=1;i<=m;i++){
		op = read();
		l = read();
		r = read();
		if(op == 1){
			x = read();
			tree.update(l, r, x);
		}else{
			printf("%lld\n", tree.query(l, r));
		}
	}
	
	return 0;
}