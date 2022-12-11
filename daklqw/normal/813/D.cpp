#include <bits/stdc++.h>

const int MAXN = 5010;
int A[MAXN], li[MAXN], bak, md[MAXN];
int n, dp[MAXN][MAXN];
int to[100010];
void gma(int & x, int y) { x < y ? x = y : 0; }
int ls[MAXN * 10], rs[MAXN * 10], vs[MAXN * 10], cnt;
void gma(int a, int b, int v) {
	++cnt;
	ls[cnt] = a, rs[cnt] = b, vs[cnt] = v;
}
int tb[MAXN][7], Ans;
void push() {
	for (int i = 1; i <= cnt; ++i) {
		gma(dp[ls[i]][rs[i]], vs[i]);
		gma(tb[ls[i]][md[rs[i]]], vs[i]);
		gma(dp[rs[i]][ls[i]], vs[i]);
		gma(tb[rs[i]][md[ls[i]]], vs[i]);
		gma(Ans, vs[i]);
	}
	cnt = 0;
}
int pre[MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i) std::cin >> A[i];
	std::copy(A + 1, A + 1 + n, li + 1);
	std::sort(li + 1, li + 1 + n);
	bak = std::unique(li + 1, li + 1 + n) - li - 1;
	for (int i = 1; i <= bak; ++i) to[li[i]] = i;
	for (int i = 1; i <= n; ++i)
		md[to[A[i]]] = A[i] % 7, A[i] = to[A[i]];
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= bak; ++j) if (pre[j])
			gma(A[i], j, pre[j] + 1);
		for (int j = 1; j <= bak; ++j) {
			int v = dp[to[li[A[i]] - 1]][j] + 1;
			v = std::max(dp[to[li[A[i]] + 1]][j] + 1, v);
			v = std::max(tb[j][md[A[i]]] + 1, v);
			gma(A[i], j, v);
		}
		push();
		++pre[A[i]];
		for (int j = 1; j <= bak; ++j) if (j != A[i])
			if (std::abs(li[j] - li[A[i]]) == 1 || md[A[i]] == md[j])
				gma(pre[A[i]], pre[j] + 1);
	}
	std::cout << Ans << std::endl;
	return 0;
}