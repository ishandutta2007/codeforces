#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

int n;

std::vector<std::vector<int> > answer;

int query(int a, int b, int c, int d) {
	printf("? %d %d %d %d\n", a, b, c, d);
	fflush(stdout);
	int x;
	scanf("%d", &x);
	return x;
}

std::vector<int> get(int b, int l, int u, int r) {
	int lower = b, upper = u;
	while (lower < upper) {
		int mid = lower + upper + 1 >> 1;
		if (query(mid, l, u, r) == 1) {
			lower = mid;
		} else {
			upper = mid - 1;
		}
	}
	b = lower;
	lower = b, upper = u;
	while (lower < upper) {
		int mid = lower + upper >> 1;
		if (query(b, l, mid, r) == 1) {
			upper = mid;
		} else {
			lower = mid + 1;
		}
	}
	u = lower;
	lower = l, upper = r;
	while (lower < upper) {
		int mid = lower + upper + 1 >> 1;
		if (query(b, mid, u, r) == 1) {
			lower = mid;
		} else {
			upper = mid - 1;
		}
	}
	l = lower;
	lower = l, upper = r;
	while (lower < upper) {
		int mid = lower + upper >> 1;
		if (query(b, l, u, mid) == 1) {
			upper = mid;
		} else {
			lower = mid + 1;
		}
	}
	r = lower;
	return {b, l, u, r};
}

void finish() {
	printf("!");
	for (int i = 0; i < answer.size(); i++) {
		for (int j = 0; j < answer[i].size(); j++) {
			printf(" %d", answer[i][j]);
		}
	}
	puts("");
	fflush(stdout);
}

int main() {
	scanf("%d", &n);

	// horizon
	int l = 1, r = n;
	while (l < r) {
		int mid = l + r >> 1;
		int t = query(1, 1, mid, n);
		if (t == 0) {
			l = mid + 1;
		} else if (t >= 1) {
			r = mid;
		}
	}
	int split = l;
	if (query(1, 1, split, n) == 1 && query(split + 1, 1, n, n) == 1) {
		answer.push_back(get(1, 1, split, n));
		answer.push_back(get(split + 1, 1, n, n));
		finish();
		return 0;
	}

	//vertical
	l = 1, r = n;
	while (l < r) {
		int mid = l + r >> 1;
		int t = query(1, 1, n, mid);
		if (t == 0) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	split = l;
	assert(query(1, 1, n, split) == 1);
	answer.push_back(get(1, 1, n, split));
	answer.push_back(get(1, split + 1, n, n));
	finish();
	return 0;
}