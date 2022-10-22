#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;

int t, n, q;
string s;
int a[300300];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> t;
	while (t--) {
		cin >> n >> q >> s;
		rep(i, 0, n)
			a[i + 1] = a[i] + (i % 2 ? -1 : 1) * (s[i] == '+' ? 1 : -1);
		while (q--) {
			int l, r;
			cin >> l >> r;
			int s = a[r] - a[l - 1];
			cout << (s == 0 ? 0 : (s % 2 ? 1 : 2)) << '\n';
		}
	}
	return 0;
}