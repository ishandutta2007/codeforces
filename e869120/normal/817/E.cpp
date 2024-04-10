#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
#pragma warning(disable:4996)
int q, a, b, c; map<int, int>M;
void add(int l, int r, int c, int x, int p) {
	if (!(l <= c && c < r))return;
	M[x] += p;
	if (r - l == 1)return;
	add(l, (l + r) / 2, c, x * 2, p);
	add((l + r) / 2, r, c, x * 2 + 1, p);
}
int sum(int l, int r, int b, int c, int x, int depth) {
	if (depth < 0)return 0;
	int ret = 0;
	if ((b&(1 << depth)) == 0) {
		if (c >= (1 << depth))ret += M[x * 2];
		else ret += sum(l, (l + r) / 2, b, c, x * 2, depth - 1);
	}
	else {
		if (c < (1 << depth))ret += 0;
		else ret += sum(l, (l + r) / 2, b, c - (1 << depth), x * 2, depth - 1);
	}
	if ((b&(1 << depth)) != 0) {
		if (c >= (1 << depth))ret += M[x * 2 + 1];
		else ret += sum((l + r) / 2, r, b, c, x * 2 + 1, depth - 1);
	}
	else {
		if (c < (1 << depth))ret += 0;
		else ret += sum((l + r) / 2, r, b, c - (1 << depth), x * 2 + 1, depth - 1);
	}
	return ret;
}
int main() {
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> a >> b; if (a == 3)cin >> c;
		if (a == 1)add(0, 1 << 27, b, 1, 1);
		if (a == 2)add(0, 1 << 27, b, 1, -1);
		if (a == 3)printf("%d\n", sum(0, 1 << 27, b, c, 1, 26));
	}
	return 0;
}