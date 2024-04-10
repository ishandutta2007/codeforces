#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; a <= i; i--)
#define cat(x) cerr << #x << " = " << x << '\n';
using ll = long long;
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--) {
		int a[3];
		cin >> a[0] >> a[1] >> a[2];
		sort(a, a + 3);
		if (a[0] + a[1] == a[2] || ((a[0] == a[1] || a[1] == a[2]) && (a[0] + a[1] + a[2]) % 2 == 0))
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}