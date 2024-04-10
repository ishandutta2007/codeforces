#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

const long long mod = 998244353;
const long long lim = (1LL << 62);

long long N, M, A[1 << 20];
long long S, B[1 << 20], el[509], er[509], t[1009][1009], dp[1009][1009];
vector<int> G[509];

long long solve() {
	for (int i = 1; i <= N; i++) { el[i] = (1LL << 30); er[i] = -(1LL << 30); }
	for (int i = 1; i <= S; i++) {
		el[B[i]] = min(el[B[i]], 1LL * i);
		er[B[i]] = max(er[B[i]], 1LL * i);
		G[B[i]].push_back(i);
	}
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j++) {
			// t[i][j] : Is there string between j and j + 1?
			t[i][el[j]]++; t[i][er[j]]--;
		}
		for (int j = 1; j <= S; j++) t[i][j] += t[i][j - 1];
	}
	
	for (int i = 1; i <= S + 1; i++) dp[i][i - 1] = 1;

	for (int i = 0; i <= S; i++) {
		for (int j = 1; j <= S - i; j++) {
			int cl = j, cr = j + i;

			int up = (1 << 30);
			for (int k = cl; k <= cr; k++) up = min(up, (int)B[k]);

			if (!(cl <= el[up] && er[up] <= cr)) continue;

			long long get_left = 0;
			for (int k = cl; k <= el[up]; k++) {
				if (t[up + 1][k - 1] >= 1) continue;
				get_left += dp[cl][k - 1] * dp[k][el[up] - 1];
				if (get_left >= lim) get_left %= mod;
			}
			get_left %= mod;

			long long get_right = 0;
			for (int k = er[up]; k <= cr; k++) {
				if (t[up + 1][k] >= 1) continue;
				get_right += dp[er[up] + 1][k] * dp[k + 1][cr];
				if (get_right >= lim) get_right %= mod;
			}
			get_right %= mod;

			long long res = get_left * get_right % mod;
			for (int k = 0; k < (int)G[up].size() - 1; k++) {
				res *= dp[G[up][k] + 1][G[up][k + 1] - 1];
				res %= mod;
			}

			dp[cl][cr] = res;
		}
	}
	return dp[1][S];
}

int main() {
	scanf("%lld%lld", &N, &M);
	for (int i = 1; i <= M; i++) scanf("%lld", &A[i]);
	for (int i = 1; i <= M; i++) {
		if (i == 1 || A[i] != A[i - 1]) {
			S++; B[S] = A[i];
		}
	}
	if (S > 1000) {
		cout << "0" << endl;
		return 0;
	}
	cout << solve() << endl;
	return 0;
}