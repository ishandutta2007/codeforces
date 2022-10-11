#include<iostream>
#include<vector>
using namespace std;
int a[1005][1005], n, m, q, sum, r1[100005], r2[100005], r3[100005], ret[100005]; vector<int>x[100005];
void dfs(int pos) {
	for (int i = 0; i < x[pos].size(); i++) {
		int F = x[pos][i];
		if (r1[F] == 1) {
			int V = a[r2[F]][r3[F]];
			if (V == 0) { a[r2[F]][r3[F]] = 1; sum++; }
			ret[F] = sum;
			dfs(F);
			if (V == 0) { a[r2[F]][r3[F]] = V; sum--; }
		}
		if (r1[F] == 2) {
			int V = a[r2[F]][r3[F]];
			if (V == 1) { a[r2[F]][r3[F]] = 0; sum--; }
			ret[F] = sum;
			dfs(F);
			if (V == 1) { a[r2[F]][r3[F]] = V; sum++; }
		}
		if (r1[F] == 3) {
			for (int i = 1; i <= m; i++) { 
				if (a[r2[F]][i] == 1) { a[r2[F]][i] = 0; sum--; } 
				else { a[r2[F]][i] = 1; sum++; }
			}
			ret[F] = sum;
			dfs(F);
			for (int i = 1; i <= m; i++) {
				if (a[r2[F]][i] == 1) { a[r2[F]][i] = 0; sum--; }
				else { a[r2[F]][i] = 1; sum++; }
			}
		}
		if (r1[F] == 4) {
			ret[F] = sum;
			dfs(F);
		}
	}
}
int main() {
	cin >> n >> m >> q;
	for (int i = 1; i <= q; i++) {
		cin >> r1[i] >> r2[i]; if (r1[i] <= 2)cin >> r3[i];
		if (r1[i] == 4) { x[r2[i]].push_back(i); }
		else { x[i - 1].push_back(i); }
	}
	dfs(0);
	for (int i = 1; i <= q; i++)cout << ret[i] << endl;
	return 0;
}