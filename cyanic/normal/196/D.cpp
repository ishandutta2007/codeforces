#include<bits/stdc++.h>
using namespace std;

const int maxn = 400005;
const int seed = 23333, MOD = 998244353;
int l[maxn], r[maxn], power[maxn], n, d, cur;
char s[maxn], res[maxn];

bool check(int L, int R) {
	return (l[R] - l[L-1] + MOD) % MOD != 1LL * (r[R] - 1LL * r[L-1] * power[R-L+1] % MOD + MOD) * power[L-1] % MOD;
}

int dfs(int k, int flag) {
	if (k == n + 1) return puts(res + 1), 1;
	for (int i=(flag?s[k]:'a'); i<='z'; i++) {
		l[k] = (l[k-1] + 1LL * i * power[k-1]) % MOD;
		r[k] = (1LL * seed * r[k-1] + i) % MOD;
		if (k < d || k == d && check(1, d) || check(k-d+1, k) && check(k-d, k)) {
			res[k] = i; if (dfs(k + 1, flag && i == s[k])) return 1;
		}
	}
	return 0;
}

int main() {
	scanf("%d%s", &d, s + 1); cur = n = strlen(s + 1); 
	while (cur && s[cur] == 'z') s[cur--] = 'a';
	if (!cur) return puts("Impossible"), 0; 
	s[cur]++; power[0] = 1; 
	for (int i=1; i<=n; i++) power[i] = 1LL * power[i-1] * seed % MOD;
	if (!dfs(1, 1)) puts("Impossible");
	return 0;
}