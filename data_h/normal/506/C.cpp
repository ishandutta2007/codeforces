#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

const int N = 111111;

priority_queue<pair<long long, int> > q;

long long need[N], cut[N], times[N];

vector<pair<int, int> > vecs;
int n, m, k, p, h[N], a[N], here[N];

bool solve(long long limit) {
	long long total = 0;
	for(int i = 1; i <= n; i++) {
		if (a[i] > limit) {
			return false;
		}
		times[i] = max(0LL, (h[i] + 1LL * a[i] * m - limit + p - 1) / p);
		total += times[i];
	}
	if (total > k * m) {
		return false;
	}
	
	for(int i = 1; i <= m; i++) {
		here[i] = 0;
	}

	for(int i = 1; i <= n; i++) {
		long long cur = limit;
		int added = 0;
		while(cur + 1LL * added * p - 1LL * m * a[i] < 0) {
			long long day = (cur + 1LL * added * p) / a[i];
			here[day]++;
			added++;
		}
		while(cur + 1LL * added * p - 1LL * m * a[i] < h[i]) {
			added++;
			here[m]++;
		}
	}

	int active = 0;
	for(int i = 1; i <= m; i++) {
		active += k;
		if ((active -= here[i]) < 0) {
			return false;
		}
	}
	return true;
}

int main() {
	scanf("%d %d %d %d", &n, &m, &k, &p);
	for(int i = 1; i <= n; i++) {
		scanf("%d %d", &h[i], &a[i]);
	}

	long long l = 0, r = 1e16;
	while(l < r) {
		long long mid = (l + r) >> 1;
		if (solve(mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	cout << l << endl;
	
	return 0;
}