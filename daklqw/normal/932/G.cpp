#include <bits/stdc++.h>

const int MAXN = 1000010;
const int mod = 1000000007;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
int pow(int a, int b, int res = 1) {
	for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
	return res;
}
char buf[MAXN], S[MAXN];
int n;
int fail[MAXN], R[MAXN], tot, lst, at;
int f[MAXN], g[MAXN], slink[MAXN], diff[MAXN];
int nxt[MAXN][26];
int find(int x) {
	while (S[at] != S[at - R[x] - 1]) x = fail[x];
	return x;
}
void ins(int x) {
	int now = find(lst), & nt = nxt[now][x], v;
	if (!nt) {
		R[v = ++tot] = R[now] + 2;
		fail[v] = nxt[find(fail[now])][x];
		diff[v] = R[v] - R[fail[v]];
		slink[v] = diff[v] == diff[fail[v]] ? slink[fail[v]] : v;
		nt = v;
	}
	lst = nt;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> buf + 1; n = strlen(buf + 1);
	for (int i = 1; i * 2 <= n; ++i)
		S[i * 2 - 1] = buf[i], S[i * 2] = buf[n - i + 1];
	R[*f = fail[0] = tot = 1] = -1; diff[0] = -233;
	for (int i = 1; i <= n; ++i) {
		ins(S[at = i] - 'a');
		int now = lst;
		while (now) {
			g[now] = f[i - R[slink[now]]];
			if (slink[now] != now)
				reduce(g[now] += g[fail[now]] - mod);
			if (i % 2 == 0) reduce(f[i] += g[now] - mod);
			now = fail[slink[now]];
		}
	}
	std::cout << f[n] << std::endl;
	return 0;
}