#include <bits/stdc++.h>

using namespace std;

int N, M, Q;
char G[600][600];
int D[600][600], R[600][600];

int queryD(int n1, int m1, int n2, int m2) {
	return D[n2][m2] - D[n1 - 1][m2] - D[n2][m1 - 1] + D[n1 - 1][m1 - 1];
}
int queryR(int n1, int m1, int n2, int m2) {
	return R[n2][m2] - R[n1 - 1][m2] - R[n2][m1 - 1] + R[n1 - 1][m1 - 1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;
	for(int n = 0; n < N; ++n)
		cin >> G[n];
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < M; ++j) {
			D[i + 1][j + 1] = (G[i][j] == '.' && G[i + 1][j] == '.');
			R[i + 1][j + 1] = (G[i][j] == '.' && G[i][j + 1] == '.');
		}
	for(int i = 1; i <= N; ++i)
		for(int j = 1; j <= M; ++j) {
			D[i][j] += D[i - 1][j] + D[i][j - 1] - D[i - 1][j - 1];
			R[i][j] += R[i - 1][j] + R[i][j - 1] - R[i - 1][j - 1];
		}
	cin >> Q;
	while(Q--) {
		int n1, m1, n2, m2;
		cin >> n1 >> m1 >> n2 >> m2;
		cout << queryD(n1, m1, n2 - 1, m2) + queryR(n1, m1, n2, m2 - 1) << '\n';
	}
}