#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

// 
int N, M, K;
int A[1 << 18], B[1 << 18], W[1 << 18];
vector<pair<int, int>> X[1 << 18];
vector<pair<int, int>> Y[1 << 18];

//  (a-b  c-d )
int Answer;
int T[11];
int cnt[11][11];
bool used[11][11][11][11];

void dfs(int pos) {
	if (pos == K) {
		bool flag = false;
		for (int i = 1; i <= pos; i++) {
			for (int j = i; j <= pos; j++) {
				if (used[i][T[i]][j][T[j]] == true) flag = true;
			}
		}
		if (flag == false) Answer += 1;
		return;
	}
	for (int i = 0; i <= pos; i++) {
		T[pos + 1] = i;
		dfs(pos + 1);
	}
}

int main() {
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 1; i <= M; i++) {
		scanf("%d%d%d", &A[i], &B[i], &W[i]);
		X[A[i]].push_back(make_pair(W[i], B[i]));
	}
	for (int i = 1; i <= N; i++) {
		sort(X[i].begin(), X[i].end());
		for (int j = 0; j < X[i].size(); j++) {
			int to = X[i][j].second;
			Y[to].push_back(make_pair(X[i].size(), j));
		}
	}

	for (int i = 1; i <= N; i++) {
		// 
		for (int j = 0; j <= 10; j++) {
			for (int k = 0; k <= 10; k++) cnt[j][k] = 0;
		}
		for (int j = 0; j < Y[i].size(); j++) cnt[Y[i][j].first][Y[i][j].second] += 1;

		// Y[i] 
		Y[i].clear();
		for (int j = 0; j <= 10; j++) {
			for (int k = 0; k <= 10; k++) {
				for (int l = 0; l < min(cnt[j][k], 2); l++) Y[i].push_back(make_pair(j, k));
			}
		}

		// 
		for (int j = 0; j < Y[i].size(); j++) {
			for (int k = j + 1; k < Y[i].size(); k++) {
				used[Y[i][j].first][Y[i][j].second][Y[i][k].first][Y[i][k].second] = true;
				used[Y[i][k].first][Y[i][k].second][Y[i][j].first][Y[i][j].second] = true;
			}
		}
	}

	dfs(1);
	cout << Answer << endl;
	return 0;
}