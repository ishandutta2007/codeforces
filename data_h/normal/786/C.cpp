#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;
const int B = 200;

int n, a[N];
int cnt[N][N / B], tcnt[N], diff[N / B];
int tot, l[N / B], r[N / B];
int ans[N];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int k = 1; k <= n && k <= B; k++) {
		int cur = 0;
		static vector<int> pos;
		pos.clear();
		ans[k] = 1;
		for (int i = 0; i < n; i++) {
			if (tcnt[a[i]] == 0) ++cur;
			if (cur > k) {
				ans[k]++;
				cur = 1;
				for (auto p : pos) tcnt[p] = 0;
				pos.clear();
			}
			tcnt[a[i]]++;
			pos.push_back(a[i]);
		}
		for (auto p : pos) tcnt[p] = 0;
	}
	tot = 0;
	for (int k = B; k <= B && k <= n; k++) {
		l[tot] = 0;
		for (int i = 0; i < n; i++) {
			if (cnt[a[i]][tot] == 0) ++diff[tot];
			if (diff[tot] > k) {
				diff[tot]--;
				r[tot] = i - 1;
				l[++tot] = i;
				diff[tot] = 1;
			}
			cnt[a[i]][tot]++;
		}
		r[tot] = n - 1;
	}
	for (int k = B + 1; k <= n; k++) {
		for (int i = 0; i <= tot; i++) {
			// move l
			while (i > 0 && l[i] <= r[i - 1] && l[i] <= r[i]) {
				if (--cnt[a[l[i]]][i] == 0) {
					diff[i]--;
				}
				l[i]++;
			}
			if (l[i] > r[i]) {
				assert(i);
				if (r[i - 1] == n - 1) {
					tot = i - 1;
					break;
				}
				l[i] = r[i - 1] + 1;
				r[i] = r[i - 1];
			}
			while (r[i] + 1 < n && diff[i] <= k) {
				++r[i];
				if (cnt[a[r[i]]][i] == 0) ++ diff[i];
				if (diff[i] > k) {
					diff[i]--;
					r[i]--;
					break;
				}
				++cnt[a[r[i]]][i];
			}
		}
		ans[k] = tot + 1;
	}
	for (int i = 1; i <= n; i++) {
		printf("%d%c", ans[i], i == n ? '\n' : ' ');
	}
	return 0;
}