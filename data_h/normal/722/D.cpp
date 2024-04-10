#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <set>
#include <queue>

using namespace std;

const int N = 50000;

int n;
int a[N];
set<int> s;

bool solve(int limit) {
	priority_queue<int> q;
	s.clear();
	for (int i = 0; i < n; i++) {
		q.push(a[i]);
	}
	while (!q.empty()) {
		int x = q.top();
		q.pop();
		if (x <= limit) {
			if (!s.count(x)) {
				s.insert(x);
				continue;
			}
		}
		if (x == 1) return false;
		q.push(x / 2);
	}
	return true;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int l = 1, r = 2e9 + 7;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (solve(mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	solve(l);
	for (auto x : s) {
		printf("%d ", x);
	}
	puts("");
	return 0;
}