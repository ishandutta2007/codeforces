#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int n;

long long m;

const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 5;;

struct stnode {
	int l, r;
	int lc, rc;
	int x;
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
			tree[pos].x = 0;
			return pos;
		}
		
		tree[pos].lc = init_tree(l, mid);
		tree[pos].rc = init_tree(mid + 1, r);
		
		tree[pos].x = tree[tree[pos].lc].x | tree[tree[pos].rc].x;
		
		return pos;
	}
	
	int query_tree(int pos, int l, int r){
		int mid = (tree[pos].l + tree[pos].r) / 2;
		
		if(tree[pos].l == l and r == tree[pos].r){
			return tree[pos].x;
		}else{
			if(r <= mid){
				return query_tree(tree[pos].lc, l, r);
			}else if(l <= mid){
				return query_tree(tree[pos].lc, l, mid) | query_tree(tree[pos].rc, mid + 1, r);
			}else{
				return query_tree(tree[pos].rc, l, r);
			}
		}
	}
	
	int query_tree(int pos, int l){
		int mid = (tree[pos].l + tree[pos].r) / 2;
		
		if(tree[pos].l == tree[pos].r){
			if(tree[pos].x)return tree[pos].l;
			else return inf;
		}else{
			int ret = inf;
			
			if(l <= mid and tree[tree[pos].lc].x){
				ret = min(ret, query_tree(tree[pos].lc, l));
			}
			if(ret == inf and tree[tree[pos].rc].x){
				ret = min(ret, query_tree(tree[pos].rc, l));
			}
			return ret;
		}
	}
	
	int update_tree(int pos, int p, int x){
		int mid = (tree[pos].l + tree[pos].r) / 2;
		
		if(tree[pos].l == tree[pos].r){
			tree[pos].x = x;
			return 0;
		}
		
		if(p <= mid){
			update_tree(tree[pos].lc, p, x);
		}else{
			update_tree(tree[pos].rc, p, x);
		}
		tree[pos].x = tree[tree[pos].lc].x | tree[tree[pos].rc].x;
		return 0;
	}
	
	int query(int l, int r){
		int ret = query_tree(root, l, r);
		return ret;
	}
	
	int update(int p, int x){
		update_tree(root, p, x);
		return 0;
	}
	
	int query_min(int l){
		return query_tree(root, l);
	}
	
	int init(int x){
		int i, j;
		tc = 0;
		root = 1;
		
		init_tree(1, x);
		
		return 0;
	}
} A, B;

long long ans[maxn];
long long t[maxn];
int c[maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

bool cmp(int x, int y){
	if(t[x] != t[y])return t[x] < t[y];
	return x < y;
}

int main(){
	int i, j;
	long long p = 0;
	
	scanf("%d%lld", &n, &m);
	
	for(i=1;i<=n;i++){
		t[i] = read();
		c[i] = i;
	}
	
	A.init(n);
	B.init(n);
	
	sort(c + 1, c + n + 1, cmp);
	queue <int> q;
	q.push(c[1]);
	j = 2;
	p = t[c[1]];
	A.update(c[1], 1);
	
	for(i=1;i<=n;i++){
		if(!q.size())p = max(p, t[c[i + 1]]);
		p += m;
		
		while(j <= n and t[c[j]] <= p){
			if(A.query(1, c[j])){
				B.update(c[j], 1);
			}else{
				A.update(c[j], 1);
				q.push(c[j]);
			}
			j++;
		}
		
		int x = q.front();
		q.pop();
		
		ans[x] = p;
		
		A.update(x, 0);
		
		if(!A.query(1, x) and B.query(x, n)){
			int y = B.query_min(x);
			B.update(y, 0);
			q.push(y);
			A.update(y, 1);
		}
	}
	
	for(i=1;i<=n;i++){
		printf("%lld ", ans[i]);
	}
	printf("\n");
	
	return 0;
}