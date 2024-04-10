#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define cat(x) cerr << #x << ": " << x << endl

using ll = long long;
using namespace std;

const int N = 1 << 20;
int n, m, col[N], add[N];
string t;

void solve() {
	cin >> n >> m >> t;
	rep(i, 0, m - 1) col[i] = add[i] = 0;

	ll s = 0, lst = -1e9;
	rep(i, 0, n * m - 1) {
		s += add[i % m];
		if (t[i] == '1') {
			if (++col[i % m] == 1) {
				s++;
			}
			int k = i - lst;
			if (k < m) {
				int b = i % m;
				int a = (i + m - k) % m;
				add[a]++;
				add[b]--;
			}
			else {
				s++;
			}
			lst = i;
		}
		cout << s << " ";
	}
	cout << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}