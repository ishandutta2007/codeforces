#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int prev_[10008][108], dp[10008][108], N, A[108], W[108];

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) { cin >> A[i]; W[A[i]]++; }

	prev_[0][0] = 1;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j <= 10000; j++) {
			for (int k = 0; k <= 100; k++) {
				if (prev_[j][k] == 0) continue;
				for (int l = 0; l <= W[i + 1]; l++) {
					int t1 = j + (i + 1) * l, t2 = k + l;
					dp[t1][t2] += prev_[j][k];
					if (dp[t1][t2] >= 2) dp[t1][t2] = 2;
				}
			}
		}
		for (int j = 0; j <= 10000; j++) { for (int k = 0; k <= 100; k++) { prev_[j][k] = dp[j][k]; dp[j][k] = 0; } }
	}

	int maxn = 0;
	for (int i = 1; i <= 100; i++) {
		for (int j = 0; j <= W[i]; j++) {
			if (prev_[i * j][j] == 1) maxn = max(maxn, j);
		}
	}
	vector<pair<int, int>>v;
	for (int i = 1; i <= 100; i++) { if (W[i] >= 1) v.push_back(make_pair(W[i], i)); }

	if (v.size() == 2 && prev_[v[0].first * v[0].second][v[0].first] == 1) maxn = N;
	cout << maxn << endl;
	return 0;
}