#include <bits/stdc++.h>
using namespace std;

int a[110000];
int b[110000];

int main() {
	ios::sync_with_stdio(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	long long ans = 0;
	for (int i = 1; i <= n; i++) ans += max(a[i], b[i]) + 1;
	cout << ans << endl;
	return 0;
}