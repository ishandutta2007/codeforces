//A black wind took you away, from sight..

#include<bits/stdc++.h>

using namespace std;

const int MAXN = 3e3 + 10;

int n, from[MAXN], to[MAXN], w[MAXN], sec[MAXN], x[MAXN];
int par[MAXN], sz[MAXN], sm;

bool cmp(int e1, int e2){
	return w[e1] < w[e2];
}

int get_par(int v){return par[v] == v?v:par[v]=get_par(par[v]);}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++)
		cin >> from[i] >> to[i] >> w[i], from[i]--, to[i]--;
	iota(sec, sec + n - 1, 0);
	sort(sec, sec + n - 1, cmp);
	for (int i = 0; i < n; i++)	cin >> x[i], sm += x[i];
	iota(par, par + n, 0);
	fill(sz, sz + n, 1);
	int ans = 0;
	for (int i = 0; i < n - 1; i++){
		int e = sec[i];
		int pu = get_par(from[e]), pv = get_par(to[e]);
		par[pu] = pv;
		sz[pv] += sz[pu];
		x[pv] += x[pu];
		ans = w[e];
		if (sm - x[pv] < sz[pv])	break;
	}
	cout << ans << "\n";
	return 0;
}