#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define sz(x) int(x.size())
#define cat(x) cerr << #x << " = " << x << endl

using ll = long long;
using namespace std;

const int N = 200200;

int t, n, k, a[N], cnt[N];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> t;
	while (t--) {
		cin >> n >> k;
		rep(i, 1, n) cnt[i] = 0;
		rep(i, 1, n) cin >> a[i], cnt[a[i]]++;
		int x = 0, y = n + 1;
		int j = 1, s = 0;
		rep(i, 1, n) {
			while (j <= n && 2 * s - n < k) {
				s += cnt[j++];
			}
			if (2 * s - n < k)
				break;
			if (j - 1 - i <= y - x) {
				x = i;
				y = j - 1;
			}
			s -= cnt[i];
		}
		cout << x << " " << y << endl;
		int L = 1;
		s = 0;
		rep(i, 1, n) {
			s += (x <= a[i] && a[i] <= y ? 1 : -1);
			if ((s == 1 && k > 1) || i == n) {
				cout << L << " " << i << endl;
				L = i + 1;
				k--;
				s = 0;
			}
		}
	}

	return 0;
}