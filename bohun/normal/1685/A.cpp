#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define cat(x) cout << #x << ": " << x << endl
using ll = long long;
using namespace std;

int n, a[100100], b[100100];

void solve() {
	cin >> n;
	rep(i, 0, n - 1) cin >> a[i];
	sort(a, a + n);
	reverse(a, a + n);
	int j = 0;
	rep(i, 0, n - 1) {
		b[j] = a[i];
		j += 2;
		if (j == n) j = 1;
	}
	rep(i, 0, n - 1) {
		int x = (i - 1 + n) % n;
		int y = (i + 1) % n;
		if (b[i] > b[x] && b[i] > b[y]) ;
		else if (b[i] < b[x] && b[i] < b[y]) ;
		else {
			cout << "NO\n";
			return;
		}
	}

	cout << "YES\n";
	rep(i, 0, n - 1) cout << b[i] << " ";
	cout << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T;
	cin >> T;
	while (T--) solve();

	return 0;
}