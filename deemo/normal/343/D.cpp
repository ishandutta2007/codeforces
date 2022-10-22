//And if you fall, I'll get you there
//I'll be your savior from all the wars that are fought inside your world
//Please have faith in my words..

#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

const int max_n = 5e5 + 40;

int n, q;
vector<int>	adj[max_n];
int s_t[max_n], f_t[max_n], sz;
int seg[max_n * 4], maxi[max_n * 4];

void dfs(int v, int p){
	s_t[v] = sz++;
	for (int u:adj[v])
		if (u != p)
			dfs(u, v);
	f_t[v] = sz;
}

void shift(int v){
	maxi[v<<1] = max(maxi[v], maxi[v<<1]);
	maxi[v<<1^1] = max(maxi[v<<1^1], maxi[v]);
}

void modify(int v, int b, int e, int l, int r, int x){
	if (l <= b && e <= r){
		maxi[v] = x;
		return;
	}
	if (r <= b || e <= l)	return;

	int mid = (b + e)/ 2;
	shift(v);
	modify(v<<1, b, mid, l, r, x);
	modify(v<<1^1, mid, e, l, r, x);
}

void mod2(int v, int b, int e, int u, int x){
	if (e - b == 1){
		seg[v] = x;
		return;
	}

	int mid = (b + e)/ 2;
	if (u < mid)
		mod2(v<<1, b, mid, u, x);
	else
		mod2(v<<1^1, mid, e, u, x);
	seg[v] = max(seg[v<<1], seg[v<<1^1]);
}

int get2(int v, int b, int e, int l, int r){
	if (l <= b && e <= r)	return	seg[v];
	if (r <= b || e <= l)	return	0;
	
	int mid = (b + e)/ 2;
	return	max(get2(v<<1, b, mid, l, r), get2(v<<1^1, mid, e, l, r));
}

int get1(int v, int b, int e, int u){
	if (e - b == 1)	return	maxi[v];

	int mid = (b + e)/ 2;
	shift(v);
	if (u < mid)
		return	get1(v<<1, b, mid, u);
	return	get1(v<<1^1, mid, e, u);
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++){
		int a, b;	scanf("%d%d", &a, &b);	a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(0, -1);
	scanf("%d", &q);
	for (int i = 1; i <= q; i++){
		int type;	scanf("%d", &type);
		if (type == 1){
			int v;	scanf("%d", &v);	v--;
			modify(1, 0, n, s_t[v], f_t[v], i);
			continue;
		}
		if (type == 2){
			int v;	scanf("%d", &v);	v--;
			mod2(1, 0, n, s_t[v], i);
			continue;
		}
		int v;	scanf("%d", &v);	v--;
		if (get2(1, 0, n, s_t[v], f_t[v]) >= get1(1, 0, n, s_t[v]))
			printf("0\n");
		else
			printf("1\n");
	}
	return 0;
}