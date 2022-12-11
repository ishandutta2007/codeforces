#include <bits/stdc++.h>

const int MAXN = 300010;
const int NINF = 0xcfcfcfcf;
int n, A[MAXN], at[MAXN], B[MAXN];
int ansl[MAXN];
struct mat {
	int A[2][2];
	friend mat operator * (mat a, mat b) {
		mat res;
		for (int i = 0; i != 2; ++i)
			for (int j = 0; j != 2; ++j)
				res.A[i][j] = std::max(a.A[i][0] + b.A[0][j], a.A[i][1] + b.A[1][j]);
		return res;
	}
} tree[MAXN << 3];
void mdf(int u, int l, int r, int tar, int v) {
	if (l == r) {
		tree[u].A[0][0] = v;
		tree[u].A[0][1] = tree[u].A[1][1] = 0;
		tree[u].A[1][0] = NINF;
		return ;
	}
	int mid = l + r >> 1;
	if (tar <= mid) mdf(u << 1, l, mid, tar, v);
	else mdf(u << 1 | 1, mid + 1, r, tar, v);
	tree[u] = tree[u << 1 | 1] * tree[u << 1];
}
bool can() {
	return std::max(tree[1].A[0][0], tree[1].A[0][1]) > 0;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i) std::cin >> A[i], at[A[i]] = i;
	for (int i = 1; i <= n; ++i) std::cin >> B[i];
	for (int i = 1; i <= n * 2; ++i) mdf(1, 1, n * 2, i, 0);
	int cur = 1, lst = 1;
	for (int i = n; i; --i) {
		mdf(1, 1, n * 2, at[i] * 2 - 1, 1);
		while (cur <= n && can()) {
			mdf(1, 1, n * 2, B[cur++] * 2, -1);
		}
		for (int j = lst; j < cur; ++j) ansl[j] = i;
		lst = cur;
	}
	for (int i = 1; i <= n; ++i) std::cout << ansl[i] << ' ';
	return 0;
}