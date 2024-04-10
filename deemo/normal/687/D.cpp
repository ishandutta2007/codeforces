#include<cstdio>
#include<algorithm>
#include<numeric>
#include<cstring>
#include<vector>

using namespace std;

const int MAXN = 1e3 + 2;
const int MAXE = 1e6 + 2;

int n, m, q;
int from[MAXE], to[MAXE], w[MAXE], ed[MAXE];
vector<int>	adj[MAXN];
int comp[MAXN], sz[MAXN];
bool col[MAXN], ss[MAXN];

bool cmp(int u, int v){return w[u] > w[v];}

void go(int v, bool t, int p){
	comp[v] = p;
	col[v] ^= t;
	for (int u:adj[v])
		go(u, t, p);
}

int ans(int l, int r){
	for (int i = 0; i < n; i++)	adj[i].clear();
	iota(comp, comp + n, 0);
	fill(sz, sz + n, 1);
	memset(col, 0, sizeof(col));
	memset(ss, 0, sizeof(ss));

	int u, v, pu, pv;
	for (int i = 0; i < m; i++)
		if (l <= ed[i] && ed[i] < r){
			int e = ed[i];
			u = from[e], v = to[e];
			pu = comp[u], pv = comp[v];
			if (sz[pu] < sz[pv])	swap(pu, pv);

			if (pu ^ pv){
				bool t = ss[pv];
				if ((col[u] ^ ss[pu]) == (col[v] ^ ss[pv]))	t = !t;
				adj[pu].push_back(pv);
				sz[pu] += sz[pv];
				go(pv, t^ss[pu], pu);
			}
			else if ((col[u] ^ ss[pu]) == (col[v] ^ ss[pv]))	return w[e];
		}
	return -1;
}

int main(){
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 0; i < m; i++)	scanf("%d %d %d", &from[i], &to[i], &w[i]), from[i]--, to[i]--;
	iota(ed, ed + m, 0);
	sort(ed, ed + m, cmp);
	while (q--){
		int l, r;	scanf("%d %d", &l, &r), l--;
		printf("%d\n", ans(l, r));
	}
	return 0;
}