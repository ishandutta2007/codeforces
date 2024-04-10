#include<bits/stdc++.h>
using namespace std;
#define MAXN	200005
#define MAXV	305
int n, opt[MAXN], value[MAXN], last[MAXV];
int cnt[MAXN];
bool mark[MAXN];
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> opt[i];
		if (opt[i] == 1 || opt[i] == 3) cin >> value[i];
	}
	for (int i = 1; i <= n; i++) {
		if (opt[i] == 3) last[value[i]] = i;
		if (opt[i] == 5) last[0] = i;
		if (opt[i] != 1 && opt[i] != 2) continue;
		if (opt[i] == 1) {
			int lft = last[0];
			for (int j = value[i]; j < MAXV; j++)
				lft = max(lft, last[j]);
			cnt[lft + 1]++; cnt[i]--;
			for (int j = i + 1; j <= n; j++) {
				if (opt[j] == 1) break;
				if (opt[j] == 3 && value[i] > value[j]) mark[j] = true;
			}
		} else {
			for (int j = i - 1; j >= 1; j--) {
				if (opt[j] == 2 || opt[j] == 4) break;
				if (opt[j] == 6) mark[j] = true;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cnt[i] += cnt[i - 1];
		if (opt[i] == 3 && cnt[i]) mark[i] = true;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans += mark[i];
	cout << ans << endl;
	return 0;
}