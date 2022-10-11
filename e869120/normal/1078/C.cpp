#include <iostream>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

vector<int>X[1 << 19], Y[1 << 19];
int N, A[1 << 19], B[1 << 19]; bool used[1 << 19];
long long dp[1 << 19][3], mod = 998244353;

long long modpow(long long a, long long b, long long m) {
	long long p = 1, q = a;
	for (int i = 0; i < 32; i++) {
		if ((b / (1LL << i)) % 2 == 1) { p *= q; p %= m; }
		q *= q; q %= m;
	}
	return p;
}

long long Div(long long a, long long b, long long m) {
	return (a * modpow(b, m - 2, m)) % m;
}

void dfs(int pos) {
	used[pos] = true;
	for (int i = 0; i < X[pos].size(); i++) {
		if (used[X[pos][i]] == true) continue;
		Y[pos].push_back(X[pos][i]);
		dfs(X[pos][i]);
	}
}

long long calc(vector<long long>E1, vector<long long>E2) {
	long long ret = 1; vector<int>id;
	for (int i = 0; i < E1.size(); i++) { ret *= E1[i]; if (E1[i] == 0) id.push_back(i); ret %= mod; }

	if (id.size() >= 2) return 0;
	if (id.size() == 1) {
		long long rem = 1;
		for (int i = 0; i < E1.size(); i++) { if (i != id[0]) { rem *= E1[i]; rem %= mod; } }
		rem *= E2[id[0]]; rem %= mod;
		return rem;
	}

	long long sum = 0;
	for (int i = 0; i < E2.size(); i++) { sum += Div(ret * E2[i] % mod, E1[i], mod); sum %= mod; }
	return sum;
}

void solve(int pos) {
	for (int i = 0; i < Y[pos].size(); i++) solve(Y[pos][i]);

	long long c1 = 1; for (int i : Y[pos]) { c1 *= (dp[i][0] + dp[i][1]); c1 %= mod; }

	vector<long long>E1, E2, E3;
	for (int i : Y[pos]) E1.push_back((dp[i][0] + 2LL * dp[i][1]) % mod);
	for (int i : Y[pos]) E2.push_back((dp[i][0] + dp[i][2]) % mod);
	for (int i : Y[pos]) E3.push_back(dp[i][1]);
	
	dp[pos][0] = c1;
	dp[pos][1] = calc(E1, E2);

	long long V1 = 1; for (int i = 0; i < E1.size(); i++) { V1 *= E1[i]; V1 %= mod; }
	long long V2 = 1; for (int i = 0; i < E2.size(); i++) { V2 *= (E1[i] - E3[i] + mod) % mod; V2 %= mod; }
	dp[pos][2] = (V1 - V2 + mod) % mod;
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N - 1; i++) {
		scanf("%d%d", &A[i], &B[i]);
		X[A[i]].push_back(B[i]);
		X[B[i]].push_back(A[i]);
	}
	dfs(1);
	solve(1);
	cout << (dp[1][0] + dp[1][1]) % mod << endl;
	return 0;
}