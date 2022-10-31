#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 1e6 + 5;

int n, m, t;

int prime[maxn];
bool isnp[maxn];
int d[maxn];
int pc = 0;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int gcd(int x, int y){
	if(!y){
		return x;
	}else{
		return gcd(y, x % y);
	}
}

int init(){
	long long i, j;
	
	d[0] = 0;
	d[1] = 1;
	
	for(i=2;i<=1e6;i++){
		if(!isnp[i]){
			pc++;
			prime[pc] = i;
			d[i] = 2;
		}
		
		for(j=2;j<=i and i*j<=1e6;j++){
			isnp[i * j] = true;
			if(gcd(i, j) == 1){
				d[i * j] = max(d[i * j], d[i] * d[j]);
			}else{
				d[i * j] = max(d[i * j], d[i] + 1);
			}
		}
	}
	
	return 0;
}

struct stnode {
	int l, r;
	int lc, rc;
	int cnt;
	long long sum;
};

struct st {
	int tc;
	stnode tree[maxn];
	int root;
	
	long long query_tree(int pos, int l, int r){
		int mid = (tree[pos].l + tree[pos].r) / 2;
		
		if(tree[pos].l == l and r == tree[pos].r){
			return tree[pos].sum;
		}else{
			if(r <= mid){
				return query_tree(tree[pos].lc, l, r);
			}else if(l <= mid){
				return query_tree(tree[pos].lc, l, mid) + query_tree(tree[pos].rc, mid + 1, r);
			}else{
				return query_tree(tree[pos].rc, l, r);
			}
		}
	}
	
	int update_tree(int pos, int l, int r){
		int mid = (tree[pos].l + tree[pos].r) / 2;
		
		if(!(tree[pos].l == l and r == tree[pos].r and tree[pos].cnt == tree[pos].r - tree[pos].l + 1)){
			
			if(tree[pos].l == tree[pos].r){
				tree[pos].sum = d[tree[pos].sum];
				if(tree[pos].sum <= 2){
					tree[pos].cnt = 1;
				}else{
					tree[pos].cnt = 0;
				}
			}else{
				if(r <= mid){
					update_tree(tree[pos].lc, l, r);
				}else if(l <= mid){
					update_tree(tree[pos].lc, l, mid);
					update_tree(tree[pos].rc, mid + 1, r);
				}else{
					update_tree(tree[pos].rc, l, r);
				}
				tree[pos].sum = tree[tree[pos].lc].sum + tree[tree[pos].rc].sum;
				tree[pos].cnt = tree[tree[pos].lc].cnt + tree[tree[pos].rc].cnt;
			}
		}
		
		return 0;
	}
	
	int init_tree(int l, int r){
		int pos = ++tc;
		int mid = (l + r) / 2;
		
		tree[pos].l = l;
		tree[pos].r = r;
		
		if(l == r){
			tree[pos].sum = read();
			if(tree[pos].sum <= 2){
				tree[pos].cnt = 1;
			}else{
				tree[pos].cnt = 0;
			}
		}else{
			tree[pos].lc = init_tree(l, mid);
			tree[pos].rc = init_tree(mid + 1, r);
			tree[pos].sum = tree[tree[pos].lc].sum + tree[tree[pos].rc].sum;
			tree[pos].cnt = tree[tree[pos].lc].cnt + tree[tree[pos].rc].cnt;
		}
		
		return pos;
	}
	
	long long query(int l, int r){
		return query_tree(root, l, r);
	}
	
	int update(int l, int r){
		update_tree(root, l, r);
		return 0;
	}
	
	int init(){
		tc = 0;
		root = init_tree(1, n);
		return 0;
	}
} tree;

int main(){
	int i, j;
	int x, y;
	int op;
	
	init();
	
	n = read();
	m = read();
	
	tree.init();
	
	while(m--){
		op = read();
		x = read();
		y = read();
		
		if(op == 1){
			tree.update(x, y);
		}else{
			printf("%lld\n", tree.query(x, y));
		}
	}
	
	return 0;
}