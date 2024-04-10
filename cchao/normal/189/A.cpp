#include <bits/stdc++.h>
using namespace std;

int dp[4010], n, a, b, c;

int f(int x) {
	if(x == 0) return 0;
	int &r = dp[x];
	if(r != -1) return r;
	r = -100000;
	if(x >= a) r = max(r, f(x - a) + 1);
	if(x >= b) r = max(r, f(x - b) + 1);
	if(x >= c) r = max(r, f(x - c) + 1);
	return r;
}

int main() {
	memset(dp, -1, sizeof dp);
	scanf("%d%d%d%d", &n, &a, &b, &c);
	printf("%d\n", f(n));
	return 0;
}