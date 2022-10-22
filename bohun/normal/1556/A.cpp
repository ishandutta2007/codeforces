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
		int a, b;
		cin >> a >> b;
		if ((a + b) % 2)
			cout << -1 << '\n';
		else if (a == b)
			cout << (a > 0) << '\n';
		else
			cout << 2 << '\n';
	}
	return 0;
}