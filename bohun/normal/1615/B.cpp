#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; a <= i; i--)
#define cat(x) cerr << #x << " = " << x << '\n';
using ll = long long;
using namespace std;

const int N = 200200;

int cnt[N][20];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 20; j++) {
			cnt[i][j] = cnt[i - 1][j] + !(i >> j & 1);
		}
	}

	int t;
	cin >> t;
	
	while (t--) {
		int a, b;
		cin >> a >> b;

		int res = 1e9;
		for (int i = 0; i < 20; i++) {
			res = min(res, cnt[b][i] - cnt[a - 1][i]);
		}
		
		cout << res << '\n';
	}

	return 0;
}