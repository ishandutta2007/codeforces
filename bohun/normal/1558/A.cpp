#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		int A = (a + b + 1) / 2;
		int B = a + b - A;

		set<int> res;
		rep(r, 0, 2) {
			rep(k, 0, a + b + 1) {
				int c = min(A, k);
				int ones = c + B - (k - c);

				int d = min(B, k);
				int ones2 = B - d + (k - d);
				if (ones > ones2)
					swap(ones, ones2);
				assert(ones % 2 == ones2 % 2);

				if (ones <= b && b <= ones2 && b % 2 == ones % 2)
					res.insert(k);
			}
			swap(A, B);
		}

		cout << int(res.size()) << '\n';
		for (auto x : res)
			cout << x << ' ';
		cout << '\n';
	}
	return 0;
}