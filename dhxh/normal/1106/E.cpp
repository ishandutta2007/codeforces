#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;

int n, m, k;

struct point {
	int s, t, d;
	long long w;
	int num;
};

point a[maxn];
point b[maxn];

struct node {
	int l, r;
	int lc, rc;
	bool vis;
	point maxx;
};

struct st {
	int root;
	int tc;
	node tree[maxn * 4];
	
	node merge(int pos, int x, int y){
		node ret = tree[pos];
		if(!tree[x].vis and !tree[y].vis){
			ret.vis = false;
		}else if(!tree[y].vis){
			ret.vis = true;
			ret.maxx = tree[x].maxx;
		}else if(!tree[x].vis){
			ret.vis = true;
			ret.maxx = tree[y].maxx;
		}else{
			ret.vis = true;
			if(tree[x].maxx.w > tree[y].maxx.w){
				ret.maxx = tree[x].maxx;
			}else if(tree[x].maxx.w < tree[y].maxx.w){
				ret.maxx = tree[y].maxx;
			}else{
				if(tree[x].maxx.d > tree[y].maxx.d){
					ret.maxx = tree[x].maxx;
				}else{
					ret.maxx = tree[y].maxx;
				}
			}
		}
		
		return ret;
	}
	
	int update_tree(int pos, int x){
		int mid = (tree[pos].l + tree[pos].r) / 2;
		
		if(tree[pos].l == tree[pos].r){
			tree[pos].vis = !tree[pos].vis;
			return 0;
		}
		
		if(x <= mid){
			update_tree(tree[pos].lc, x);
		}else{
			update_tree(tree[pos].rc, x);
		}
		
		tree[pos] = merge(pos, tree[pos].lc, tree[pos].rc);
		
		return 0;
	}
	
	int init_tree(int l, int r){
		int mid = (l + r) / 2;
		int pos = ++tc;
		
		tree[pos].l = l;
		tree[pos].r = r;
		tree[pos].vis = false;
		
		if(l == r){
			tree[pos].maxx = a[l];
		}else{
			tree[pos].lc = init_tree(l, mid);
			tree[pos].rc = init_tree(mid + 1, r);
		}
		
		
		return pos;
	}
	
	node query(){
		return tree[root];
	}
	
	int update(int x){
		update_tree(root, x);
	}
	
	int init(){
		tc = 0;
		
		root = init_tree(1, k);
		
		return 0;
	}
};

st tree;

long long f[maxn][205];

bool cmpa(point x, point y){
	return x.s < y.s;
}

bool cmpb(point x, point y){
	return x.t < y.t;
}

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j, l;
	int x, y;
	
	n = read();
	m = read();
	k = read();
	
	for(i=1;i<=k;i++){
		a[i].s = read();
		a[i].t = read();
		a[i].d = read();
		a[i].w = read();
		a[i].num = i;
		b[i] = a[i];
	}
	
	tree.init();
	
	sort(a + 1, a + k + 1, cmpa);
	sort(b + 1, b + k + 1, cmpb);
	
	memset(f, 0x3f, sizeof(f));
	
	f[1][0] = 0;
	
	x = 1, y = 1;
	
	for(i=1;i<=n;i++){
		while(x <= k and a[x].s <= i){
			tree.update(a[x].num);
			x++;
		}
		
		while(y <= k and b[y].t < i){
			tree.update(b[y].num);
			y++;
		}
		
		node tmpa = tree.query();
		point tmp = tmpa.maxx;
		
		for(j=0;j<=m;j++){
			f[i + 1][j + 1] = min(f[i + 1][j + 1], f[i][j]);
		}
		
		if(tmpa.vis){
			for(j=0;j<=m;j++){
				f[tmp.d + 1][j] = min(f[tmp.d + 1][j], f[i][j] + tmp.w);
			}
		}else{
			for(j=0;j<=m;j++){
				f[i + 1][j] = min(f[i + 1][j], f[i][j]);
			}
		}
	}
	
	long long ans = 0x3f3f3f3f3f3f3f3f;
	
	for(j=0;j<=m;j++){
		ans = min(ans, f[n + 1][j]);
	}
	
	printf("%lld\n", ans);
	
	return 0;
}