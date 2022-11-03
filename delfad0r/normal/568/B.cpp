#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1000000007;

int N;
int binom[5000][5000];
int eq[5000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	
	for(int i = 0; i <= N; ++i)
		binom[i][0] = 1;
	for(int n = 1; n <= N; ++n)
		for(int k = 1; k <= n; ++k)
			binom[n][k] = (binom[n - 1][k] + binom[n - 1][k - 1]) % MOD;
	eq[0] = 1;
	for(int n = 1; n <= N; ++n) {
		eq[n] = 0;
		for(int k = 0; k < n; ++k)
			eq[n] = (eq[n] + ((ll(binom[n - 1][k]) * ll(eq[k])) % MOD)) % MOD;
	}
	
	int ans = 0;
	for(int n = 1; n <= N; ++n)
		ans = (ans + ((ll(binom[N][n]) * ll(eq[N - n])) % MOD)) % MOD;
	cout << ans;
}