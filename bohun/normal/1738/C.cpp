#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define cat(x) cout << #x << ": " << x << endl

using namespace std;
using ll = long long;

const int N = 105;
int n, a[N];

void solve() {
	cin >> n;
	int c0 = 0;
	int c1 = 0;
	rep(i, 1, n) {
		cin >> a[i];
		c0 += abs(a[i]) % 2 == 0;
		c1 += abs(a[i]) % 2 == 1;
	}

	c1 %= 4;
	c0 %= 2;

	bool bob = 0;
	bob |= c1 == 1 && c0 == 0;
	bob |= c1 == 2;

	cout << (bob ? "Bob\n" : "Alice\n");
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T;
	cin >> T;
	while (T--) solve();

	return 0;
}