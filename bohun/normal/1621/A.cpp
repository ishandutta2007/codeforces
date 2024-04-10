#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, b, a) for (int i = b; i >= a; i--)
#define cat(x) cerr << #x << " = " << x << "\n";
using ll = long long;
using namespace std;

int n, k;

void solve() {
	cin >> n >> k;
	if (k > (n + 1) / 2) {
		cout << "-1\n";
		return;
	}
	rep(i, 1, n) {
		rep(j, 1, n) {
			if (i == j && i % 2 && k) {
				k--;
				cout << "R";
			}
			else 
				cout << ".";
		}
		cout << "\n";
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}