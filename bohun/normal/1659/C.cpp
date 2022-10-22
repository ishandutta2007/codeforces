#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define cat(x) cout << #x << ": " << x << endl

using ll = long long;
using namespace std;

const int N = 200200;
int n;
ll a, b, x[N];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T;
	cin >> T;
	while (T--) {
		cin >> n >> a >> b;
		rep(i, 1, n) cin >> x[i];
		ll res = 2e18, s = 0;
		per(i, 0, n) {
			res = min(res, (a + b) * x[i] + b * (s - (n - i) * x[i]));
			s += x[i];
		}
		cout << res << "\n";
	}

	return 0;
}