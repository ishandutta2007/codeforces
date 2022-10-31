#include <iostream>
#include <vector>
#define INF 1LL << 60
#define maxn 5003
using namespace std;
int n, w[maxn], d[maxn], sze[maxn];
vector <int> G[maxn];
long long g[maxn][2], f[maxn][2][maxn];
void dp(int u){
	f[u][1][0] = INF;
	f[u][1][1] = w[u] - d[u];
	f[u][0][0] = 0;
	f[u][0][1] = w[u];
	sze[u] = 1;
	for (int i = 0; i < G[u].size(); ++ i){
		int v = G[u][i];
		dp(v);
		for (int j = 0; j <= n; ++ j)
			g[j][0] = g[j][1] = INF;
		for (int j = 0; j <= sze[u]; ++ j)
			for (int k = 0; k <= sze[v]; ++ k){
				g[j + k][1] = min(g[j + k][1], min(f[u][1][j] + f[v][1][k], f[u][1][j] + f[v][0][k]));
				g[j + k][0] = min(g[j + k][0], f[u][0][j] + f[v][0][k]);
			}
		for (int j = 0; j <= sze[u] + sze[v]; ++ j){
			f[u][1][j] = min(f[u][1][j], g[j][1]);
			f[u][0][j] = min(f[u][0][j], g[j][0]);
		}
		sze[u] += sze[v];
	}
}
int main(){
	int b;
	cin >> n >> b;
	for (int i = 1; i <= n; ++ i){
		cin >> w[i] >> d[i];
		if (i > 1){
			int f;
			cin >> f;
			G[f].push_back(i);
		}
	}
	for (int i = 1; i <= n; ++ i)
		for (int j = 0; j <= n; ++ j)
			f[i][0][j] = f[i][1][j] = INF;
	dp(1);
	for (int i = n; i >= 0; -- i)
		if (f[1][0][i] <= b || f[1][1][i] <= b){
			cout << i << endl;
			return 0;
		}
}