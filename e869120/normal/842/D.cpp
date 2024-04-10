#include<iostream>
using namespace std;
#pragma warning(disable:4996)
int n, m, a[400000], p[1 << 19], c;
int sum(int l, int r) {
	int G = p[r - 1]; if (l >= 1)G -= p[l - 1];
	return G;
}
int mex() {
	int Y = 0, K = 0;
	for (int i = 0; i < 19; i++) {
		int F = (c / (1 << (18 - i))) % 2; K += (1 << (18 - i))*F;
		if (sum((Y ^ K), (Y ^ K) + (1 << (18 - i))) == (1 << (18 - i)))Y += (1 << (18 - i));
	}
	return Y;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) { scanf("%d", &a[i]); p[a[i]] = 1; }
	for (int i = 1; i < 524288; i++)p[i] += p[i - 1];
	for (int i = 0; i < m; i++) {
		int q; scanf("%d", &q); c ^= q;
		printf("%d\n", mex());
	}
	return 0;
}