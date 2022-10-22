#include<bits/stdc++.h>

const int N = 19;
const int MAX = 1 << N;

int seg[MAX << 1];
int n, m;
int cnt[MAX];

void add(int sit, int value){
	seg[sit += MAX] += value;
	for (sit >>= 1 ; sit; sit >>= 1){
		seg[sit] = seg[sit << 1] + seg[sit << 1 | 1];
	}
}

int query(int x){
	int sit = 1;
	for (int i = N - 1; ~i; -- i){
		(sit <<= 1) |= x >> i & 1;
		if (!seg[sit]){
			sit ^= 1;
		}
	}
	return (sit - MAX) ^ x;
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0, x; i < n; ++ i){
		scanf("%d", &x);
		++ cnt[x];
	}
	for (int i = 0; i < MAX; ++ i){
		if (!cnt[i]){
			add(i, 1);
		}
	}
	int now = 0;
	while (m --){
		int x;
		scanf("%d", &x);
		printf("%d\n", query(now ^ x));
		now ^= x;
	}
	return 0;
}