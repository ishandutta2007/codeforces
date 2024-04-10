#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;
const long long inf = 0x3f3f3f3f3f3f3f3f;

int n, m;

long long a[maxn];

struct ex {
	long long cnt[15];
	long long ans;
	
	int init(long long x){
		long long y = x;
		for(int i=0;i<=10;i++){
			if(y % 10){
				cnt[i] = x;
			}else{
				cnt[i] = inf;
			}
			y /= 10;
		}
		
		ans = inf;
		return 0;
	}
};

struct stnode {
	int l, r;
	int lc, rc;
	ex inf;
};

ex merge(ex x, ex y){
	ex ret;
	
	ret.ans = min(x.ans, y.ans);
	
	for(int i=0;i<=10;i++){
		ret.cnt[i] = min(x.cnt[i], y.cnt[i]);
	}
	
	for(int i=0;i<=10;i++){
		ret.ans = min(ret.ans, x.cnt[i] + y.cnt[i]);
	}
	
	return ret;
}

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
			tree[pos].inf.init(a[l]);
			return pos;
		}
		
		tree[pos].lc = init_tree(l, mid);
		tree[pos].rc = init_tree(mid + 1, r);
		
		tree[pos].inf = merge(tree[tree[pos].lc].inf, tree[tree[pos].rc].inf);
		
		return pos;
	}
	
	ex query_tree(int pos, int l, int r){
		int mid = (tree[pos].l + tree[pos].r) / 2;
		
		if(tree[pos].l == l and r == tree[pos].r){
			return tree[pos].inf;
		}else{
			if(r <= mid){
				return query_tree(tree[pos].lc, l, r);
			}else if(l <= mid){
				return merge(query_tree(tree[pos].lc, l, mid), query_tree(tree[pos].rc, mid + 1, r));
			}else{
				return query_tree(tree[pos].rc, l, r);
			}
		}
	}
	
	int update_tree(int pos, int p, long long x){
		int mid = (tree[pos].l + tree[pos].r) / 2;
		
		if(tree[pos].l == tree[pos].r){
			tree[pos].inf.init(x);
		}else{
			if(p <= mid){
				update_tree(tree[pos].lc, p, x);
			}else{
				update_tree(tree[pos].rc, p, x);
			}
			tree[pos].inf = merge(tree[tree[pos].lc].inf, tree[tree[pos].rc].inf);
		}
		return 0;
	}
	
	long long query(int l, int r){
		ex ret = query_tree(root, l, r);
		if(ret.ans == inf)return -1;
		return ret.ans;
	}
	
	int update(int p, long long x){
		update_tree(root, p, x);
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
	int p, l, r, k;
	long long x;
	int opt;
	
	n = read();
	m = read();
	
	for(i=1;i<=n;i++){
		a[i] = read();
	}
	
	tree.init(n);
	
	for(i=1;i<=m;i++){
		opt = read();
		if(opt == 1){
			p = read();
			x = read();
			tree.update(p, x);
		}else{
			l = read();
			r = read();
			printf("%lld\n", tree.query(l, r));
		}
	}
	
	return 0;
}