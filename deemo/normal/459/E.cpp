#include<cstdio>
#include<cassert>
#include<algorithm>
#include<vector>
#include<utility>
#include<numeric>

using namespace std;

const int MAXN = 6e5 + 100;
const int MAXE = 6e5 + 100;

int n, m, ec, cn, t;
int edge[MAXE], d[MAXE], sec[MAXE], id[MAXE];
int from[MAXE], to[MAXE], w[MAXE];
vector<int>	adj[MAXN];
int le[MAXN], ri[MAXN];
int weed[4 * MAXE];

void add_edge(int a, int b, int c){from[ec] = a, to[ec] = b, w[ec] = c;	ec++;}	

bool cmp(int a, int b){return	w[a] > w[b];}

void water(int v, int b, int e, int x, int val){
	if (e - b == 1){
		weed[v] = val;
		return;
	}
	
	int mid = (b + e)/ 2;
	if (x < mid)
		water(v<<1, b, mid, x, val);
	else
		water(v<<1^1, mid, e, x, val);
	weed[v] = max(weed[v<<1], weed[v<<1^1]);
}

int smoke(int v, int b, int e, int l, int r){
	if (l <= b && e <= r)	return	weed[v];
	if (r <= b || e <= l)	return	0;

	int mid = (b + e)/ 2;
	return	max(smoke(v<<1, b, mid, l, r), smoke(v<<1^1, mid, e, l, r));
}

int main(){
	scanf("%d%d", &n, &m);
	while (m--){
		int a, b, c;	scanf("%d%d%d", &a, &b, &c);	a--, b--;
		adj[a].push_back(ec);
		add_edge(a, b, c);
	}

	for (int i = 0; i < n; i++){
		le[i] = cn;
		for (int e:adj[i])
			id[e] = cn++;
		ri[i] = cn;
	}
	iota(edge, edge + ec, 0);
	sort(edge, edge + ec, cmp);

	int ans = 0;
	for (int i = 0; i < ec; i++){
		int e = edge[i];
		if (i != 0 && w[edge[i - 1]] != w[e]){
			for (int h = 0; h < t; h++)
				water(1, 0, ec, id[sec[h]], d[sec[h]]);
			t = 0;
		}

		int l = le[to[e]], r = ri[to[e]];
		d[e] = smoke(1, 0, ec, l, r) + 1;
		ans = max(ans, d[e]);
		sec[t++] = e;
	}
	printf("%d\n", ans);
	return	0;
}