#include <bits/stdc++.h>

using namespace std;

int N;
int C[1000];

int memo[1000][1000];
int dp(int a, int b) {
	if(b - a <= 0) return 0;
	if(memo[a][b] != -1) return memo[a][b];
	memo[a][b] = 1 << 30;
	if(C[a] == C[b]) memo[a][b] = dp(a + 1, b - 1);
	for(int i = a; i < b; ++i)
		memo[a][b] = min(memo[a][b], dp(a, i) + dp(i + 1, b) + 1);
	return memo[a][b];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(memo, -1, sizeof(memo));
	
	cin >> N;
	for(int n = 0; n < N; ++n)
		cin >> C[n];
	
	cout << (dp(0, N - 1) + 1) << '\n';
}