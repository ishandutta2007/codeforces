#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int N, K;
int D[202020];
int tmp[202020];
int E[202020];
int ans[202020];

int main() {
	scanf("%d%d", &N, &K);
	int s = K;
	D[0] = 1;
	for(int i = K; s <= N; s += ++i) {
		for(int j = 0; j < i; j++) E[j] = 0;
		E[0] = D[0];
		for(int j = 1; j <= N; j++) {
			tmp[j] = E[j % i];
			E[j % i] = (E[j % i] + D[j]) % MOD;
		}
		for(int j = 0; j <= N; j++) {
			D[j] = tmp[j];
			ans[j] = (ans[j] + D[j]) % MOD;
		}
	}
	for(int i = 1; i <= N; i++) printf("%d ", ans[i]); puts("");
	return 0;
}