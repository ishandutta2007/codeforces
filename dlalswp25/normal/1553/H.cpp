#include <bits/stdc++.h>

using namespace std;

const int INF = 1010101010;

int N, K;
int A[1010101];
int ans[1010101];
int base;

struct Node {
	int lft = INF, rgt = INF, mn = INF;
}T[1050505];

void upd(int idx, int h, bool inv) {
	int lnode = (inv ? idx << 1 | 1 : idx << 1);
	int rnode = (inv ? idx << 1 : idx << 1 | 1);

	T[idx].lft = min(T[lnode].lft, (1 << h) + T[rnode].lft);
	T[idx].rgt = min(T[rnode].rgt, (1 << h) + T[lnode].rgt);
	T[idx].mn = min(min(T[rnode].mn, T[lnode].mn), T[lnode].rgt + T[rnode].lft + 1);
}

void f(int h, int x) {
	if(h >= K) {
		ans[x] = T[1].mn;
		return;
	}
	int t = K - h - 1;
	for(int i = 1 << t; i < 1 << t + 1; i++) upd(i, h, false);
	f(h + 1, x);
	for(int i = 1 << t; i < 1 << t + 1; i++) upd(i, h, true);
	f(h + 1, x | 1 << h);
	for(int i = 1 << t; i < 1 << t + 1; i++) upd(i, h, false);
}

int main() {
	scanf("%d%d", &N, &K);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);

	base = 1 << K;
	for(int i = 1; i <= N; i++) {
		T[base + A[i]].lft = 0;
		T[base + A[i]].rgt = 0;
	}

	for(int i = K - 1; i >= 0; i--) {
		for(int j = 1 << i; j < 1 << i + 1; j++) {
			upd(j, K - i - 1, false);
			// printf("%d %d %d %d\n", j, T[j].lft, T[j].rgt, T[j].mn);
		}
	}

	f(0, 0);
	for(int i = 0; i < 1 << K; i++) printf("%d ", ans[i]); puts("");

	return 0;
}