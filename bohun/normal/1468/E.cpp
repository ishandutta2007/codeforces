#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--) {
		int a[4];
		cin >> a[0] >> a[1] >> a[2] >> a[3];
		sort(a, a + 4);
		cout << a[0] * a[2] << "\n";
	}

	return 0;
}