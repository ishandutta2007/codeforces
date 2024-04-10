#include <bits/stdc++.h>

using namespace std;

int query(int l, int r) {
	printf("? %d %d\n", l, r);
	fflush(stdout);
	int ret; scanf("%d", &ret);
	return ret;
}

int main() {
	int N; scanf("%d", &N);
	int x = query(1, N);
	bool lft = false;
	if(x != 1) {
		if(query(1, x) == x) lft = true;
	}

	if(lft) {
		int l = 1, r = x - 1;
		while(l <= r) {
			int m = l + r >> 1;
			if(query(m, x) == x) l = m + 1;
			else r = m - 1;
		}
		printf("! %d\n", r);
		fflush(stdout);
	}
	else {
		int l = x + 1, r = N;
		while(l <= r) {
			int m = l + r >> 1;
			if(query(x, m) == x) r = m - 1;
			else l = m + 1;
		}
		printf("! %d\n", l);
		fflush(stdout);
	}
	return 0;
}