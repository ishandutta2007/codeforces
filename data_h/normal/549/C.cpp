#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 2e5 + 7;

int n, k;
int a[N];
int cnt[N];
int total = 0;

void solve(int total) {
	if (total == 1) {
		puts("Stannis");
	} else {
		puts("Daenerys");
	}
	exit(0);
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		cnt[a[i] & 1]++;
	}
	total = (cnt[1] & 1);
	k = n - k;

	if (k == 0) {
		solve(total);
	}
	
	if (k & 1) {
		if (k / 2 >= cnt[1]) {
			solve(0);
		}
		if (k / 2 >= cnt[0] && (total ^ ( (k - cnt[0]) & 1) ) == 0) {
			solve(0);
		}
		solve(1);
	} else {
		if (k / 2 >= cnt[0] && (total ^ ( (k - cnt[0]) & 1) ) == 1) {
			solve(1);
		}
		solve(0);
	}
	return 0;
}