#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 1e5 + 5;

int n, m, t;

int a[maxn];

struct node {
	int l, r;
	int lc, rc;
	int minn;
	int lazy;
};

struct st {
	node tree[4 * maxn];
	int root;
	int tc;
	
	int push_down(int pos){
		tree[tree[pos].lc].minn += tree[pos].lazy;
		tree[tree[pos].rc].minn += tree[pos].lazy;
		tree[tree[pos].lc].lazy += tree[pos].lazy;
		tree[tree[pos].rc].lazy += tree[pos].lazy;
		tree[pos].lazy = 0;
	}
	
	int update_tree(int pos, int l, int r){
		int mid = (tree[pos].l + tree[pos].r) / 2;
		
		if(tree[pos].lazy){
			push_down(pos);
		}
		
		if(tree[pos].l == l and r == tree[pos].r){
			tree[pos].minn -= 1;
			tree[pos].lazy -= 1;
		}else{
			if(r <= mid){
				update_tree(tree[pos].lc, l, r);
			}else if(l <= mid){
				update_tree(tree[pos].lc, l, mid);
				update_tree(tree[pos].rc, mid + 1, r);
			}else{
				update_tree(tree[pos].rc, l, r);
			}
			
			tree[pos].minn = min(tree[tree[pos].lc].minn, tree[tree[pos].rc].minn);
		}
		
		return 0;
	}
	
	int query_tree(int pos, int l, int r){
		int mid = (tree[pos].l + tree[pos].r) / 2;
		
		if(tree[pos].lazy){
			push_down(pos);
		}
		
		if(tree[pos].l == l and r == tree[pos].r){
			return tree[pos].minn;
		}else{
			if(r <= mid){
				return query_tree(tree[pos].lc, l, r);
			}else if(l <= mid){
				return min(query_tree(tree[pos].lc, l, mid), query_tree(tree[pos].rc, mid + 1, r));
			}else{
				return query_tree(tree[pos].rc, l, r);
			}
		}
	}
	
	int init_tree(int l, int r){
		int mid = (l + r) / 2;
		int pos = ++tc;
		
		tree[pos].l = l;
		tree[pos].r = r;
		
		if(l == r){
			tree[pos].minn = a[l];
		}else{
			tree[pos].lc = init_tree(l, mid);
			tree[pos].rc = init_tree(mid + 1, r);
			tree[pos].minn = min(tree[tree[pos].lc].minn, tree[tree[pos].rc].minn);
		}
		
		return pos;
	}
	
	int query(int l, int r){
		return query_tree(root, l, r);
	}
	
	int update(int x, int y){
		update_tree(root, x, y);
		return 0;
	}
	
	int init(){
		tc = 0;
		root = init_tree(1, n);
		return 0;
	}
};

st tree[2];

int f[maxn][2];

struct ex {
	int l, r, n;
} e[maxn];

bool cmpa(ex x, ex y){
	return x.r < y.r;
}

bool cmpb(ex x, ex y){
	return x.l > y.l;
}

bool cmpc(ex x, ex y){
	return x.n < y.n;
}

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	
	n = read();
	m = read();
	
	for(i=1;i<=n;i++){
		a[i] = read();
	}
	
	for(i=1;i<=m;i++){
		e[i].l = read();
		e[i].r = read();
		e[i].n = i;
	}
	
	tree[0].init();
	tree[1].init();
	
	sort(e + 1, e + m + 1, cmpa);
	
	j = 1;
	
	for(i=1;i<=n;i++){
		while(j <= m and e[j].r < i){
			tree[0].update(e[j].l, e[j].r);
			j++;
		}
		f[i][0] = tree[0].query(1, i);
	}
	
	sort(e + 1, e + m + 1, cmpb);
	
	j = 1;
	
	for(i=n;i>=1;i--){
		while(j <= m and e[j].l > i){
			tree[1].update(e[j].l, e[j].r);
			j++;
		}
		f[i][1] = tree[1].query(i, n);
	}
	
	int ans = a[1] - min(f[1][0], f[1][1]);
	int x = 1;
	
	for(i=2;i<=n;i++){
		if(a[i] - min(f[i][0], f[i][1]) > ans){
			ans = a[i] - min(f[i][0], f[i][1]);
			x = i;
		}
	}
	
	vector <ex> vec;
	
	for(i=1;i<=m;i++){
		if(e[i].l > x or e[i].r < x){
			vec.push_back(e[i]);
		}
	}
	
	printf("%d\n", ans);
	printf("%d\n", (int)vec.size());
	
	sort(vec.begin(), vec.end(), cmpc);
	
	for(i=0;i<vec.size();i++){
		printf("%d ", vec[i].n);
	}
	printf("\n");
	
	return 0;
}