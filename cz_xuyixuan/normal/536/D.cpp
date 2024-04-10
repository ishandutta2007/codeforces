#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e3 + 5;
const long long INF = 1e18;
typedef long long ll;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
namespace ShortestPath {
	const ll INF = 1e18;
	const int MAXP = 1e6;
	struct edge {int dest, len; };
	int n; ll dist[MAXP];
	vector <edge> a[MAXP];
	set <pair <ll, int> > st;
	void addedge(int x, int y, int z) {
		a[x].push_back((edge) {y, z});
	}
	void init(int x) {
		n = x; st.clear();
		for (int i = 1; i <= n; i++) {
			dist[i] = INF;
			a[i].clear();
		}
	}
	void work(int s) {
		dist[s] = 0;
		for (int i = 1; i <= n; i++)
			if (s != i) dist[i] = INF;
		st.insert(make_pair(0, s));
		while (!st.empty()) {
			pair <ll, int> tmp = *st.begin();
			st.erase(tmp);
			for (unsigned i = 0; i < a[tmp.second].size(); i++) {
				int dest = a[tmp.second][i].dest;
				ll newlen = tmp.first + a[tmp.second][i].len;
				if (newlen < dist[dest]) {
					st.erase(make_pair(dist[dest], dest));
					dist[dest] = newlen;
					st.insert(make_pair(dist[dest], dest));
				}
			}
		}
	}
}
int n, m, s, t;
int p[MAXN], x[MAXN], y[MAXN];
int cnt[MAXN][MAXN]; ll sum[MAXN][MAXN];
ll dp[MAXN][MAXN][2], aux[MAXN][MAXN][2];
void makecor(ll *x, int *y) {
	set <ll> st; map <ll, int> res;
	for (int i = 1; i <= n; i++)
		st.insert(x[i]);
	int tot = 0;
	for (auto x : st) res[x] = ++tot;
	for (int i = 1; i <= n; i++)
		y[i] = res[x[i]];
}
int calcnt(int lx, int rx, int ly, int ry) {
	return cnt[rx][ry] - cnt[rx][ly - 1] - cnt[lx - 1][ry] + cnt[lx - 1][ly - 1];
}
ll calsum(int lx, int rx, int ly, int ry) {
	return sum[rx][ry] - sum[rx][ly - 1] - sum[lx - 1][ry] + sum[lx - 1][ly - 1];
}
void debug() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			printf("(%4lld,%4lld) ", dp[i][j][0], dp[i][j][1]);
		printf("\n");
	}
}
int main() {
	read(n), read(m), read(s), read(t);
	for (int i = 1; i <= n; i++)
		read(p[i]);
	ShortestPath :: init(n);
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		read(x), read(y), read(z);
		ShortestPath :: addedge(x, y, z);
		ShortestPath :: addedge(y, x, z);
	}
	ShortestPath :: work(s);
	makecor(ShortestPath :: dist, x);
	ShortestPath :: work(t);
	makecor(ShortestPath :: dist, y);
	for (int i = 1; i <= n; i++) {
		cnt[x[i]][y[i]]++;
		sum[x[i]][y[i]] += p[i];
	}
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++) {
		cnt[i][j] += cnt[i - 1][j] + cnt[i][j - 1] - cnt[i - 1][j - 1];
		sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
	}
	for (int i = n; i >= 1; i--)
	for (int j = n; j >= 1; j--) {
		aux[i][j][0] = dp[i + 1][j][1] + sum[i][n] - sum[i][j - 1];
		if (i != n) chkmax(aux[i][j][0], aux[i + 1][j][0]);
		if (calcnt(i, i, j, n) == 0) dp[i][j][0] = dp[i + 1][j][0];
		else dp[i][j][0] = aux[i][j][0] + sum[i - 1][j - 1] - sum[i - 1][n];
		
		aux[i][j][1] = dp[i][j + 1][0] - sum[n][j] + sum[i - 1][j];
		if (j != n) chkmin(aux[i][j][1], aux[i][j + 1][1]);
		if (calcnt(i, n, j, j) == 0) dp[i][j][1] = dp[i][j + 1][1];
		else dp[i][j][1] = aux[i][j][1] - sum[i - 1][j - 1] + sum[n][j - 1];
	}
	//debug();
	if (dp[1][1][0] > 0) puts("Break a heart");
	else if (dp[1][1][0] == 0) puts("Flowers");
	else puts("Cry");
	return 0;
}