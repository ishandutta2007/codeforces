#include <bits/stdc++.h>

const int MAXN = 131077;
typedef long long LL;

int A[MAXN], B[MAXN], pre[MAXN];
int n, m;
int ls[MAXN], rs[MAXN], ks[MAXN], ansl[MAXN];
void gmi(int & x, int y) { x > y ? x = y : 0; }
inline int calc(int l, int id) {
	int r = pre[rs[id]] - pre[l] + (ks[id] - rs[id] + l) * A[l];
	gmi(ansl[id], r);
	return r;
}
const int BLO = 32;
std::vector<int> qs[MAXN << 1];
void addq(int u, int l, int r, int L, int R, int id) {
	if (r - l + 1 <= BLO) {
		L = std::max(L, l), R = std::min(r, R);
		for (int i = L; i <= R; ++i) calc(i, id);
		return ;
	}
	if (L <= l && r <= R) {
		qs[u].push_back(id);
		return ;
	}
	int mid = l + r >> 1;
	if (L <= mid) addq(u << 1, l, mid, L, R, id);
	if (mid < R) addq(u << 1 | 1, mid + 1, r, L, R, id);
}
int st[MAXN], top;
void calcans(int id) {
	if (top == 1) calc(st[1], id);
	int l = 1, r = top - 1;
	while (l <= r) {
		int mid = l + r >> 1;
		int x = calc(st[mid], id);
		int y = calc(st[mid + 1], id);
		if (x < y) r = mid - 1;
		else l = mid + 1;
	}
}
bool judge(int x, int y, int z) {
	int x1 = A[y] - A[x], x2 = A[z] - A[x];
	int y1 = B[y] - B[x], y2 = B[z] - B[x];
	return (LL) x1 * y2 - (LL) y1 * x2 <= 0;
}
bool cmpa(int a, int b) {
	return A[a] == A[b] ? B[a] < B[b] : A[a] < A[b];
}
void solve(int u, int l, int r) {
	if (r - l + 1 <= BLO) return ;
	int mid = l + r >> 1;
	solve(u << 1, l, mid);
	solve(u << 1 | 1, mid + 1, r);
	if (qs[u].empty()) return ;
	static int rk[MAXN]; int bak = 0;
	for (int i = l; i <= r; ++i) rk[++bak] = i;
	std::sort(rk + 1, rk + 1 + bak, cmpa);
	top = 0;
	for (int i = 1; i <= bak; ++i) {
		while (top > 1 && judge(st[top - 1], st[top], rk[i]))
			--top;
		st[++top] = rk[i];
	}
	for (auto t : qs[u]) calcans(t);
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> A[i];
		pre[i] = pre[i - 1] + A[i];
		B[i] = i * A[i] - pre[i];
	}
	std::cin >> m;
	memset(ansl, 0x3f, sizeof ansl);
	for (int i = 1; i <= m; ++i) {
		std::cin >> ks[i] >> rs[i];
		ls[i] = rs[i] - ks[i] + 1;
		addq(1, 1, n, ls[i], rs[i], i);
	}
	solve(1, 1, n);
	for (int i = 1; i <= m; ++i)
		std::cout << ansl[i] << '\n';
	return 0;
}