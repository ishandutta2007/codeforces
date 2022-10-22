/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 501234;
int cnt[N], cnt2[N], a[N], ans[N];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int m, k, n, s;
	cin >> m >> k >> n >> s;
	for (int i = 0; i < m; i++)
		cin >> a[i];
	set <int> st;
	for (int i = 0; i < s; i++) {
		int x;
		cin >> x;
		cnt[x]++;
		st.insert(x);
	}
	ans[0] = INT_MAX;
	for (int i = 0; i < m; i++) {
		cnt2[a[i]]++;
		if (cnt2[a[i]] >= cnt[a[i]])
			st.erase(a[i]);
		if (st.empty()) {
			ans[0] = i;
			break;
		}
	}
	if (ans[0] == INT_MAX) {
		cout << -1;
		return 0;
	}
	for (int i = 1; i < m; i++) {
		if (ans[i - 1] == 2 * m) {
			ans[i] = 2 * m;
			continue;
		}
		cnt2[a[i - 1]]--;
		if (cnt[a[i - 1]] <= cnt2[a[i - 1]]) {
			ans[i] = ans[i - 1];
			continue;
		}
		for (int j = ans[i - 1] + 1; j < m; j++) {
			cnt2[a[j]]++;
			if (cnt[a[i - 1]] <= cnt2[a[i - 1]]) {
				ans[i] = j;
				break;
			}
		}
		if (cnt[a[i - 1]] > cnt2[a[i - 1]]) 
			ans[i] = 2 * m;
//		cout << i << ' ' << ans[i] << '\n';
	}
	for (int i = 0; i < N; i++)
		cnt2[i] = 0;
	for (int i = 0; i < m; i++) {
		ans[i] = ans[i] - i + 1;
		ans[i] -= k;
		ans[i] = max(0, ans[i]);
		if (ans[i] + i % k <= (m - n * k)) {
			cout << ans[i] + i % k << '\n';
			int cntt = ans[i] + i % k;
			for (int j = 1; j <= i % k; j++) {
				cout << j << ' ';
				cntt--;
			}
			for (int j = i; j < i + ans[i] + k; j++) {
				if (cntt == 0) 
					break;
				cnt2[a[j]]++;
				if (cnt2[a[j]] > cnt[a[j]]) {
					cout << j + 1 << ' ';
					cntt--;
				}
			}
			return 0;
		}
	}
	cout << -1;
}