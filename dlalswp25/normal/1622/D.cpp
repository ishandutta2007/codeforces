#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;

int N, K;
char A[5050];
ll ncr[5050][5050];

int main() {
	scanf("%d%d", &N, &K);
	scanf("%s", A + 1);
	int cnt = 0;
	for(int i = 1; i <= N; i++) cnt += A[i] == '1';
	if(!K || cnt < K) { puts("1"); return 0; }

	for(int i = 0; i <= N; i++) ncr[i][0] = 1;
	for(int i = 1; i <= N; i++) for(int j = 1; j <= i; j++) ncr[i][j] = (ncr[i - 1][j - 1] + ncr[i - 1][j]) % MOD;

	ll ans = 1;
	for(int i = 1; i <= N; i++) {
		int cnt = 0;
		int j = i;
		for(; j <= N; j++) {
			if(A[j] == '1') cnt++;
			if(cnt > K) break;
		}
		if(cnt > K) cnt = K;
		if(A[i] == '1') ans = (ans + ncr[j - i - 1][cnt]) % MOD;
		else ans = (ans + ncr[j - i - 1][cnt - 1]) % MOD;
	}
	printf("%lld\n", ans);
	return 0;
}