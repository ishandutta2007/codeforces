#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 5e5 + 5;

long long n, m, t, q;

long long a[maxn];

long long maxx = 0;

pair <long long, int> que[maxn];

int ans[maxn];
int c[maxn];

vector <int> veca;
vector <vector <int> > vecb;

struct stnode {
	int l, r;
	int lc, rc;
	int sum;
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
		tree[pos].sum = 0;
		
		if(l == r){
			return pos;
		}
		
		tree[pos].lc = init_tree(l, mid);
		tree[pos].rc = init_tree(mid + 1, r);
		
		tree[pos].sum = tree[tree[pos].lc].sum + tree[tree[pos].rc].sum;
		
		return pos;
	}
	
	int query_tree(int pos, int x){
		int mid = (tree[pos].l + tree[pos].r) / 2;
		
		if(tree[pos].l == tree[pos].r){
			return tree[pos].l;
		}else{
			if(tree[tree[pos].lc].sum >= x){
				return query_tree(tree[pos].lc, x);
			}else{
				return query_tree(tree[pos].rc, x - tree[tree[pos].lc].sum);
			}
		}
	}
	
	int update_tree(int pos,int x){
		int mid = (tree[pos].l + tree[pos].r) / 2;
		
		if(tree[pos].l == x and x == tree[pos].r){
			tree[pos].sum = 1;
		}else{
			if(x <= mid){
				update_tree(tree[pos].lc, x);
			}else{
				update_tree(tree[pos].rc, x);
			}
			tree[pos].sum = tree[tree[pos].lc].sum + tree[tree[pos].rc].sum;
		}
		return 0;
	}
	
	int query(int p){
		int ret = query_tree(root, p);
		return ret;
	}
	
	int update(int p){
		update_tree(root, p);
		return 0;
	}
	
	int init(){
		int i, j;
		tc = 0;
		root = init_tree(1, m);
		
		return 0;
	}
} tree;

long long read(){
	long long x;
	scanf("%lld", &x);
	return x;
}

bool cmp(int x, int y){
	if(a[x] != a[y])return a[x] < a[y];
	return x < y;
}

int main(){
	int i, j;
	long long x, y;
	long long sum = 0;
	
	n = read();
	m = read();
	q = read();
	
	tree.init();
	
	for(i=1;i<=n;i++){
		x = read();
		a[x]++;
	}
	
	for(i=1;i<=q;i++){
		que[i].first = read() - n;
		que[i].second = i;
	}
	
	sort(que + 1, que + q + 1);
	
	for(i=1;i<=m;i++){
		c[i] = i;
	}
	
	sort(c + 1, c + m + 1, cmp);
	
	vector <int> tmp;
	veca.push_back(a[c[1]]);
	vecb.push_back(tmp);
	vecb.back().push_back(c[1]);
	
	for(i=2;i<=m;i++){
		if(a[c[i]] != veca.back()){
			veca.push_back(a[c[i]]);
			vecb.push_back(tmp);
		}
		vecb.back().push_back(c[i]);
	}
	
	x = 1;
	y = vecb[0].size();
	long long l = veca[0];
	
	for(int z : vecb[0]){
		tree.update(z);
	}
	
	for(i=1;i<=q;i++){
		while(x < veca.size() and sum + y * (veca[x] - l) < que[i].first){
			sum += y * (veca[x] - l);
			y += vecb[x].size();
			l = veca[x];
			for(int z : vecb[x]){
				tree.update(z);
			}
			x++;
		}
		
		long long p = (que[i].first - sum - 1) % y + 1;
		ans[que[i].second] = tree.query(p);
	}
	
	for(i=1;i<=q;i++){
		printf("%d\n", ans[i]);
	}
	
	return 0;
}