#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
typedef long long ll;
using namespace std;
int n, a[100005], b[100005];
int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int i = 1; i <= n; i++) {
			cin >> b[i];
			b[i] += b[i - 1];
		}
		int res = 1e9, s = 0;
		for (int i = n; 1 <= i; i--) {
			res = min(res, max(b[i - 1], s));
			s += a[i];
		}
		cout << res << "\n";
	}
	return 0;
}