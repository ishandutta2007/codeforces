#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3005;

int D[MAXN][MAXN];
int IO[MAXN][MAXN], II[MAXN][MAXN];
int n;

vector<int> G[MAXN];

queue<int> Q;
void bfs(int node) {
	D[node][node] = 1;
	Q.push(node);

	while(!Q.empty()) {
		int top = Q.front();
		Q.pop();

		for(auto vec : G[top])
			if(D[node][vec] == 0) {
				D[node][vec] = D[node][top] + 1;
				Q.push(vec);
			}
	}

	for(int i = 1; i <= n; ++i)
		if(D[node][i] == 0)
			D[node][i] = -1e8;
}

int main() {
	int a, b;
	cin >> n;

	int m;
	cin >> m;
	while(m--) {
		cin >> a >> b;
		G[a].push_back(b);
	}

	for(int i = 1; i <= n; ++i)
			bfs(i);

	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			II[i][j] = IO[i][j] = j;
		}

		sort(II[i] + 1, II[i] + n + 1, [&](int a, int b) {return D[a][i] > D[b][i];});
		sort(IO[i] + 1, IO[i] + n + 1, [&](int a, int b) {return D[i][a] > D[i][b];});

	}

	int best = -1;
	int b1, b2, b3, b4;

	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j) {
			if(i == j) continue;

			for(int k = 1; k <= 4; ++k)
				for(int l = 1; l <= 4; ++l) {
					int a = II[i][k];
					int b = IO[j][l];

					if(a != b && a != i && a != j && b != i && b != j) {
						if(best < D[a][i] + D[i][j] + D[j][b]) {
							best = D[a][i] + D[i][j] + D[j][b];
							b1 = a; b2 = i; b3 = j; b4 = b;
						}
					}
				}
		}

	cout << b1 << " " << b2 << " " << b3 << " " << b4 << '\n';

}