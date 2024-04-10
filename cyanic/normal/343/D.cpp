#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define lc (o << 1)
#define rc (o << 1 | 1)
#define mid ((l+r) >> 1)
using namespace std;

const int maxn = 500009;
int T[maxn<<2], lazy[maxn<<2];
int in[maxn], out[maxn], fa[maxn];
vector<int> e[maxn];
int n, Q, a, b, clk;

void dfs(int u){
	in[u] = ++clk;
	for (int i=0; i<e[u].size(); i++)
		if (e[u][i] != fa[u]){
			fa[e[u][i]] = u;
			dfs(e[u][i]);
		}
	out[u] = clk;
}

void pushdown(int o){
	if (lazy[o] == -1) return;
	T[lc] = lazy[lc] = lazy[o];
	T[rc] = lazy[rc] = lazy[o];
	lazy[o] = -1;
}

void update(int o, int l, int r, int x, int y, int z){
	if (l == x && y == r){
		T[o] = lazy[o] = z; return;
	}
	pushdown(o);
	if (x <= mid) update(lc, l, mid, x, min(y, mid), z);
	if (mid+1 <= y) update(rc, mid+1, r, max(x, mid+1) , y, z);
	T[o] = T[lc] | T[rc];
}

int query(int o, int l, int r, int x, int y){
	if (l == x && y == r) return T[o];
	pushdown(o);
	if (y <= mid) return query(lc, l, mid, x, y);
	if (mid+1 <= x) return query(rc, mid+1, r, x, y);
	return query(lc, l, mid, x, mid) | query(rc, mid+1, r, mid+1, y);
}

int main(){
	scanf("%d", &n);
	for (int i=1; i<=n-1; i++){
		scanf("%d%d", &a, &b);
		e[a].push_back(b);
		e[b].push_back(a);
	}
	fa[1] = 0; dfs(1);
	
	memset(T, true, sizeof T);
	memset(lazy, -1, sizeof lazy);
	scanf("%d", &Q);
	while (Q--){
		scanf("%d%d", &a, &b);
		if (a == 1){
			if (query(1, 1, n, in[b], out[b])){
				if (fa[b]) update(1, 1, n, in[fa[b]], in[fa[b]], 1);
				update(1, 1, n, in[b], out[b], 0);
			}
		}
		else if (a == 2){
			update(1, 1, n, in[b], in[b], 1);
		}
		else{
			putchar('0' + 1-query(1, 1, n, in[b], out[b]));
			puts("");
		}
	}
	return 0;
}