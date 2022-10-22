#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define sz(x) int(x.size())
#define cat(x) cerr << #x << " = " << x << endl

using ll = long long;
using namespace std;

int T, n, a[200200];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> T;
	while (T--) {
		cin >> n;
		rep(i, 0, n - 1) a[i] = i;
		per(i, 0, n - 1)
			if (__builtin_popcount(i) == 1) {
				reverse(a, a + i);
				break;
			}
		rep(i, 0, n - 1) cout << a[i] << " "; cout << endl;
	}

	return 0;
}