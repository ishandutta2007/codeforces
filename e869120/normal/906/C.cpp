#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

int N, M, A[1009], B[1009], dp[1 << 22], mask[1 << 22];
int ans[1 << 22]; pair<int, int> pre[1 << 22];

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> A[i] >> B[i]; A[i]--; B[i]--;
		mask[A[i]] |= (1 << B[i]);
		mask[B[i]] |= (1 << A[i]);
		dp[(1 << A[i]) + (1 << B[i])] += 1;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < (1 << N); j++) {
			if ((j&(1 << i)) == 0) { dp[j + (1 << i)] += dp[j]; }
		}
	}
	for (int i = 0; i < (1 << N); i++) ans[i] = (1 << 30);
	for (int i = 0; i < N; i++) { ans[(1 << i)] = 0; pre[(1 << i)] = make_pair(-1, -1); }

	for (int i = 1; i < (1 << N); i++) {
		if (ans[i] == (1 << 30)) continue;

		for (int j = 0; j < N; j++) {
			if ((i & (1 << j)) == 0) continue;
			int E = (i | mask[j]);
			if (ans[E] > ans[i] + 1) {
				ans[E] = ans[i] + 1;
				pre[E] = make_pair(i, j);
			}
		}
	}

	int maxn = (1 << 30), maxid = -1;
	for (int i = 0; i < (1 << N); i++) {
		if (ans[i] == (1 << 30)) continue;

		int E = M - dp[i];
		int F1 = N * (N - 1) / 2;
		int F2 = 0; for (int j = 0; j < N; j++) { if ((i&(1 << j)) != 0) F2++; }
		F2 = F2 * (F2 - 1) / 2;

		if (E == F1 - F2) {
			if (maxn > ans[i]) { maxn = ans[i]; maxid = i; }
		}
	}

	int cx = maxid;
	vector<int>vec;
	while (true) {
		if (pre[cx].second == -1) break;
		vec.push_back(pre[cx].second);
		cx = pre[cx].first;
	}
	reverse(vec.begin(), vec.end());

	cout << maxn << endl;
	for (int i = 0; i < vec.size(); i++) { if (i) cout << " "; cout << vec[i] + 1; } cout << endl;
	return 0;
}