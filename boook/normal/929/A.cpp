#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		v.push_back(x);
	}

	for (int i = 0; i < v.size() - 1; i++) {
		if (v[i + 1] - v[i] > k) {
			puts("-1");
			return 0;
		}
	}

	int cnt = 1, now = v[1] - v[0];
	for (int i = 1; i < v.size() - 1; i++) {
		if (now + v[i + 1] - v[i] <= k) {
			now += v[i + 1] - v[i];
		} else {
			cnt++;
			now = v[i + 1] - v[i];
		}
	}

	printf("%d\n", cnt);
	return 0;
}