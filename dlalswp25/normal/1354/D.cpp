#include <bits/stdc++.h>

using namespace std;

int N, Q;
int T[2121212];
int base = 1048576;

void init() {
	for(int i = base - 1; i >= 1; i--) T[i] = T[i << 1] + T[i << 1 | 1];
}

void upd(int p, int x) {
	p += base;
	p--;
	while(p) {
		T[p] += x;
		p >>= 1;
	}
}

void kth(int k) {
	k--;

	int p = 1;
	while(p < base) {
		if(k >= T[p << 1]) {
			k -= T[p << 1];
			p = p << 1 | 1;
		}
		else p = p << 1;
	}

	upd(p - base + 1, -1);
}

int main() {
	scanf("%d%d", &N, &Q);
	for(int i = 1; i <= N; i++) {
		int a; scanf("%d", &a);
		T[base + a - 1]++;
	}
	init();

	while(Q--) {
		int k; scanf("%d", &k);
		if(k > 0) {
			upd(k, 1);
		}
		else {
			kth(-k);
		}
	}

	for(int i = 1; i <= N; i++) {
		if(T[base + i - 1] > 0) { printf("%d\n", i); return 0; }
	}
	puts("0");
	return 0;
}