#include <bits/stdc++.h>
using namespace std;

#define rep(i, l, r) for (int i = l; i <= r; i++)

const int N = 200005;
char a[N];
int w[N], heap[N], n, k, cnt;
long long ans;

void read(int &x) {
	x = 0; int f = 1;
	char op = getchar();
	while (!isdigit(op)) {
		if (op == '-') f = -1;
		op = getchar();
	}
	while (isdigit(op)) {
		x = 10 * x + op - '0';
		op = getchar();
	}
	x *= f;
}

void read(char &x) {
	x = getchar();
	while (x < 'a' || x > 'z') x = getchar();
}

//  
void up(int u) {
	int fa = u >> 1;
	if (fa > 0 && heap[fa] < heap[u]) {
		swap(heap[fa], heap[u]);
		up(fa);
	}
}

void down(int u) {
	int son = u << 1;
	if (son <= cnt) {
		if (son < cnt && heap[son] < heap[son + 1]) son++;
		if (heap[u] < heap[son]) {
			swap(heap[u], heap[son]);
			down(son);
		}
	}
}

int main() {
	read(n), read(k);
	rep(i, 1, n) read(w[i]);
	rep(i, 1, n) read(a[i]);
	rep(i, 1, n) {
		int j = i;
		while (j < n && a[j + 1] == a[i]) j++;
		// [i, j]
		if (j - i + 1 <= k) {
			rep(_, i, j) ans += w[_];
			i = j;
			continue;
		}
		cnt = 0;
		rep(_, i, j) {
			heap[++cnt] = w[_];
			up(cnt);
		}
		rep(_, 1, k) {
			ans += heap[1];
			heap[1] = heap[cnt--];
			down(1);
		}
		i = j;
	}
	printf("%lld\n", ans);
	return 0;
}