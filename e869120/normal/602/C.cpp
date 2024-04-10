#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

int N, M, dist1[409], dist2[409];
bool used[409][409];

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= M; i++) {
		int u, v; scanf("%d%d", &u, &v);
		used[u][v] = true; used[v][u] = true;
	}
	
	for (int i = 2; i <= N; i++) { dist1[i] = (1 << 30); dist2[i] = (1 << 30); }
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (used[j][k] == true) { dist1[k] = min(dist1[k], dist1[j] + 1); }
				if (used[j][k] == false) { dist2[k] = min(dist2[k], dist2[j] + 1); }
			}
		}
	}
	
	int V = max(dist1[N], dist2[N]);
	if (V == (1 << 30)) V = -1;
	cout << V << endl;
	return 0;
}