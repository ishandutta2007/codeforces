#include<bits/stdc++.h>
using namespace std;
const int N = 300000+10;
int v[N], dp[N];

int main() {
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i ++) scanf("%d", &v[i]);
	sort(v + 1, v + n + 1);
	int st = 0, en = 1e9;
	while (st < en) {
		int md = st + en >> 1;
		dp[0] = 1;
		for (int i = 1; i <= n; i ++) {
			dp[i] = dp[i - 1];
			int L = lower_bound(v + 1, v + n + 1, v[i] - md) - v - 1;
			int R = i - k;
			if (R >= L && dp[R] > (L ? dp[L - 1] : 0)) dp[i]++;
		}
		if (dp[n] == dp[n - 1]) st = md + 1;
		else en = md;
	}
	cout << st << endl;
	return 0;
}