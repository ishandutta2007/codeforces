#include <bits/stdc++.H>

#define MAXN (100010)
#define ll long long

int n;
int m[MAXN], sm[MAXN];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i) {
		scanf("%d", m + i);
		sm[i] = m[i] + 1 - i;
	}
	sm[n] = INT_MIN;
	for (int i = n - 1; ~i; -- i) {
		sm[i] = std::max(sm[i], sm[i + 1]);
	}
	ll ans = 0;
	int x = 1;
	for (int i = 1; i < n; ++ i) {
		if (x - i < sm[i]) {
			++ x;
		}
		ans += x - 1 - m[i];
	}
	printf("%I64d\n", ans);
	return 0;
}