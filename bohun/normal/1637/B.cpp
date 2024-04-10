#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define cat(x) cerr << #x << " = " << x << endl

using ll = long long;
using namespace std;

int t, n, a[20000];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> t;
	while (t--) {
		cin >> n;
		int res = 0;
		rep(i, 1, n) {
			cin >> a[i];
			res += (1 + (a[i] == 0)) * i * (n - i + 1);
		}
		cout << res << "\n";
	}

	return 0;
}