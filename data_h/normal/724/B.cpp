#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

const int N = 22;

int a[N][N], b[N];
int n, m;

int go(int a[], int b[]) {
	int l = 0, r = m - 1;
	while (l <= r && a[l] == b[l]) l++;
	while (l <= r && a[r] == b[r]) r--;
	if (l > r) return true;
	if (a[l] != b[r] || a[r] != b[l]) return false;
	l++; r--;
	for (int i = l; i <= r; i++) {
		if (a[i] != b[i]) {
			return false;
		}
	}
	return true;
}

bool test(int l, int r) {
	for (int i = 0; i < n; i++) {
		//printf("i = %d\n", i);
		bool sat = false;
		swap(a[i][l], a[i][r]);
		sat |= go(a[i], b);
		swap(a[i][l], a[i][r]);
		swap(b[l], b[r]);
		sat |= go(a[i], b);
		swap(b[l], b[r]);
		if (!sat) {
			return false;
		}
	}
	return true;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
			a[i][j]--;
		}
	}
	for (int j = 0; j < m; j++) b[j] = j;
	//test(1, 2);

	bool succ = test(0, 0);
	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j < m; j++) {
			succ |= test(i, j);
		}
	}
	if (succ) {
		puts("YES");
	} else {
		puts("NO");
	}
	return 0;
}