#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

const int maxn = 200100;
int n, m, rt;
long double res;
pair<long double, int> ans;
int w[maxn], sz[maxn];
long double dev[maxn];
vector<pair<int, int>> ed[maxn];
bool del[maxn];

void dfs(int t, int fa){
	sz[t] = 1;
	for(auto e : ed[t]){
		int v = e.fi;
		if(v == fa || del[v]) continue;
		dfs(v, t);
		sz[t] += sz[v];
	}
}

void getroot(int t, int fa){
	int tmax = 0;
	for(auto e : ed[t]){
		int v = e.fi;
		if(v == fa || del[v]) continue;
		getroot(v, t);
		tmax = max(tmax, sz[v]);
	}
	tmax = max(m - sz[t], tmax);
	if(tmax <= m / 2) rt = t;
}

void dfs(int t, int fa, int ce, ll d){
	if(!ce && fa) ce = t, dev[t] = 0;
	dev[ce] += sqrt(d) * w[t];
	res += d * sqrt(d) * w[t];
	for(auto e : ed[t]){
		int v = e.fi, c = e.se;
		if(v == fa) continue;
		dfs(v, t, ce, d + c);
	}
}

void solve(int t){
	dfs(t, 0);
	m = sz[t];
	getroot(t, 0);

	res = 0;
	dfs(rt, 0, 0, 0);
	del[rt] = 1;
	ans = min(ans, mkp(res, rt));
	long double sum = 0;
	for(auto e : ed[rt]){
		int v = e.fi;
		sum += dev[v];
	}
	int nex = 0;
	for(auto e : ed[rt]){
		int v = e.fi;
		if(del[v]) continue;
		if(sum - 2 * dev[v] < 0) nex = v;
	}
	if(nex) solve(nex);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", w + i);
	for(int i = 1; i < n; ++i){
		static int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		ed[u].pb(mkp(v, c));
		ed[v].pb(mkp(u, c));
	}
	ans = mkp(1e100, 0);
	solve(1);
	printf("%d %.10f\n", ans.se, (double)ans.fi);
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}