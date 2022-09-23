#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int cnt[20];
int A[101010];
int N;
ll T[30];

const ll MOD = 998244353;
ll ans = 0;

int nd(int x) {
	int ret = 0;
	while(x) {
		ret++;
		x /= 10;
	}
	return ret;
}

void f(int x) {
	for(int i = 0; x; i++) {
		int t = x % 10;
		x /= 10;
		for(int j = 0; j <= 10; j++) {
			if(j <= i) {
				ans = (ans + t * cnt[j] * T[i + j]) % MOD;
				ans = (ans + t * cnt[j] * T[i + j]) % MOD;
			}
			else {
				ans = (ans + t * cnt[j] * T[2 * i + 1]) % MOD;
				ans = (ans + t * cnt[j] * T[2 * i]) % MOD;
			}
		}
	}
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
		cnt[nd(A[i])]++;
	}

	T[0] = 1;
	for(int i = 1; i <= 20; i++) T[i] = T[i - 1] * 10 % MOD;

	for(int i = 1; i <= N; i++) f(A[i]);

	printf("%lld\n", ans);

	return 0;
}