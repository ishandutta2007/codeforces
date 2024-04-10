#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#define fi first
#define se second
using namespace std;
const long long INF = 1LL << 60;
struct data{ long long mn, smn; };
data operator + (const data &d, const int &x){
	data a = d;
	if (x < a.mn) a.smn = a.mn, a.mn = x;
	else if (x < a.smn) a.smn = x;
	return a;
}
const int maxn = 1e6 + 6;
vector <int> G[maxn];
map <int, data> mp;
int s[maxn];
long long sum = 0, ans = INF, dp[maxn], a[maxn][3];
int n;
void build(int u, int f){
	s[u] = 1;
	for (int i = 0; i < G[u].size(); ++ i){
		int v = G[u][i];
		if (v != f){
			build(v, u);
			s[u] += s[v];
		}
	}
}
void dfs(int u, int f){
	if (f && G[u].size() == 1){
		dp[u] = 1LL * s[u] * s[u];
		return;
	}
	dp[u] = INF;
	for (int i = 0; i < G[u].size(); ++ i){
		int v = G[u][i];
		if (v != f){
			dfs(v, u);
			dp[u] = min(dp[u], dp[v] + 1LL * (s[u] - s[v]) * (s[u] - s[v]));
		}
	}
	mp.clear();
	mp[0] = {0, INF};
	for (int i = 0; i < G[u].size(); ++ i){
		int v = G[u][i];
		if (v != f){
			if (mp.count(s[v]))
				mp[s[v]] = mp[s[v]] + dp[v];
			else
				mp[s[v]] = {dp[v], INF};
		}
	}
	int m = 0;
	for (map <int, data> :: iterator it = mp.begin(); it != mp.end(); ++ it){
		pair <int, data> p = *it;
		a[++ m][0] = p.fi, a[m][1] = p.se.mn, a[m][2] = p.se.smn;
	}
	for (int i = 1; i <= m; ++ i)
		if (a[i][2] != INF){
			long long t = 1LL * n * n - 2LL * n * (a[i][0] + a[i][0]) + 2LL * a[i][0] * a[i][0] + 2LL * a[i][0] * a[i][0];
			ans = min(ans, t + a[i][1] + a[i][2]);
		}
	for (int i = 1; i <= m; ++ i)
		for (int j = i + 1; j <= m; ++ j){
			long long t = 1LL * n * n - 2LL * n * (a[i][0] + a[j][0]) + 2LL * a[i][0] * a[j][0] + 1LL * a[i][0] * a[i][0] + 1LL * a[j][0] * a[j][0];
			ans = min(ans, t + a[i][1] + a[j][1]);
		}
}
int read(){
	int c = 0; char ch = getchar();
	while (ch < '0' || '9' < ch) ch = getchar();
	while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
	return c;
}
int main(){
	n = read();
	for (int i = 1; i < n; ++ i){
		int u = read(), v = read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	build(1, 0);
	dfs(1, 0);
	cout << 1LL * n * (n - 1) - (ans - n) / 2 << endl;
}