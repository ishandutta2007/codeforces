#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define cat(x) cerr << #x << " = " << x << endl

using ll = long long;
using namespace std;

const int N = 120;
int t, n, a[N], b[N];
bitset<N * N> dp[N];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	dp[0][0] = 1;

	cin >> t;
	while (t--) {
		int s = 0;
		int s2 = 0;
		cin >> n;
		rep(i, 1, n) {
			cin >> a[i];
			s += a[i];
			s2 += a[i] * a[i];
		}
		rep(i, 1, n) {
			cin >> b[i];
			s += b[i];
			s2 += b[i] * b[i];
		}

		rep(i, 1, n)
			dp[i] = (dp[i - 1] << a[i]) | (dp[i - 1] << b[i]);

		per(i, 0, s / 2) {
			if (dp[n][i]) {
				int x = i;
				int y = s - i;
				cout << s2 * (n - 1) + (x * x + y * y - s2) << "\n";
				break;
			}
		}
	}

	return 0;
}