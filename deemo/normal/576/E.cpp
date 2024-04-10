//weird

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
#include<utility>
#include<numeric>

using namespace std;

const int MAXN = 5e5 + 10;
const int MAXK = 50 + 1;

int n, m, k, q;
int from[MAXN], to[MAXN], cl[MAXN];
int id[MAXN], col[MAXN];
int comp[MAXK][MAXN], sz[MAXK][MAXN];
bool cg[MAXK][MAXN];
vector<int>	qq[MAXN];
vector<pair<int, int>>	nut[4 * MAXN];
vector<pair<pair<pair<int, int>, pair<int, int>>, int>>	hist;

void water(int v, int b, int e, int l, int r, int ed, int c){
	if (r - l == 0)	return;
	if (l <= b && e <= r){
		nut[v].push_back({ed, c});
		return;
	}
	if (r <= b || e <= l)	return;

	int mid = (b + e)/ 2;
	water(v<<1, b, mid, l, r, ed, c);
	water(v<<1^1, mid, e, l, r, ed, c);
}	

int get_comp(int v, int mk){
	if (comp[mk][v] == v)	return	v;
	return	get_comp(comp[mk][v], mk);
}

bool pt(int v, int mk){
	if (comp[mk][v] == v)	return	cg[mk][v];
	return	cg[mk][v] ^ pt(comp[mk][v], mk);
}

bool merge(pair<int, int>	ed){
	int u = from[ed.first], v = to[ed.first], mk = ed.second;
	int uu = get_comp(u, mk), vv = get_comp(v, mk);
	if (sz[mk][uu] > sz[mk][vv])	swap(u, v), swap(uu, vv);
	if (uu == vv)	return false;

	int aa = pt(u, mk), bb = pt(v, mk);
	bool fl = aa == bb;
	cg[mk][uu] ^= fl;
	comp[mk][uu] = vv;
	sz[mk][vv] += sz[mk][uu];
	hist.push_back({{{uu, vv}, {fl, sz[mk][uu]}}, mk});
	return	true;
}

void undo(){
	auto x = hist.back();
	int uu = x.first.first.first, vv = x.first.first.second, zz = x.first.second.second, mk = x.second;
	bool fl = x.first.second.first;
	cg[mk][uu] ^= fl;
	comp[mk][uu] = uu;
	sz[mk][vv] -= zz;
	hist.pop_back();
}

bool ok(int ed, int mk){return pt(from[ed], mk) != pt(to[ed], mk) || get_comp(from[ed], mk) != get_comp(to[ed], mk);}

void dfs(int v, int b, int e){
	int tt = 0;
	for (auto x:nut[v])
		if (merge(x))	tt++;
	if (e - b == 1){
		int ed = id[b], c = col[b];
		qq[ed].pop_back();
		if (ok(ed, c))
			printf("YES\n"), cl[ed] = c;
		else
			printf("NO\n");
		if (cl[ed])
			water(1, 0, q, b + 1, qq[ed].empty()?q:qq[ed].back(), ed, cl[ed]);
	}
	else{
		int mid = (b + e)/ 2;
		dfs(v<<1, b, mid);
		dfs(v<<1^1, mid, e);
	}
	while (tt--)	undo();
}

int main(){
	scanf("%d %d %d %d", &n, &m, &k, &q);
	for (int i = 0; i < m; i++)
		scanf("%d %d", &from[i], &to[i]), from[i]--, to[i]--;
	for (int i = 0; i < q; i++){
		scanf("%d %d", &id[i], &col[i]), id[i]--;
		qq[id[i]].push_back(i);
	}
	for (int i = 0; i < MAXN; i++)
		reverse(qq[i].begin(), qq[i].end());
	for (int i = 1; i <= k; i++)
		iota(comp[i], comp[i] + n, 0), fill(sz[i], sz[i] + n, 1);
	dfs(1, 0, q);
	return	0;
}