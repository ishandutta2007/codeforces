#include <bits/stdc++.h>

using namespace std;

int N;
int A[202020];

int ans, cnt;

struct NODE {
	int x;
	int l, r;

	NODE() : x(0), l(0), r(0) {}
}T[32 * 202020];

int id = 1;

void add(int now, int b, int x) {
	if(b < 0) {
		T[now].x = 1;
		return;
	}
	if(x & (1 << b)) {
		if(!T[now].r) T[now].r = ++id;
		add(T[now].r, b - 1, x);
	}
	else {
		if(!T[now].l) T[now].l = ++id;
		add(T[now].l, b - 1, x);
	}

	T[now].x = T[T[now].l].x + T[T[now].r].x;
}

void query(int now, int b, int x) {
	if(b < 0) {
		cnt++;
		return;
	}
	if(x & (1 << b)) {
		if(T[now].x > T[T[now].r].x) cnt++;
		query(T[now].r, b - 1, x);
	}
	else {
		if(T[now].x > T[T[now].l].x) cnt++;
		query(T[now].l, b - 1, x);
	}
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
		add(1, 29, A[i]);
	}

	for(int i = 1; i <= N; i++) {
		cnt = 0;
		query(1, 29, A[i]);
		ans = max(ans, cnt);
	}
	printf("%d\n", N - ans);
	return 0;
}