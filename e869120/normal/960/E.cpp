#include <iostream>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

const long long mod = 1000000007;
long long N, A[1 << 18], r0[1 << 18], r1[1 << 18], col[1 << 18];
vector<int>X[1 << 18], Y[1 << 18];
bool used[1 << 18];

void dfs(int pos, int dep) {
	// 0 : , 1 : 
	used[pos] = true; col[pos] = dep;
	if (col[pos] == 0) r0[pos] = 1;
	else r1[pos] = 1;
	for (int i = 0; i < X[pos].size(); i++) {
		if (used[X[pos][i]] == true) continue;
		Y[pos].push_back(X[pos][i]);
		dfs(X[pos][i], dep ^ 1);

		r1[pos] += r1[X[pos][i]];
		r0[pos] += r0[X[pos][i]];
	}
}

int main() {
	scanf("%lld", &N);
	for (int i = 1; i <= N; i++) scanf("%lld", &A[i]);
	for (int i = 1; i <= N - 1; i++) {
		int a, b; scanf("%d%d", &a, &b);
		X[a].push_back(b);
		X[b].push_back(a);
	}
	dfs(1, 0);

	long long sum = 0;
	for (int i = 1; i <= N; i++) {
		long long S0 = r0[1] * (r0[1] + r1[1]), S1 = r1[1] * (r0[1] + r1[1]);
		if (col[i] == 1) swap(S0, S1);

		long long cx0 = r0[1], cx1 = r1[1];
		if (col[i] == 0) cx0--; else cx1--;

		for (int j = 0; j < Y[i].size(); j++) {
			int to = Y[i][j];
			long long T0 = r0[to] * (r0[to] + r1[to]), T1 = r1[to] * (r0[to] + r1[to]);
			if (col[i] == 1) swap(T0, T1);
			S0 -= T0; S1 -= T1;
			cx0 -= r0[to]; cx1 -= r1[to];
		}
		long long U0 = cx0 * (cx0 + cx1), U1 = cx1 * (cx0 + cx1);
		if (col[i] == 1) swap(U0, U1);
		S0 -= U0; S1 -= U1;

		long long V1 = (A[i] + mod) % mod;
		long long V2 = (S0 - S1 + mod * mod) % mod;
		sum += V1 * V2; sum %= mod;
	}
	cout << sum << endl;
	return 0;
}