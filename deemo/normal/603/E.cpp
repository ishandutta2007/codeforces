//I want you to know it's a little fucked up that I'm stuck here waitin', no longer debatin'
//tired of sittin' and hatin' and making these excuses
//for why you're not around, and feelin so useless.

#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#include<numeric>
#include<set>

using namespace std;

const int MAXN = 3e5 + 10;

int n, m, from[MAXN], to[MAXN], w[MAXN], ed[MAXN], par[MAXN], sz[MAXN], cur, cc, ans[MAXN];
int tt, tw[MAXN], type[MAXN], gg[MAXN], pg1[MAXN], pg2[MAXN];
vector<int>	ls[4 * MAXN];
multiset<int>	wt;

bool cmp(int e1, int e2){return w[e1] < w[e2];}

void insert(int v, int b, int e, int l, int r){
	if (l <= b && e <= r){
		ls[v].push_back(l);
		return;
	}
	if (r <= b || e <= l)	return;

	int mid = (b + e)/ 2;
	insert(v<<1, b, mid, l, r);
	insert(v<<1^1, mid, e, l, r);
}	

int get_par(int v){return par[v]==v?v:get_par(par[v]);}

void add(int e){
	wt.insert(w[e]);
	int u = from[e], v = to[e];
	int pu = get_par(u), pv = get_par(v);
	tw[tt] = w[e];
	if (pu == pv){
		type[tt++] = 0;
		return;
	}		
	type[tt] = 1;
	
	if ((sz[pu] & 1) && (sz[pv] & 1))	cc-=2, gg[tt] = 2;
	else	gg[tt] = 0;

	pg1[tt] = pu, pg2[tt] = pv;
	if (sz[pu] > sz[pv])	sz[pu] += sz[pv], par[pv] = pu;
	else	sz[pv] += sz[pu], par[pu] = pv;	
	tt++;
}

void undo(){
	tt--;
	wt.erase(wt.find(tw[tt]));
	if (!type[tt])	return;
	
	cc += gg[tt];
	if (sz[pg1[tt]] > sz[pg2[tt]])	par[pg2[tt]] = pg2[tt], sz[pg1[tt]] -= sz[pg2[tt]];
	else	par[pg1[tt]] = pg1[tt], sz[pg2[tt]] -= sz[pg1[tt]];
}	

void dfs(int v, int l, int r){
	for (int e:ls[v])	add(e);

	if (r - l == 1){
		ans[l] = -1;
		while (cur < m && cc){
			int e = ed[cur++];
			if (e <= l)
				insert(1, 0, m, e, l), insert(1, 0, m, l, r), add(e);
		}
		if (!cc){
			auto it = wt.end();	it--;
			ans[l] = *it;
		}
	}
	else{
		int mid = (l + r)/ 2;
		dfs(v<<1^1, mid, r);
		dfs(v<<1, l, mid);
	}
	for (int e:ls[v])
		undo();
}

int main(){
	scanf("%d %d", &n, &m);	cc = n;
	for (int i = 0; i < m; i++)
		scanf("%d %d %d", &from[i], &to[i], &w[i]), from[i]--, to[i]--;
	iota(ed, ed + m, 0);
	sort(ed, ed + m, cmp);
	iota(par, par + n, 0);
	fill(sz, sz + n, 1);
	dfs(1, 0, m);

	for (int i = 0; i < m; i++)
		printf("%d\n", ans[i]);
	return 0;
}