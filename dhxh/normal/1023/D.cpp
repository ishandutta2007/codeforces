#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 2e5 + 5;

int n, m, q;

int a[maxn];

int ans[maxn];

int b[maxn][2];

bool v[maxn];

struct stnode {
	int l, r;
	int lc, rc;
	int minn;
	int tmp;
};


struct sttree {
	stnode tree[maxn * 4];
	int root = 1;
	int tc = 0;
	int ac = 0;
	
	int init_tree(int l, int r){
		tc++;
		int mid = (l + r) / 2;
		int tnow = tc;
		if(l == r){
			ac++;
			tree[tnow].l = l;
			tree[tnow].r = r;
			tree[tnow].minn = a[ac];
			return tnow;
		}
		
		tree[tnow].lc = init_tree(l, mid);
		tree[tnow].rc = init_tree(mid + 1, r);
		tree[tnow].l = l;
		tree[tnow].r = r;
		tree[tnow].minn = min(tree[tree[tnow].lc].minn, tree[tree[tnow].rc].minn);
		
		return tnow;
	}
	
	int query(int tnow, int l, int r){
		int mid = (tree[tnow].l + tree[tnow].r) / 2;
		if(l == tree[tnow].l and tree[tnow].r == r){
			return tree[tnow].minn;
		}
		
		if(r <= mid){
			return query(tree[tnow].lc, l, r);
		}else if(l > mid){
			return query(tree[tnow].rc, l, r);
		}else{
			return min(query(tree[tnow].lc, l, mid), query(tree[tnow].rc, mid + 1, r));
		}
	}
};

struct sttreeb {
	stnode tree[maxn * 4];
	int root = 1;
	int tc = 0;
	int ac = 0;
	
	int init_tree(int l, int r){
		tc++;
		int mid = (l + r) / 2;
		int tnow = tc;
		
		tree[tnow].tmp = -1;
		
		if(l == r){
			ac++;
			tree[tnow].l = l;
			tree[tnow].r = r;
			tree[tnow].tmp = 1;
			return tnow;
		}
		
		tree[tnow].lc = init_tree(l, mid);
		tree[tnow].rc = init_tree(mid + 1, r);
		tree[tnow].l = l;
		tree[tnow].r = r;
		
		return tnow;
	}
	
	int push_down(int tnow){
		if(tree[tnow].tmp == -1 or tree[tnow].l == tree[tnow].r){
			return 0;
		}
		
		tree[tree[tnow].lc].tmp = tree[tnow].tmp;
		tree[tree[tnow].rc].tmp = tree[tnow].tmp;
		tree[tnow].tmp = -1;
		
		return 0;
	}
	
	int update(int tnow, int l, int r, int x){
		int mid = (tree[tnow].l + tree[tnow].r) / 2;
		if(l == tree[tnow].l and tree[tnow].r == r){
			tree[tnow].tmp = x;
			return 0;
		}
		
		push_down(tnow);
		
		if(r <= mid){
			update(tree[tnow].lc, l, r, x);
		}else if(l > mid){
			update(tree[tnow].rc, l, r, x);
		}else{
			update(tree[tnow].lc, l, mid, x);
			update(tree[tnow].rc, mid + 1, r, x);
		}
		return 0;
	}
	
	int echo_tree(int tnow){
		push_down(tnow);
		if(tree[tnow].l == tree[tnow].r){
			printf("%d ", tree[tnow].tmp);
			return 0;
		}
		
		
		echo_tree(tree[tnow].lc);
		echo_tree(tree[tnow].rc);
		
		return 0;
	}
};

sttree treea;

sttreeb treeb;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	int t = 0;
	
	n = read();
	q = read();
	
	for(i=1;i<=max(n, q);i++){
		b[i][0] = maxn;
		b[i][1] = 0;
	}
	
	for(i=1;i<=n;i++){
		a[i] = read();
		v[a[i]] = true;
		//if(a[i] != i){
			b[a[i]][0] = min(b[a[i]][0], i);
			b[a[i]][1] = max(b[a[i]][1], i);
			if(a[i] > q){
				printf("NO\n");
				return 0;
			}
		//}
		if(a[i] == 0){
			t = i;
			a[i] = maxn;
		}
	}
	
	if((!v[q]) and !t){
		printf("NO\n");
		return 0;
	}
	
	treea.init_tree(1, n);
	treeb.init_tree(1, n);
	
	for(i=1;i<=q;i++){
		if(b[i][0] == maxn or !b[i][0]){
			if(t){
				treeb.update(1, t, t, i);
			}
			continue;
		}
		
		if(treea.query(1, b[i][0], b[i][1]) < i){
			printf("NO\n");
			return 0;
		}
		
		
		treeb.update(1, b[i][0], b[i][1], i);
	}
	
	
	printf("YES\n");
	
	treeb.echo_tree(1);
	printf("\n");
	
	return 0;
}