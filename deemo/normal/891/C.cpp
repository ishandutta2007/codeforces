#include<cstdio>
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 5e5 + 10;

int n, m, uu[MAXN], vv[MAXN], ww[MAXN], sec[MAXN], par[MAXN], ed[MAXN], size[MAXN];

bool cmp(int e1, int e2){return ww[e1] < ww[e2];}
int getPar(int v){return par[v]==v?v:par[v]=getPar(par[v]);}
int getPar2(int v){return par[v]==v?v:getPar(par[v]);}

int hist[MAXN];
int main(){
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
		scanf("%d %d %d", &uu[i], &vv[i], &ww[i]), uu[i]--, vv[i]--;
	iota(sec, sec+m, 0);
	sort(sec, sec+m, cmp);
	iota(par, par+n, 0);
	for (int l = 0; l < m; ){
		int r = l;
		while (r < m && ww[sec[l]] == ww[sec[r]]) r++;

		for (int i = l; i < r; i++){
			int e = sec[i];
			int u = getPar(uu[e]), v = getPar(vv[e]);
			uu[e] = u, vv[e] = v;
		}

		for (; l < r; l++){
			int e = sec[l];
			int u = getPar(uu[e]), v = getPar(vv[e]);
			if (u==v) continue;
			par[u] = v;
		}
	}

	iota(par, par+n,0);
	fill(size, size+n, 1);
	int q; scanf("%d", &q);
	while (q--){
		int sz; scanf("%d", &sz);
		for (int i = 0; i < sz; i++)
			scanf("%d", &ed[i]), ed[i]--;
		sort(ed, ed+sz, cmp);

		bool fail = false;
		for (int l = 0; l < sz && !fail;){
			int r = l, cc = 0;
			while (r < sz && ww[ed[l]] == ww[ed[r]]) r++;
			for (; l < r; l++){
				int e = ed[l];
				int u = getPar2(uu[e]), v = getPar2(vv[e]);
				if (u == v){
					fail = true;
					break;
				}

				if (size[u] > size[v])
					swap(u, v);
				par[u] = v;
				size[v] += size[u];
				hist[cc++] = u;
			}

			while (cc > 0){
				cc--;
				size[par[hist[cc]]] -= size[hist[cc]];
				par[hist[cc]] = hist[cc];
			}
		}

		if (fail)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}