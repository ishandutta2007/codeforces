#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int N, K;
int A[300300];

int k0, k1, l;
ll dp[5010][5010];

ll foo(int a, int b) {
	if(dp[a][b] != -1) return dp[a][b];
	if(a == 0 && b == 0) return 0;
	int p = a * l + b * (l + 1);
	dp[a][b] = 1LL << 60;
	if(a > 0)
		dp[a][b] = min(dp[a][b], foo(a - 1, b) + A[p - 1] - A[p - l]);
	if(b > 0)
		dp[a][b] = min(dp[a][b], foo(a, b - 1) + A[p - 1] - A[p - l - 1]);
	return dp[a][b];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(dp, -1, sizeof(dp));
	
	cin >> N >> K;
	for(int n = 0; n < N; ++n) cin >> A[n];
	sort(A, A + N);
	k1 = N % K;
	k0 = K - k1;
	l = N / K;		//length k0
	
	cout << foo(k0, k1) << '\n';
}