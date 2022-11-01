#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;

int n, m, t;

int pre[maxn];

struct stnode {
	int l, r;
	int lc, rc;
	int mx, mn;
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
		
		if(l == r){
			tree[pos].mx = tree[pos].mn = pre[l];
			return pos;
		}
		
		tree[pos].lc = init_tree(l, mid);
		tree[pos].rc = init_tree(mid + 1, r);
		
		tree[pos].mx = max(tree[tree[pos].lc].mx, tree[tree[pos].rc].mx);
		tree[pos].mn = min(tree[tree[pos].lc].mn, tree[tree[pos].rc].mn);
		
		return pos;
	}
	
	pair <int, int> query_tree(int pos, int l, int r){
		int mid = (tree[pos].l + tree[pos].r) / 2;
		
		if(tree[pos].l == l and r == tree[pos].r){
			return {tree[pos].mx, tree[pos].mn};
		}else{
			if(r <= mid){
				return query_tree(tree[pos].lc, l, r);
			}else if(l <= mid){
				auto L = query_tree(tree[pos].lc, l, mid);
				auto R = query_tree(tree[pos].rc, mid + 1, r);
				return {max(L.first, R.first), min(L.second, R.second)};
			}else{
				return query_tree(tree[pos].rc, l, r);
			}
		}
	}
	
	pair <int, int> query(int l, int r){
		if(l > r) return {0, 0};
		return query_tree(root, l, r);
	}
	
	void init(){
		tc = 0;
		root = init_tree(0, n);
	}
} tree;

int main(){
	int i, j;
	char ch;
	
	scanf("%d", &t);
	
	while(t--){
		scanf("%d%d", &n, &m);
		
		for(i=1;i<=n;i++){
			scanf(" %c", &ch);
			if(ch == '-'){
				pre[i] = pre[i - 1] - 1;
			}else{
				pre[i] = pre[i - 1] + 1;
			}
		}
		
		tree.init();
		
		for(i=1;i<=m;i++){
			int l, r;
			scanf("%d%d", &l, &r);
			int mx = 0, mn = 0;
			auto ret = tree.query(0, l - 1);
			mx = max(mx, ret.first);
			mn = min(mn, ret.second);
			
			if(r < n){
				auto ret = tree.query(r + 1, n);
				int x = pre[l - 1] - pre[r];
				ret.first += x;
				ret.second += x;
				mx = max(mx, ret.first);
				mn = min(mn, ret.second);
			}
			
			printf("%d\n", mx - mn + 1);
		}
	}
	
	return 0;
}