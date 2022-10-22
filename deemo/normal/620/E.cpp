#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const int MAXN = 4e5 + 1000;

int n, q, col[MAXN];
int s_t[MAXN], f_t[MAXN], pos[MAXN], tm;
ll weed[4 * MAXN];
int nut[4 * MAXN];
vector<int>	adj[MAXN];

void dfs(int v, int p = -1){
	pos[tm] = v;
	s_t[v] = tm++;
	for (int u:adj[v])
		if (u != p)	dfs(u, v);
	f_t[v] = tm;
}

void plant(int v = 1, int b = 0, int e = n){
	if (e - b == 1){
		weed[v] = 1LL << col[pos[b]];
		return;
	}

	int mid = (b + e)/ 2;
	plant(v<<1, b, mid);
	plant(v<<1^1, mid, e);
	weed[v] = weed[v<<1] | weed[v<<1^1];
}

void absorb(int v){
	if (nut[v] == 0)	return;
	nut[v<<1] = nut[v<<1^1] = nut[v];
	weed[v<<1] = weed[v<<1^1] = 1LL<<nut[v];
	nut[v] = 0;
}

void water(int v, int b, int e, int l, int r, int c){
	if (l <= b && e <= r){
		weed[v] = 1LL<<c;
		nut[v] = c;
		return;
	}
	if (r <= b || e <= l)	return;

	int mid = (b + e)/ 2;
	absorb(v);
	water(v<<1, b, mid, l, r, c);
	water(v<<1^1, mid, e, l, r, c);
	weed[v] = weed[v<<1] | weed[v<<1^1];
}

ll smoke(int v, int b, int e, int l, int r){
	if (l <= b && e <= r)	return	weed[v];
	if (r <= b || e <= l)	return	0;

	int mid = (b + e)/ 2;
	absorb(v);
	return	smoke(v<<1, b, mid, l, r) | smoke(v<<1^1, mid, e, l, r);
}

int main(){
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++)	scanf("%d", &col[i]);
	for (int i = 0; i < n - 1; i++){
		int a, b;	scanf("%d %d", &a, &b);	a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(0);
	plant();
	while (q--){
		int type;	scanf("%d", &type);
		if (type == 1){
			int v, c;	scanf("%d %d", &v, &c);	v--;
			water(1, 0, n, s_t[v], f_t[v], c);
		}
		else{
			int v;	scanf("%d", &v);	v--;
			printf("%d\n", __builtin_popcountll(smoke(1, 0, n, s_t[v], f_t[v])));
		}
	}
	return	0;
}