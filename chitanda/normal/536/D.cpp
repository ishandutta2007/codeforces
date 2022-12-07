#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define all(a) a.begin(), a.end()

const int maxn = 2005;
const int inf = 1e9;
int n, m, s, t;
int p[maxn];
int dis[maxn][maxn];
ll d[2][maxn];
bool tag[maxn];
int cnt[maxn][maxn];
ll sum[maxn][maxn];
ll dp[2][maxn][maxn];
ll mx[2][maxn];

int dij(bool k, int S){
	memset(tag, 0, sizeof(tag));
	memset(d[k], 127, sizeof(d[k]));
	d[k][S] = 0;
	for(int i = 1; i <= n; ++i){
		int tmp = -1;
		for(int j = 1; j <= n; ++j)
			if(!tag[j] && (tmp == -1 || d[k][j] < d[k][tmp])) tmp = j;
		if(tmp == -1) break;
		tag[tmp] = 1;
		for(int j = 1; j <= n; ++j)
			if(!tag[j] && dis[tmp][j] < inf)
				d[k][j] = min(d[k][j], d[k][tmp] + dis[tmp][j]);
	}
	
	vector<ll> q;
	for(int i = 1; i <= n; ++i) q.pb(d[k][i]);
	sort(all(q));
	q.erase(unique(all(q)), q.end());
	for(int i = 1; i <= n; ++i)
		d[k][i] = lower_bound(all(q), d[k][i]) - q.begin() + 1;
	return q.size();
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	scanf("%d%d", &s, &t);
	memset(dis, 127, sizeof(dis));
	for(int i = 1; i <= n; ++i) scanf("%d", p + i);
	for(int i = 1; i <= m; ++i){
		static int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		dis[u][v] = min(dis[u][v], w);
		dis[v][u] = min(dis[u][v], w);
	}
	
	int mn = dij(0, s);
	int mm = dij(1, t);

	for(int i = 0; i <= mn; ++i){
		for(int j = 1; j <= n; ++j)
			if(d[0][j] <= i) ++cnt[i][0], sum[i][0] += p[j];
			else ++cnt[i][d[1][j]], sum[i][d[1][j]] += p[j];
		for(int j = 1; j <= mm; ++j){
			cnt[i][j] += cnt[i][j - 1];
			sum[i][j] += sum[i][j - 1];
		}
	}
	
	for(int i = 0; i <= mn; ++i)
		mx[0][i] = -sum[i][mm];
	for(int i = 0; i <= mm; ++i)
		mx[1][i] = sum[mn][i];
	
	for(int i = mn - 1; i >= 0; --i)
		for(int j = mm - 1; j >= 0; --j){
			if(cnt[i][j] == n) continue;
			if(cnt[i][j] == cnt[i + 1][j])
				dp[0][i][j] = dp[0][i + 1][j];
			else
				dp[0][i][j] = mx[1][j] - sum[i][j];
			
			
			if(cnt[i][j] == cnt[i][j + 1])
				dp[1][i][j] = dp[1][i][j + 1];
			else
				dp[1][i][j] = mx[0][i] + sum[i][j];
			mx[0][i] = min(mx[0][i], dp[0][i][j] - sum[i][j]);
			mx[1][j] = max(mx[1][j], dp[1][i][j] + sum[i][j]);
		}
	
	if(dp[0][0][0] > 0) puts("Break a heart");
	else if(dp[0][0][0] < 0) puts("Cry");
	else puts("Flowers");
	return 0;
}