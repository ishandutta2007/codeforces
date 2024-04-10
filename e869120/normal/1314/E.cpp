#include <iostream>
#include <vector>
using namespace std;

long long mod = 998244353;
long long N, K;
long long cnt = 0;

long long func(long long dep, vector<long long> vec) {
	if (dep == 3) {
		long long S = 0, SC = 0;
		for (int i = 0; i < vec.size(); i++) {
			long long cur = vec.size() - i;
			for (int j = 0; j < vec[i]; j++) { SC++; S += cur * SC; }
		}
		return S;
	}
	else {
		vector<long long> vec2;
		for (int i = vec.size() - 1; i >= 0; i--) {
			for (int j = 0; j < vec[i]; j++) {
				vec2.push_back(vec.size() - i);
				if (vec2.size() > N) return N + 1;
			}
		}
		return func(dep - 1, vec2);
	}
}

void dfs(vector<long long> vec, long long dep) {
	for (int i = dep; i <= N; i++) {
		vector<long long> vec2 = vec;
		vec2.push_back(i);
		if (func(K, vec2) > N) break;
		cnt++;
		dfs(vec2, i);
	}
}

// 
long long dp1[3009];
long long func_1() {
	dp1[0] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= N - i; j++) { dp1[j + i] += dp1[j]; dp1[j + i] %= mod; }
	}
	long long sum = 0;
	for (int i = 1; i <= N; i++) { sum += dp1[i]; sum %= mod; }
	return sum;
}

//  (2) 
long long dp[3009][3009];
long long func_2() {
	dp[0][0] = 1;
	for (int i = N; i >= 1; i--) {
		int border = N / i;
		for (int j = 0; j <= N - i; j++) {
			for (int k = 0; k <= border; k++) {
				if (dp[j][k] == 0) continue;

				int idx = j + (k + 1) * i;
				if (idx > N) break;
				dp[idx][k + 1] += dp[j][k];
				if (dp[idx][k + 1] >= mod) dp[idx][k + 1] -= mod;
			}
		}
	}

	long long sum = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) { sum += dp[i][j]; sum %= mod; }
	}
	return sum;
}

int main() {
	cin >> N >> K;

	if (K >= 3) {
		dfs({}, 1);
		cout << cnt << endl;
	}
	if (K == 2) {
		cout << func_2() << endl;
	}
	if (K == 1) {
		cout << func_1() << endl;
	}
	return 0;
}