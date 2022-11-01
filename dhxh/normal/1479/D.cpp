#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5 + 5;

struct ex {
	int l, r, f, x, y, n;
};
 
vector <ex> que;
 
int ans[maxn];
int a[maxn];

int n, m, q;

vector <int> e[maxn];
int fa[maxn][25];
int dep[maxn];
int f[maxn];
int h[maxn];
bool vis[maxn];

vector <int> v;
int sz;

struct st {
	int tree[maxn];
	int sum[maxn];
	int sz;
	
	void insert(int x){
		tree[x]++;
		sum[x / sz]++;
	}
	
	void erase(int x){
		tree[x]--;
		sum[x / sz]--;
	}
	
	int query(int l, int r){
		if(l / sz == r / sz){
			for(int i=l;i<=r;i++){
				if(tree[i]) return i;
			}
			return -1;
		}
		
		int t = (l / sz + 1) * sz - 1;
		for(int i=l;i<=t;i++){
			if(tree[i]) return i;
		}
		
		t = r / sz;
		for(int j=l/sz+1;j<t;j++){
			if(sum[j]){
				for(int i=j*sz;;i++){
					if(tree[i]) return i;
				}
			}
		}
		
		for(int i=r/sz*sz;i<=r;i++){
			if(tree[i]) return i;
		}
		
		return -1;
	}
	
	void init(){
		sz = sqrt(n);
	}
} s;

bool cmp(ex x, ex y){
	if(x.l / sz != y.l / sz){
		return x.l < y.l;
	}else{
		if((x.l / sz) & 1){
			return x.r > y.r;
		}else{
			return x.r < y.r;
		}
	}
}

int dfs(int x){
	f[x] = v.size();
	v.push_back(x);
	
	for(int i=0;fa[x][i];i++){
		fa[x][i + 1] = fa[fa[x][i]][i];
	}
	
	for(auto y : e[x]){
		if(y == fa[x][0]) continue;
		fa[y][0] = x;
		dep[y] = dep[x] + 1;
		dfs(y);
	}
	
	h[x] = (int)v.size();
	v.push_back(x);
	
	return 0;
}

int lca(int x, int y){
	if(dep[x] < dep[y]) swap(x, y);
	
	if(dep[x] > dep[y]){
		for(int i=20;i>=0;i--){
			if(dep[x] - dep[y] >= (1 << i)){
				x = fa[x][i];
			}
		}
	}
	
	if(x == y) return x;
	
	for(int i=20;i>=0;i--){
		if(fa[x][i] != fa[y][i]){
			x = fa[x][i];
			y = fa[y][i];
		}
	}
	
	return fa[x][0];
}

int change(int p){
	p = a[p];
	vis[p] = !vis[p];
	if(vis[p]){
		s.insert(p);
	}else{
		s.erase(p);
	}
	
	return 0;
}

int read(){
	int x = 0;
	char ch = getchar();
	
	while('0' > ch or ch > '9') ch = getchar();
	
	while('0' <= ch and ch <= '9'){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	
	return x;
}

int main(){
	int i, j;
	int o;
	int l, r, x, y;
	memset(ans, -1, sizeof(ans));
	
	//scanf("%d%d", &n, &q);
	n = read(); q = read();
	
	sz = sqrt(n) * 3;
	
	for(i=1;i<=n;i++){
		//scanf("%d", &a[i]);
		a[i] = read();
	}
	
	for(i=1;i<n;i++){
		//scanf("%d%d", &x, &y);
		x = read(); y = read();
		e[x].push_back(y);
		e[y].push_back(x);
	}
	
	dep[1] = 1;
	dfs(1);
	
	for(j=1;j<=q;j++){
		//scanf("%d%d%d%d", &x, &y, &l, &r);
		x = read(); y = read(); l = read(); r = read();
		if(x == y){
			if(l <= a[x] and a[x] <= r){
				ans[j] = a[x];
			}
			continue;
		}
		int L = lca(x, y);
		if(L == y) que.push_back((ex){f[L], f[x], 0, l, r, j});
		else if(L == x) que.push_back((ex){f[L], f[y], 0, l, r, j});
		else if(f[x] < f[y]) que.push_back((ex){h[x], f[y], L, l, r, j});
		else que.push_back((ex){h[y], f[x], L, l, r, j});
	}
	
	sort(que.begin(), que.end(), cmp);
	
	s.init();
	l = 0, r = 0;
	if(n > 1) change(v[0]);
	
	for(ex tmp : que){
		while(r < tmp.r) change(v[++r]);
		while(l > tmp.l) change(v[--l]);
		while(r > tmp.r) change(v[r--]);
		while(l < tmp.l) change(v[l++]);
		
		if(tmp.f) change(tmp.f);
		ans[tmp.n] = s.query(tmp.x, tmp.y);
		if(tmp.f) change(tmp.f);
	}
	
	for(i=1;i<=q;i++){
		printf("%d\n", ans[i]);
	}
	
	return 0;
}