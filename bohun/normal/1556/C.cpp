#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;

int n;
ll c[1010], res;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n;
	rep(i, 0, n) {
		cin >> c[i];
		if (i % 2 == 1)
			c[i] *= -1;
	}

	for (int i = 0; i < n; i += 2) {
		ll s = 0;
		ll pick = 0;

		for (int j = i + 1; j < n; j += 2) {

			ll A = c[i];
			ll B = -c[j];
			ll S = s;
			A -= -pick;
			S += -pick;


			if (S > 0) {
				B -= S;
			}
			else {
				A -= -S;
			}

			res += max(0ll, min(A, B) + (i + 1 < j));
			
			s += c[j];
			pick = min(pick, s);
			s += c[j + 1];
			pick = min(pick, s);
		}
	}

	cout << res << '\n';

	return 0;
}