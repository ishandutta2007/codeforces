#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int F[4010][4010], Deg[4010], ff[4010][4010];
vector<int>G[4010], Num[4010], res[4010];
int n1, n2, m, source, sink, v[4010], cc;
int Flow(int a) {
	if (a == sink)return 1;
	v[a] = cc;
	for (auto &x : G[a]) {
		if (v[x] != cc && F[a][x]) {
			if (Flow(x)) {
				F[a][x]--;
				F[x][a]++;
				return 1;
			}
		}
	}
	return 0;
}
int main() {
	int i, a, b, j;
	scanf("%d%d%d", &n1, &n2, &m);
	sink = n1 + n2 + 1;
	for (i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		b += n1;
		F[a][b]++;
		G[a].push_back(b);
		G[b].push_back(a);
		Num[a].push_back(i+1);
		Num[b].push_back(i+1);
		Deg[a]++, Deg[b]++;
	}
	int Mn = 1e9;
	for (i = 1; i <= n1 + n2; i++)Mn = min(Mn, Deg[i]);
	for (i = 1; i <= n1; i++) {
		G[0].push_back(i), G[i].push_back(0);
		F[0][i] = Deg[i] - Mn;
	}
	for (i = n1 + 1; i <= n1 + n2; i++) {
		G[sink].push_back(i), G[i].push_back(sink);
		F[i][sink] = Deg[i] - Mn;
	}
	for (int tt = 0; tt <= Mn; tt++) {
		cc++;
		while (Flow(0)){
			cc++;
		}
		for (i = 1; i <= n1; i++) {
			for (auto &t : G[i])ff[i][t] = F[i][t];
		}
		for (i = 1; i <= n1; i++) {
			for (j = 0; j < G[i].size(); j++) {
				int x = G[i][j];
				if (x && ff[i][x]) {
					ff[i][x]--;
					res[Mn - tt].push_back(Num[i][j]);
				}
			}
		}
		for (i = 1; i <= n1; i++)F[0][i]++;
		for (i = n1 + 1; i <= n1 + n2; i++)F[i][sink]++;
	}
	for (i = 0; i <= Mn; i++) {
		printf("%d ", res[i].size());
		for (auto &t : res[i])printf("%d ", t);
		puts("");
	}
}