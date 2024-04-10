#include <bits/stdc++.h>
using namespace std;

const int N = 220000;

int a[N], b[N];

long long solve(int n, int m) {
	sort(b, b + n, greater<int>());
	long long ret = 0;
	for (int i = 0; i < m && i < n; i++) ret += b[i];
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	string s; cin >> s;
	long long ans = 0;
	for (int i = 0, j; i < n; i = j) {
		for (j = i; j < n && s[i] == s[j]; j++);
		for (int k = i; k < j; k++) b[k-i] = a[k];
		ans += solve(j - i, m);
	}
	cout << ans << endl;
	return 0;
}