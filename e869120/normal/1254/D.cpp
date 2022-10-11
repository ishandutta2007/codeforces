#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

class BIT {
public:
	int size_ = 1;
	vector<long long> bit;

	void init(int sz) {
		size_ = sz + 2;
		bit.resize(size_ + 2, 0);
	}
	void add(int pos, long long x) {
		pos++;
		while (pos <= size_) {
			bit[pos] += x;
			pos += (pos & -pos);
		}
	}
	long long sum(int pos) {
		long long s = 0; pos++;
		while (pos >= 1) {
			s += bit[pos];
			pos -= (pos & -pos);
		}
		return s;
	}
};

long long modpow(long long a, long long b, long long m) {
	long long p = 1, q = a;
	for (int i = 0; i < 32; i++) {
		if ((b / (1LL << i)) % 2 == 1) { p *= q; p %= m; }
		q *= q; q %= m;
	}
	return p;
}

const long long mod = 998244353;
int Backet;

int N, U[1 << 18], V[1 << 18];
int Q, T[1 << 18], A[1 << 18], B[1 << 18];
int cl[1 << 18], cr[1 << 18], dp[1 << 18], cnts;
vector<int> X[1 << 18], Y[1 << 18];

long long Answer[1 << 18];
long long Keisuu[1 << 18];
long long Keisuu2[1 << 18];
BIT Z;

void dfs(int pos) {
	cnts++; cl[pos] = cnts; dp[pos] = 1;
	for (int i = 0; i < X[pos].size(); i++) {
		if (cl[X[pos][i]] >= 1) continue;
		dfs(X[pos][i]);
		Y[pos].push_back(X[pos][i]);
		dp[pos] += dp[X[pos][i]];
	}
	cr[pos] = cnts;
}

void adds(int pos, long long q) {
	if (X[pos].size() > Backet) return;
	for (int i : Y[pos]) {
		Z.add(cl[i], 1LL * (N - dp[i]) * q);
		Z.add(cr[i] + 1, -1LL * (N - dp[i]) * q);
	}
	Z.add(1, 1LL * dp[pos] * q);
	Z.add(N + 1, -1LL * dp[pos] * q);
	Z.add(cl[pos], -1LL * dp[pos] * q);
	Z.add(cr[pos] + 1, 1LL * dp[pos] * q);
	Z.add(cl[pos], 1LL * N * q);
	Z.add(cl[pos] + 1, -1LL * N * q);
}

void solve(int pos) {
	for (int i = 1; i <= N; i++) Keisuu[i] = dp[pos];
	for (int i : Y[pos]) {
		for (int j = cl[i]; j <= cr[i]; j++) Keisuu[j] = N - dp[i];
	}
	Keisuu[cl[pos]] = N;

	for (int i = 1; i <= Q; i++) Keisuu2[i] = 0;
	for (int i = 1; i <= Q; i++) { if (T[i] == 1 && A[i] == pos) Keisuu2[i] += B[i]; }
	for (int i = 1; i <= Q; i++) Keisuu2[i] += Keisuu2[i - 1];

	for (int i = 1; i <= Q; i++) {
		if (T[i] == 1) continue;
		Answer[i] += Keisuu2[i] * Keisuu[cl[A[i]]];
	}
}

int main() {
	//  1. 
	scanf("%d%d", &N, &Q);
	for (int i = 1; i <= N - 1; i++) scanf("%d%d", &U[i], &V[i]);
	for (int i = 1; i <= Q; i++) {
		scanf("%d", &T[i]);
		if (T[i] == 1) scanf("%d%d", &A[i], &B[i]);
		if (T[i] == 2) scanf("%d", &A[i]);
	}

	//  2. 
	for (int i = 1; i <= N - 1; i++) {
		X[U[i]].push_back(V[i]);
		X[V[i]].push_back(U[i]);
	}

	//  3. DFS
	dfs(1);
	Backet = max(1, (int)(0.44 * sqrt(1.0 * N)));

	//  4. 
	Z.init(N + 2);
	for (int i = 1; i <= Q; i++) {
		if (T[i] == 1) adds(A[i], B[i]);
		if (T[i] == 2) Answer[i] += Z.sum(cl[A[i]]);
	}

	//  5. 
	for (int i = 1; i <= N; i++) {
		if (X[i].size() <= Backet) continue;
		solve(i);
	}

	//  6. 
	long long V = modpow(N, mod - 2, mod);
	for (int i = 1; i <= Q; i++) {
		if (T[i] == 2) printf("%lld\n", (Answer[i] % mod) * V % mod);
	}
	return 0;
}