#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

int N, M, A[509][509], dp[509][1024], pre[509][1024];

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) scanf("%d", &A[i][j]);
	}
	dp[0][0] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 1024; j++) {
			if (dp[i - 1][j] == 0) continue;
			for (int k = 1; k <= M; k++) { dp[i][j^A[i][k]] = 1; pre[i][j^A[i][k]] = k; }
		}
	}
	int V = -1;
	for (int i = 1; i < 1024; i++) { if (dp[N][i] == 1) V = i; }

	if (V == -1) cout << "NIE" << endl;
	else {
		int cx = V; vector<int>vec;
		for (int i = N; i >= 1; i--) {
			vec.push_back(pre[i][cx]);
			cx = (cx ^ A[i][pre[i][cx]]);
		}
		reverse(vec.begin(), vec.end());

		cout << "TAK" << endl;
		for (int i = 0; i < vec.size(); i++) { if (i) cout << " "; cout << vec[i]; }
		cout << endl;
	}
	return 0;
}