#include <bits/stdc++.h>

using namespace std;

int N, K, Q;
char S[262626];

struct Node {
	int sum, v, x;
}T[525252];

void init() {
	for(int i = N; i < N << 1; i++) {
		T[i].sum = T[i].x = T[i].v = 1;
	}
	for(int i = N - 1; i >= 1; i--) {
		T[i].sum = T[i].x = T[i << 1].sum + T[i << 1 | 1].sum;
		T[i].v = 1;
	}
}

void upd(int p, int t) {
	if(t == 1) { T[p].v = 1; T[p].x = T[p].sum; }
	else { T[p].v = 0; T[p].x = 0; }
	while(p > 1) {
		p >>= 1;
		T[p].sum = T[p << 1].x + T[p << 1 | 1].x;
		if(T[p].v) T[p].x = T[p].sum;
		else T[p].x = 0;
	}
}

int main() {
	scanf("%d", &K);
	N = 1 << K;
	init();
	scanf("%s", S + 1);
	for(int i = 1; i < N; i++) {
		int t = N - i;
		if(S[i] == '0') upd(t << 1, 0);
		else if(S[i] == '1') upd(t << 1 | 1, 0);
	}
	scanf("%d", &Q);
	while(Q--) {
		int p; char c;
		scanf("%d %c", &p, &c);
		int t = N - p;
		if(S[p] == '0') upd(t << 1, 1);
		else if(S[p] == '1') upd(t << 1 | 1, 1);
		S[p] = c;
		if(S[p] == '0') upd(t << 1, 0);
		else if(S[p] == '1') upd(t << 1 | 1, 0);
		printf("%d\n", T[1].x);
	}

	return 0;
}