#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

const int N = 1e5 + 7;

int cnt[N], a[N];
int n;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		cnt[x]++;
	}
	for (int i = 2; i < N; i++) {
		for (int j = i + i; j < N; j += i) {
			cnt[i] += cnt[j];
		}
	}
	int ans = 1;
	for (int i = 2; i < N; i++) {
		ans = max(ans, cnt[i]);
	}
	printf("%d\n", ans);
	return 0;
}