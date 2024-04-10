#include <iostream>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

long long mod = 1000000007;
long long N, X[1 << 18], A[1 << 18], B[1 << 18], dist[1 << 18];
long long par[1 << 18][22], dp[1 << 18][22];
vector<int> G[1 << 18];
bool used[1 << 18];

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

void dfs(int pos, int dep) {
	used[pos] = true; dist[pos] = dep;
	for (int i = 0; i < G[pos].size(); i++) {
		if (used[G[pos][i]] == true) continue;
		par[G[pos][i]][0] = pos;
		dfs(G[pos][i], dep + 1);
	}
}

pair<long long, long long> diff(long long pos, long long cnt) {
	long long ret = 0, x = 0;
	for (int i = 21; i >= 0; i--) {
		long long R = gcd(ret, dp[pos][i]);
		long long S1 = R; if (S1 == 0) S1 = (1LL << 60);
		long long S2 = cnt; if (S2 == 0) S2 = (1LL << 60);
		if (S1 >= S2) { ret = R; x += (1 << i); pos = par[pos][i]; }
	}
	if (pos == 0) return make_pair((1LL << 22) - 1LL, -1LL);
	return make_pair(x, gcd(ret, X[pos]));
}

int main() {
	scanf("%lld", &N);
	for (int i = 1; i <= N; i++) scanf("%lld", &X[i]);
	for (int i = 1; i <= N - 1; i++) {
		scanf("%lld%lld", &A[i], &B[i]);
		G[A[i]].push_back(B[i]);
		G[B[i]].push_back(A[i]);
	}

	dfs(1, 0);

	for (int i = 1; i <= N; i++) dp[i][0] = X[i];
	for (int i = 1; i < 22; i++) {
		for (int j = 1; j <= N; j++) par[j][i] = par[par[j][i - 1]][i - 1];
	}
	for (int i = 1; i < 22; i++) {
		for (int j = 1; j <= N; j++) dp[j][i] = gcd(dp[j][i - 1], dp[par[j][i - 1]][i - 1]);
	}

	long long sum = 0;
	for (int i = 1; i <= N; i++) {
		vector<pair<long long, long long>> val;
		long long cx = X[i]; val.push_back(make_pair(X[i], 0));

		while (true) {
			pair<long long, long long> rem = diff(i, cx);
			if (rem.first == (1 << 22) - 1) break;
			val.push_back(make_pair(rem.second, rem.first));
			cx = rem.second;
		}
		val.push_back(make_pair(0, dist[i] + 1));

		for (int j = 1; j < val.size(); j++) {
			sum += (val[j - 1].first % mod) * ((val[j].second - val[j - 1].second + mod * mod) % mod);
			sum %= mod;
		}
	}

	cout << sum << endl;
	return 0;
}