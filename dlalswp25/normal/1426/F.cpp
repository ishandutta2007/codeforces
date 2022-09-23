#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int N;
ll P[202020];
char A[202020];

int sa[202020];
int sc[202020];

int main() {
	scanf("%d", &N);
	scanf("%s", A + 1);
	P[0] = 1;
	for(int i = 1; i <= N; i++) P[i] = P[i - 1] * 3 % MOD;

	int K = 0;
	for(int i = 1; i <= N; i++) {
		sa[i] = sa[i - 1]; sc[i] = sc[i - 1];
		if(A[i] == 'a') sa[i]++;
		if(A[i] == 'c') sc[i]++;
		if(A[i] == '?') K++;
	}

	ll ans = 0;
	int cnt = 0;
	for(int i = 1; i <= N; i++) {
		int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
		int k = K;
		if(A[i] == 'b') {
			x1 = cnt, x2 = K - cnt;
			y1 = sa[i], y2 = sc[N] - sc[i];

		}
		else if(A[i] == '?') {
			x1 = cnt, x2 = K - cnt - 1;
			y1 = sa[i], y2 = sc[N] - sc[i];
			k = K - 1;
			cnt++;
		}
		else continue;

		ans = (ans + P[k] * y1 % MOD * y2 % MOD) % MOD;
		if(k >= 1) ans = (ans + P[k - 1] * x1 % MOD * y2 % MOD) % MOD;
		if(k >= 1) ans = (ans + P[k - 1] * x2 % MOD * y1 % MOD) % MOD;
		if(k >= 2) ans = (ans + P[k - 2] * x1 % MOD * x2 % MOD) % MOD;
	}
	printf("%lld\n", ans);

	return 0;
}