#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#include<cstring>
#include<numeric>

using namespace std;

typedef long long ll;

#define F first
#define S second

const int MAXN = 1e5 + 10;

int n, from[MAXN], to[MAXN], w[MAXN];
int ed[MAXN], sec[MAXN];
vector<int>	adj[MAXN];
int depth[MAXN], sz;
ll ss[MAXN];
ll size[MAXN];
int par[MAXN];
pair<ll, int>	gec[MAXN];
int tt;

bool cmp(int u, int v){return w[u] < w[v];}
bool cmpe(int e1, int e2){return depth[from[e1]] > depth[from[e2]];}
int cmpz(pair<ll, int>	a, pair<ll, int> b){
	if (a.F ^ b.F)
		return a.F > b.F;
	return a.S < b.S;
}

int get_par(int v){return par[v]==v?v:par[v]=get_par(par[v]);}

void plant(int v, int p = -1, int de = 0){
	depth[v] = de;
	for (int e:adj[v])
		if (e^p){
			int u = (from[e]==v?to[e]:from[e]);
			plant(u, e, de + 1);
		}
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++){
		scanf("%d %d %d", &from[i], &to[i], &w[i]), from[i]--, to[i]--;
		adj[from[i]].push_back(i);
		adj[to[i]].push_back(i);
	}
	plant(0);
	for (int i = 0; i < n - 1; i++)
		if (depth[to[i]] < depth[from[i]])	swap(from[i], to[i]);

	iota(ed, ed + n - 1, 0);
	sort(ed, ed + n - 1, cmp);
	fill(size, size + n, 1);
	iota(par, par + n, 0);

	for (int i = 0; i < n - 1;){
		int j = i, sz = 0;
		while (j < n - 1 && w[ed[i]] == w[ed[j]])
			sec[sz++] = ed[j++];
		
		sort(sec, sec + sz, cmpe);
		for (int e = 0; e < sz; e++){
			int p1 = get_par(from[sec[e]]), p2 = get_par(to[sec[e]]);
			ss[sec[e]] = size[p2];
			par[p2] = p1;
			size[p1] += size[p2];
		}
		
		for (; i < j; i++)
			gec[tt++] = {ss[ed[i]] * (ll(size[get_par(from[ed[i]])]) - ss[ed[i]]) * 2ll, ed[i]};
	}

	sort(gec, gec + tt, cmpz);
	int cnt = 0;
	while (cnt < n - 1 && gec[cnt].F == gec[0].F)	cnt++;
	printf("%I64d %d\n", gec[0].F, cnt);
	for (int i = 0; i < cnt; i++)
		printf("%d ", gec[i].S + 1);
	printf("\n");
	return 0;
}