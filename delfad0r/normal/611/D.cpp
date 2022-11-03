#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

typedef long long ll;

int N;
char S[5050];
int dp[5050][5050];
int Z[5050][5050];

void Zalgo(char * s, int len, int * z) {
	int l = 0, r = 0;
	for(int i = 1; i < len; ++i) {
		if(i <= r)
			z[i] = min(r - i + 1, z[i - l]);
		while(i + z[i] < len && s[z[i]] == s[i + z[i]])
			++z[i];
		if(i + z[i] >= r) {
			l = i;
			r = i + z[i] - 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	cin >> S;
	S[N] = '\0';
	
	for(int i = 0; i < N; ++i)
		Zalgo(S + i, N - i, Z[i] + i);
	for(int j = 0; j < N; ++j)
		dp[0][j] = 1;
	for(int i = 1; i < N; ++i) {
		if(S[i] == '0') continue;
		int k = i;
		for(int j = i; j < N; ++j) {
			dp[i][j] = dp[i][j - 1];
			while(k > 0 && j - i > i - k) {
				--k;
				dp[i][j] = (dp[i][j] + dp[k][i - 1]) % MOD;
			}
			if(k == 0) continue;
			if(Z[k - 1][i] + k - 1 < i && S[Z[k - 1][i] + k - 1] < S[Z[k - 1][i] + i]) {
				--k;
				dp[i][j] = (dp[i][j] + dp[k][i - 1]) % MOD;
			}
		}
	}
	
	ll ans = 0;
	for(int i = 0; i < N; ++i)
		ans += dp[i][N - 1];
	cout << (ans % MOD) << '\n';
}