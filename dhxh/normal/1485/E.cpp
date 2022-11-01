#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;

int n, m, t;

long long a[maxn];
int fa[maxn];
vector <int> e[maxn];
int dep[maxn];
vector <int> vec[maxn];
long long f[maxn];

struct stnode {
	int l, r;
	int lc, rc;
	long long mx;
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
		tree[pos].mx = 0xc0c0c0c0;
		
		if(l == r){
			return pos;
		}
		
		tree[pos].lc = init_tree(l, mid);
		tree[pos].rc = init_tree(mid + 1, r);
		
		return pos;
	}
	
	long long query_tree(int pos, int l, int r){
		int mid = (tree[pos].l + tree[pos].r) / 2;
		
		if(tree[pos].l == l and r == tree[pos].r){
			return tree[pos].mx;
		}else{
			if(r <= mid){
				return query_tree(tree[pos].lc, l, r);
			}else if(l <= mid){
				return max(query_tree(tree[pos].lc, l, mid), query_tree(tree[pos].rc, mid + 1, r));
			}else{
				return query_tree(tree[pos].rc, l, r);
			}
		}
	}
	
	void update_tree(int pos, int p, long long x){
		int mid = (tree[pos].l + tree[pos].r) / 2;
		
		if(tree[pos].l == tree[pos].r){
			tree[pos].mx = x;
		}else{
			if(p <= mid){
				update_tree(tree[pos].lc, p, x);
			}else{
				update_tree(tree[pos].rc, p, x);
			}
			tree[pos].mx = max(tree[tree[pos].lc].mx, tree[tree[pos].rc].mx);
		}
	}
	
	long long query(int l, int r){
		if(r < l) return 0x3f3f3f3f;
		return query_tree(root, l, r);
	}
	
	void update(int p, long long x){
		update_tree(root, p, x);
	}
	
	void init(int x){
		int i, j;
		tc = 0;
		root = init_tree(1, x);
	}
} tree[2];

void dfs(int x){
	vec[dep[x]].push_back(x);
	m = max(m, dep[x]);
	for(auto y : e[x]){
		dep[y] = dep[x] + 1;
		dfs(y);
	}
}

bool cmp(int x, int y){
	return a[x] < a[y];
}

int main(){
	int i, j;
	
	scanf("%d", &t);
	
	while(t--){
		scanf("%d", &n);
		m = 0;
		for(i=0;i<=n;i++) e[i].clear(), dep[i] = 0, vec[i].clear(), f[i] = 0;
		
		for(i=2;i<=n;i++){
			scanf("%d", &fa[i]);
			e[fa[i]].push_back(i);
		}
		
		for(i=2;i<=n;i++) scanf("%lld", &a[i]);
		
		dfs(1);
		
		for(i=1;i<=m;i++){
			sort(vec[i].begin(), vec[i].end(), cmp);
		}
		
		f[1] = 0;
		tree[0].init(n);
		tree[1].init(n);
		
		int sum = 1;
		long long ans = 0;
		for(i=1;i<=m;i++){
			int sz = vec[i].size();
			for(j=0;j<sz;j++){
				int x = vec[i][j];
				tree[0].update(sum + j, f[fa[x]] + a[x]);
				tree[1].update(sum + j, f[fa[x]] - a[x]);
			}
			
			for(j=0;j<sz;j++){
				int x = vec[i][j];
				f[x] = max(tree[1].query(sum, sum + j) + a[x], tree[0].query(sum + j, sum + sz - 1) - a[x]);
				f[x] = max(f[x], f[fa[x]] + max(a[x] - a[vec[i].front()], a[vec[i].back()] - a[x]));
				ans = max(ans, f[x]);
			}
			
			sum += sz;
		}
		
		printf("%lld\n", ans);
	}
	
	return 0;
}