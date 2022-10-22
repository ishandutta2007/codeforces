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
		int n;
		cin >> n;

		int s = 0;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			s += x;
		}

		cout << (s % n == 0 ? 0 : 1) << '\n';
	}

	return 0;
}