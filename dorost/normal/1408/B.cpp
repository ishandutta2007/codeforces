/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 102;
int a[N], cnt[N];

void solve() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < N; i++)
		cnt[i] = 0;
	for (int i = 0; i < n; i++) {  
		cin >> a[i];
		cnt[a[i]]++;
	}
	int num = 0;
	vector <int> v;
	for (int i = 0; i < N; i++)
		if (cnt[i])
			num++, v.push_back(i);
	for (int i = 0; i < num; i++) 
		a[i] = i;
	n = num;
	for (int m = 1; m < N; m++) {
		int b[n][m] = {};
		bool f = true;
		for (int i = 0; i < n; i++) {
			int x = a[i] / m, y = a[i] % m;
			for (int j = 0; j < m; j++) {
				b[i][j] = x + (j < y);
			}
		}
		for (int i = 0; i < m; i++) {
			int cnt2[N] = {};
			for (int j = 0; j < n; j++) {
				cnt2[b[j][i]]++;
			}
			int all = 0;
			for (int j = 0; j < N; j++)
				if (cnt2[j])
					all++;
			if (all > k) {
				f = false;
				break;
			}
		}
		if (f) {
			cout << m << ' ';
			return;
		}
	}
	cout << -1 << ' ';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}