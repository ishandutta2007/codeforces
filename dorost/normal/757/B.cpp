/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int a[N], cnt[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	int mx = 1;
	for (int i = 2; i < N; i++) {
		int x = 0;
		for (int j = i; j < N; j += i) {
			x += cnt[j];
		}
		mx = max(mx, x);
	}
	cout << mx;
}

int32_t main() {
	solve();
}