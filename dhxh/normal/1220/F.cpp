#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

const int maxn = 4e5 + 5;

int n, m;

int a[maxn];
int p[maxn];
int L[maxn];
int R[maxn];

struct stnode {
	int l, r;
	int lc, rc;
	int lazy;
	int max, min;
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
			tree[pos].max = tree[pos].min = 0;
			return pos;
		}
		
		tree[pos].lc = init_tree(l, mid);
		tree[pos].rc = init_tree(mid + 1, r);
		
		tree[pos].max = max(tree[tree[pos].lc].max, tree[tree[pos].rc].max);
		tree[pos].min = min(tree[tree[pos].lc].min, tree[tree[pos].rc].min);
		
		return pos;
	}
	
	int pushdown(int pos){
		tree[tree[pos].lc].max += tree[pos].lazy;
		tree[tree[pos].rc].max += tree[pos].lazy;
		tree[tree[pos].lc].min += tree[pos].lazy;
		tree[tree[pos].rc].min += tree[pos].lazy;
		
		tree[tree[pos].lc].lazy += tree[pos].lazy;
		tree[tree[pos].rc].lazy += tree[pos].lazy;
		tree[pos].lazy = 0;
		
		return 0;
	}
	
	int update_tree(int pos, int l, int r, int x){
		int mid = (tree[pos].l + tree[pos].r) / 2;
		
		if(tree[pos].l == l and r == tree[pos].r){
			tree[pos].lazy += x;
			tree[pos].max += x;
			tree[pos].min += x;
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
			tree[pos].max = max(tree[tree[pos].lc].max, tree[tree[pos].rc].max);
			tree[pos].min = min(tree[tree[pos].lc].min, tree[tree[pos].rc].min);
		}
		return 0;
	}
	
	int query_tree(int pos, int l, int r){
		int mid = (tree[pos].l + tree[pos].r) / 2;
		
		if(tree[pos].l == l and r == tree[pos].r){
			return tree[pos].max;
		}else{
			if(tree[pos].lazy){
				pushdown(pos);
			}
			if(r <= mid){
				return query_tree(tree[pos].lc, l, r);
			}else if(l <= mid){
				return max(query_tree(tree[pos].lc, l, mid), query_tree(tree[pos].rc, mid + 1, r));
			}else{
				return query_tree(tree[pos].rc, l, r);
			}
		}
		return 0;
	}
	
	int query_max(){
		return tree[root].max;
	}
	
	int query(int l, int r){
		if(r < l)return 0;
		return query_tree(root, l, r);
	}
	
	int update(int l, int r, int x){
		if(r < l)return 0;
		update_tree(root, l, r, x);
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
	int ansa, ansb = 0;
	
	n = read();
	
	for(i=1;i<=n;i++){
		a[i] = read();
		a[i + n] = a[i];
		p[a[i]] = i;
	}
	
	stack <int> q;
	
	for(i=1;i<=n;i++){
		while(!q.empty() and a[q.top()] >= a[i])q.pop();
		q.push(i);
	}
	
	for(i=n+1;i<=2*n;i++){
		while(!q.empty() and a[q.top()] >= a[i])q.pop();
		if(a[i] != 1){
			L[i - n] = q.top() - n;
		}else{
			L[i - n] = 0;
		}
		q.push(i);
	}
	
	for(i=2*n;i>n;i--){
		while(!q.empty() and a[q.top()] >= a[i])q.pop();
		q.push(i);
	}
	
	for(i=n;i>0;i--){
		while(!q.empty() and a[q.top()] >= a[i])q.pop();
		if(a[i] != 1){
			R[i] = q.top();
		}else{
			R[i] = n;
		}
		q.push(i);
	}
	
	tree.init(n);
	
	tree.update(1, n, 1);
	
	for(i=1;i<=n;i++){
		if(a[i] == 1)continue;
		tree.update(max(1, L[i] + 1), i, 1);
		tree.update(i + 1, min(R[i] - 1, n), 1);
	}
	
	ansa = tree.query_max();
	
	for(i=1;i<n;i++){
		if(a[i] == 1)continue;
		if(R[i] - 1 > n){
			tree.update(1, R[i] - n - 1, -1);
		}
		tree.update(i + 1, min(R[i] - 1, n), -1);
		if(L[i] + 1 <= 0){
			tree.update(L[i] + 1 + n, n, 1);
		}
		tree.update(max(1, L[i] + 1), i - 1, 1);
		tree.update(i, i, tree.query((L[i] <= 0 ? L[i] + n : L[i]), (L[i] <= 0 ? L[i] + n : L[i])) + 1 - tree.query(i, i));
		if(tree.query_max() < ansa){
			ansa = tree.query_max();
			ansb = i;
		}
	}
	
	printf("%d %d\n", ansa, ansb);
	
	return 0;
}