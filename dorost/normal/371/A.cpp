/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1000, M = 3;
int a[N], cnt[N][M];

int32_t main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[i % k][a[i]]++;
	}
	int ans = 0;
	for (int i = 0; i < k; i++) {
		ans += min(cnt[i][1], cnt[i][2]);
	}
	cout << ans;
}