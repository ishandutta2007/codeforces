#include <bits/stdc++.h>

const int MAXN = 300010;
int A[MAXN], B[MAXN], n;
std::vector<int> ta, tb;
int ans, ansl[MAXN];
int cmp(int a, int b) {
	return B[a] > B[b];
}
int tl[MAXN];
void solve(std::vector<int> li) {
	std::sort(li.begin(), li.end(), cmp);
	int up = 0x3f3f3f3f, bak = 0;
	for (int i : li) {
		if (A[i] < up) up = B[i], tl[++bak] = i;
	}
	if (bak > ans) ans = bak, memcpy(ansl, tl, bak + 1 << 2);
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", A + i, B + i);
		if (A[i] < B[i]) ta.push_back(i);
		else A[i] = -A[i], B[i] = -B[i], tb.push_back(i);
	}
	solve(ta); solve(tb);
	printf("%d\n", ans);
	for (int i = 1; i <= ans; ++i) printf("%d%c", ansl[i], " \n"[i == ans]);
	return 0;
}