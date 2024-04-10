#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 2e5 + 5;

int n, m, t, q;

int inf = 0x3f3f3f3f;

char a[maxn];

int getn(char x){
	if(x == 'R'){
		return 0;
	}else if(x == 'P'){
		return 1;
	}else{
		return 2;
	}
}

struct ex {
	int maxx[5];
	int minx[5];
	int cnt[5];
	
	int init(char x, int p){
		memset(cnt, 0, sizeof(cnt));
		memset(minx, 0x3f, sizeof(minx));
		memset(maxx, 0, sizeof(maxx));
		cnt[getn(x)] = 1;
		minx[getn(x)] = maxx[getn(x)] = p;
		return 0;
	}
};

ex merge(ex x, ex y){
	ex ret;
	int i;
	
	for(i=0;i<3;i++){
		ret.maxx[i] = max(x.maxx[i], y.maxx[i]);
		ret.minx[i] = min(x.minx[i], y.minx[i]);
		ret.cnt[i] = x.cnt[i] + y.cnt[i];
	}
	
	return ret;
}

struct node {
	int l, r;
	int lc, rc;
	ex x;
};

node tree[maxn * 4];

int root;
int tc = 0;

ex query(int pos, int l, int r){
	int mid = (tree[pos].l + tree[pos].r) / 2;
	
	if(tree[pos].l == l and r == tree[pos].r){
		return tree[pos].x;
	}else{
		if(r <= mid){
			return query(tree[pos].lc, l, r);
		}else if(l <= mid){
			return merge(query(tree[pos].lc, l, mid), query(tree[pos].rc, mid + 1, r));
		}else{
			return query(tree[pos].rc, l, r);
		}
	}
}

int queryans(){
	int i, j;
	int ans = 0;
	int l, r;
	ex ret = tree[root].x;
	
	for(i=0;i<3;i++){
		if(!ret.cnt[(i + 1) % 3]){
			ans += ret.cnt[i];
		}else if(ret.cnt[i]){
			if(!ret.cnt[(i + 2) % 3]){
				continue;
			}
			
			if(ret.maxx[(i + 1) % 3] > ret.maxx[(i + 2) % 3]){
				r = ret.maxx[(i + 2) % 3];
			}else{
				r = n;
			}
			
			if(ret.minx[(i + 1) % 3] < ret.minx[(i + 2) % 3]){
				l = ret.minx[(i + 2) % 3];
			}else{
				l = 1;
			}
			
			if(ret.maxx[(i + 1) % 3] < n and ret.minx[(i + 2) % 3] < ret.maxx[(i + 1) % 3] and r != n){
				ans += query(root, ret.maxx[(i + 1) % 3] + 1, n).cnt[i];
			}
			
			if(ret.minx[(i + 1) % 3] > 1 and ret.maxx[(i + 2) % 3] > ret.minx[(i + 1) % 3] and l != 1){
				ans += query(root, 1, ret.minx[(i + 1) % 3] - 1).cnt[i];
			}
			
			ans += query(root, l, r).cnt[i];
		}
	}
	
	return ans;
}

int update(int pos, int p, char x){
	int mid = (tree[pos].l + tree[pos].r) / 2;
	
	if(tree[pos].l == tree[pos].r){
		tree[pos].x.init(x, p);
	}else{
		if(p <= mid){
			update(tree[pos].lc, p, x);
		}else{
			update(tree[pos].rc, p, x);
		}
		tree[pos].x = merge(tree[tree[pos].lc].x, tree[tree[pos].rc].x);
		
	}
	
	return 0;
}

int init_tree(int l, int r){
	int mid = (l + r) / 2;
	int pos = ++tc;
	
	tree[pos].l = l;
	tree[pos].r = r;
	
	if(l == r){
		tree[pos].x.init(a[l], l);
	}else{
		tree[pos].lc = init_tree(l, mid);
		tree[pos].rc = init_tree(mid + 1, r);
		tree[pos].x = merge(tree[tree[pos].lc].x, tree[tree[pos].rc].x);
	}
	
	return pos;
}

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	int p;
	char x;
	n = read();
	q = read();
	
	scanf("%s", &a[1]);
	
	root = init_tree(1, n);
	
	printf("%d\n", queryans());
	
	while(q--){
		p = read();
		scanf(" %c", &x);
		
		update(root, p, x);
		printf("%d\n", queryans());
	}
	
	return 0;
}