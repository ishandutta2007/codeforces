#include <bits/stdc++.h>

using namespace std;

int N;

int query(int w) {
	printf("? %d\n", w);
	fflush(stdout);
	int ret; scanf("%d", &ret);
	return ret;
}

int main() {
	scanf("%d", &N);
	int l = 1, r = N * 2001;
	while(l <= r) {
		int m = l + r >> 1;
		int t = query(m);
		if(t != 1) l = m + 1;
		else r = m - 1;
	}
	// l
	int ans = l;
	for(int i = 2; i <= N; i++) {
		int w = l / i;
		int t = query(w);
		if(t) ans = min(ans, t * w);
	}
	printf("! %d\n", ans);
	fflush(stdout);
	return 0;
}