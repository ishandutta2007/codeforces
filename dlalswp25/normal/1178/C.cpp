#include <bits/stdc++.h>

using namespace std;

int MOD = 998244353;

int main() {
	int W, H; scanf("%d%d", &W, &H);
	int ans = 1;
	for(int i = 0; i < W + H; i++) ans = ans * 2 % MOD;
	printf("%d\n", ans);
	return 0;
}