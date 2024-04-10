#include <bits/stdc++.h>

const int MAXN = 300010;
const int INF = 0x3f3f3f3f;
typedef long long LL;
int pre[2][MAXN];
int n;
int A[MAXN], B[MAXN], C[MAXN];
void solve(int * A, int * B) {
	LL sm = 0; std::map<LL, int> at; at[0] = n + 1;
	for (int i = 1; i <= n + 1; ++i) B[i] = INF;
	for (int i = n; i; --i) {
		sm += A[i];
		if (at.count(sm)) B[i] = at[sm];
		at[sm] = i;
	}
	for (int i = n; i; --i) B[i] = std::min(B[i], B[i + 1]);
}
std::map<int, int> M[MAXN];
void gma(int & x, int y) { x < y ? x = y : 0; }
int calc(int a, int b) {
	if (M[a].count(b)) return M[a][b];
	int & res = M[a][b] = 0;
	if (A[a] < INF && A[a] <= B[b])
		gma(res, calc(A[a], b) + 1);
	if (B[b] < INF && B[b] <= A[a])
		gma(res, calc(a, B[b]) + 1);
	int t = std::max(a, b);
	if (C[t] < INF) gma(res, calc(C[t], C[t]) + 1);
	return res;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int j = 0; j < 2; ++j)
		for (int i = 1; i <= n; ++i)
			std::cin >> pre[j][i];
	solve(pre[0], A);
	solve(pre[1], B);
	for (int i = 1; i <= n; ++i) pre[0][i] += pre[1][i];
	solve(pre[0], C);
	std::cout << calc(1, 1) << std::endl;
	return 0;
}