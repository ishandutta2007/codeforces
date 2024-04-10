#include <bits/stdc++.h>

using namespace std;

int N, K;

int rev(int x) {
	int ret = 0;
	while(x) {
		ret = ret * K + x % K;
		x /= K;
	}
	return ret;
}

int inv(int x) {
	int ret = 0;
	bool fg = false;
	int z = 0;
	while(x) {
		int t = x % K;
		if(t) fg = true;
		if(!fg) z++;
		ret = ret * K + (K - t) % K;
		x /= K;
	}
	ret = rev(ret);
	for(int i = 0; i < z; i++) ret *= K;
	return ret;
}

int add(int a, int b) {
	int ret = 0;
	bool fg = false;
	int z = 0;
	while(a || b) {
		int t = (a % K + b % K) % K;
		if(t) fg = true;
		if(!fg) z++;
		ret = ret * K + t;
		a /= K; b /= K;
	}
	ret = rev(ret);
	for(int i = 0; i < z; i++) ret *= K;
	return ret;
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &K);
		int x = 0;

		for(int i = 0; i < N; i++) {
			int t = add(x, (i & 1 ? inv(i) : i));
			printf("%d\n", t); fflush(stdout);
			int r; scanf("%d", &r);
			if(r == -1) return 0;
			if(r) break;
			x = add(t, inv(x));
		}
	}
	return 0;
}