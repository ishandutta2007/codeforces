#include <bits/stdc++.h>

const int MAXN = 100010;
int lg[MAXN], n, A[MAXN];
int L[17][MAXN], R[17][MAXN];
int SSL[16][17][MAXN], SSR[16][17][MAXN];
int (*SL)[MAXN], (*SR)[MAXN];
int nowST;
void setst(int i) {
	nowST = i, SL = SSL[i], SR = SSR[i];
}
int qryl(int l, int r) {
	if (nowST == 16) {
		assert(l == r);
		return L[16][l];
	}
	if (l <= 0)
		return std::max(std::min(qryl(l + n, n) - n, qryl(1, r)), 1 - n);
	if (r > n)
		return std::max(std::min(qryl(1, r - n) + n, qryl(l, n)), 1 - n);
	const int L = lg[r - l + 1];
	return std::min(SL[L][l], SL[L][r - (1 << L) + 1]);
}
int qryr(int l, int r) {
	if (nowST == 16) {
		assert(l == r);
		return R[16][l];
	}
	if (l <= 0)
		return std::min(std::max(qryr(l + n, n) - n, qryr(1, r)), n * 2);
	if (r > n)
		return std::min(std::max(qryr(1, r - n) + n, qryr(l, n)), n * 2);
	const int L = lg[r - l + 1];
	return std::max(SR[L][l], SR[L][r - (1 << L) + 1]);
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	if (n == 1) return std::cout << 0 << std::endl, 0;
	lg[0] = -1;
	for (int i = 1; i <= n; ++i)
		std::cin >> A[i], lg[i] = lg[i >> 1] + 1;
	for (int i = 1; i <= n; ++i) L[0][i] = i - A[i], R[0][i] = i + A[i];
	for (int i = 1; i != 17; ++i) {
		setst(i - 1);
		for (int j = 1; j <= n; ++j)
			SL[0][j] = L[i - 1][j], SR[0][j] = R[i - 1][j];
		for (int j = 1; j != 17; ++j)
			for (int k = 1; k + (1 << j) - 1 <= n; ++k) {
				SL[j][k] = std::min(SL[j - 1][k], SL[j - 1][k + (1 << j - 1)]);
				SR[j][k] = std::max(SR[j - 1][k], SR[j - 1][k + (1 << j - 1)]);
			}
		for (int j = 1; j <= n; ++j) {
			L[i][j] = qryl(L[i - 1][j], R[i - 1][j]);
			R[i][j] = qryr(L[i - 1][j], R[i - 1][j]);
		}
	}
	for (int i = 1; i <= n; ++i) {
		int l = i, r = i, ans = 0;
		for (int j = 16; ~j; --j) {
			setst(j);
			int nl = qryl(l, r);
			int nr = qryr(l, r);
			if (nr - nl + 1 < n)
				l = nl, r = nr, ans |= 1 << j;
		}
		std::cout << ans + 1 << ' ';
	}
	return 0;
}