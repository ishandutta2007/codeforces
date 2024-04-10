#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
const int LOG = 20;

int n, k;
int lst[MAXN], cnt[MAXN<<2], par[LOG][MAXN], gg;
int comp[MAXN];
vector<int> adj[MAXN];

int getPar(int de, int v){return par[de][v]==v?v:par[de][v]=getPar(de, par[de][v]);}

void plant(int v, int b, int e, int de = 0){
	if (e - b == 1){
		par[de][b] = b;
		cnt[v] = 1;
		return;
	}

	int mid = b + e >> 1;
	plant(v<<1, b, mid, de+1);
	plant(v<<1^1, mid, e, de+1);
	
	for (int i = b; i < e; i++) par[de][i] = par[de + 1][i];

	for (int i = mid-1; i >= max(b, mid-k); i--)
		for (int u:adj[i])
			if (mid <= u && u < e)
				par[de][getPar(de, u)] = getPar(de, i);

	gg++;
	for (int i = b; i < e; i++){
		int p = getPar(de, i);
		if (lst[p] != gg) cnt[v]++;
		lst[p] = gg;
	}
}

int weed[MAXN<<2];
void water(int v, int b, int e, int l, int r, int val){
	if (r <= b || e <= l) return;
	weed[v] = -1;
	if (l <= b && e <= r){
		weed[v] = val;
		return;
	}

	int mid = b + e >> 1;
	water(v<<1, b, mid, l, r, val);
	water(v<<1^1, mid, e, l, r, val);
}

int col(int v, int b, int e, int pos){
	if (~weed[v]) return weed[v];
	
	int mid = b + e >> 1;
	if (pos < mid)
		return col(v<<1, b, mid, pos);
	return col(v<<1^1, mid, e, pos);
}

int getComp(int v){
	if (lst[v] ^ gg){
		lst[v] = gg;
		comp[v] = par[col(1, 0, n, v)][v];
	}
	return comp[v] == v?v:comp[v]=getComp(comp[v]);
}

int smoke(int v, int b, int e, int l, int r, int de = 0){
	if (l <= b && e <= r){
		water(1, 0, n, b, e, de);
		return cnt[v];
	}
	if (r <= b || e <= l) return 0;

	int mid = b+e>>1;
	int ret = smoke(v<<1, b, mid, l, r, de+1) + smoke(v<<1^1, mid, e, l, r, de+1);
	b = max(b, l), e = min(e, r);
	for (int i = mid-1; i >= max(b, mid-k); i--)
		for (int u:adj[i])
			if (mid <= u && u < e){
				int p1 = getComp(i), p2 = getComp(u);
				if (p1 ^ p2){
					ret--;
					comp[p2] = p1;
				}
			}
	return ret;
}

int main(){
	scanf("%d %d", &n, &k);
	int m; scanf("%d", &m);
	while (m--){
		int u, v; scanf("%d %d", &u, &v), u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	plant(1, 0, n);

	int q; scanf("%d", &q);
	while (q--){
		gg++;
		int l, r; scanf("%d %d", &l, &r), l--;
		printf("%d\n", smoke(1, 0, n, l, r));
	}
	return 0;
}