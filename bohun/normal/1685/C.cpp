#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define cat(x) cout << #x << ": " << x << endl
using ll = long long;
using namespace std;

const int N = 200200;

int n, b[N];
char s[N];

void solve() {
	cin >> n >> s + 1;
	n *= 2;
	int fi = -1, la = -1;
	rep(i, 1, n) {
		b[i] = b[i - 1] + (s[i] == '(' ? 1 : -1);
		if (b[i] < 0) {
			if (fi == -1) fi = i;
			la = i;
		}
	}

	if (fi == -1) {
		cout << "0\n";
		return;
	}

	int mx = 0;
	rep(i, fi, la) mx = max(mx, b[i]);

	pair<int, int> up = {0, fi - 1};
	per(i, 0, fi - 1) {
		if (b[i] < 0) break;
		up = max(up, {b[i], i});
	}

	pair<int, int> up2 = {0, la + 1};
	rep(i, la + 1, n) {
		if (b[i] < 0) break;
		up2 = max(up2, {b[i], i});
	}

	// cat(fi);
	// cat(la);
	// cat(mx);
	// cat(up.first);
	// cat(up.second);

	if (up.first + up2.first >= mx) {
		cout << "1\n";
		cout << up.second + 1 << " " << up2.second << "\n";
		return;
	}

	pair<int, int> big = {0, 0};
	rep(i, 1, n) big = max(big, {abs(b[i]), i});

	int L = big.second;
	int R = big.second;
	
	while (b[L] != 0) L--;
	while (b[R] != 0) R++;

	cout << "2\n";
	if (b[big.second] < 0) {
		cout << "1 " << R << "\n";
		cout << R - big.second + 1 << " " << n << "\n";
	}
	else {
		cout << 1 << " " << big.second << "\n";
		cout << big.second + 1 << " " << n << "\n";
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T;
	cin >> T;
	while (T--) solve();

	return 0;
}