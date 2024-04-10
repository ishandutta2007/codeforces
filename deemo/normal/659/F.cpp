#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>
#include<cstring>

using namespace std;

typedef long long ll;

const ll MAXN = 1e3 + 10;

ll n, m, c[MAXN][MAXN], sz, ww, size[MAXN][MAXN];
bool vis[MAXN][MAXN];
ll k;
pair<ll, ll>	sec[MAXN * MAXN], pnt(-1, -1), par[MAXN][MAXN];

bool fit(ll a, ll b){return 0 <= a && a < n && 0 <= b && b < m;}

bool cmp(pair<ll, ll> a, pair<ll, ll> b){return c[a.first][a.second] > c[b.first][b.second];}

pair<ll, ll>	get_par(ll a, ll b){
	if (par[a][b] == make_pair(a, b))	return	{a, b};
	return	par[a][b] = get_par(par[a][b].first, par[a][b].second);
}

void dfs(ll a, ll b){
	if (vis[a][b] || k == 0 || c[a][b] < ww)	return;
	k -= ww;
	vis[a][b] = 1;
	c[a][b] = ww;
	for (ll aa = -1; aa <= 1; aa++)
		for (ll bb = -1; bb <= 1; bb++)
			if (abs(aa) + abs(bb) == 1 && fit(a + aa, b + bb))
				dfs(a + aa, b + bb);
}

int main(){
	scanf("%I64d %I64d %I64d", &n, &m, &k);
	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < m; j++)	scanf("%I64d", &c[i][j]), sec[sz++] = {i, j}, par[i][j] = {i, j}, size[i][j] = 1;
	sort(sec, sec + sz, cmp);
	for (ll i = 0; i < sz; i++){
		auto v = sec[i];
		vis[v.first][v.second] = 1;
		ll w = c[v.first][v.second];
		for (ll aa = -1; aa <= 1; aa++)
			for (ll bb = -1; bb <= 1; bb++)
				if (abs(aa) + abs(bb) == 1 && fit(v.first + aa, v.second + bb) && vis[v.first + aa][v.second + bb]){
					auto p1 = get_par(v.first, v.second), p2 = get_par(v.first + aa, v.second + bb);
					if (p1 == p2)	continue;
					size[p1.first][p1.second] += size[p2.first][p2.second];
					par[p2.first][p2.second] = p1;
				}
		auto p1 = get_par(v.first, v.second);
		ll ss = size[p1.first][p1.second];
		if (k % ll(w) == 0){
			ll z = k/ ll(w);
			if (z > ss)	continue;
			pnt = v;
			break;
		}
	}
	if (pnt.first == -1){
		printf("NO\n");
		return 0;
	}
	ww = c[pnt.first][pnt.second];
	printf("YES\n");
	memset(vis, 0, sizeof(vis));
	dfs(pnt.first, pnt.second);
	for (ll i = 0; i < n; i++){
		for (ll j = 0; j < m; j++)
			if (!vis[i][j])
				printf("0 ");
			else
				printf("%I64d ", c[i][j]);
		printf("\n");
	}
	return	0;
}