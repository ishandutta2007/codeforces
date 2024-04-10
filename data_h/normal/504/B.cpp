#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

const int N = 2e5 + 10;

int a[N];
int n, p[N], bits[N];

inline int lowbit(int x) {
	return x & (-x);
}

int ask(int pos) {
	int s = 0;
	for(int i = pos; i; i -= lowbit(i)) {
		s += bits[i];
	}
	return s;
}

void ins(int pos) {
	for(int i = pos; i <= n; i += lowbit(i)) {
		bits[i] ++;
	}
}

void scan(int p[], int a[], int n) {
	fill(bits + 1, bits + n + 1, 0);
	for(int i = 0; i < n; i++) {
		++p[i];
		int rank = p[i] - ask(p[i]);
		a[i] += rank - 1;
		ins(p[i]);
	}
}

void print(int a[], int n) {
	fill(bits + 1, bits + n + 1, 0);
	for(int i = 0; i < n; i++) {
		int l = 1, r = n;
		while(l < r) {
			int mid = (l + r) / 2;
			if (mid - ask(mid) < a[i] + 1) {
				l = mid + 1;
			} else {
				r = mid;
			}
		}
		printf("%d%c", l - 1, i == n - 1 ? '\n' : ' ');
		ins(l);
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
	}
	scan(p, a, n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
	}
	scan(p, a, n);
/*	
	for(int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
*/
	for(int i = n - 1; i >= 0; i--) {
		int v = n - i;
		if (i > 0) {
			if (a[i] >= v) {
				a[i - 1]++;
			}
		}
		a[i] %= v;
	}
	print(a, n);
	return 0;
}