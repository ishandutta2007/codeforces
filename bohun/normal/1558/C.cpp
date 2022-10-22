#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;

int t, n, a[2050];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> t;
	while (t--) {
		cin >> n;
		rep(i, 1, n + 1)
			cin >> a[i];

		vector<int> moves;
		auto gao = [&](int x) {
			moves.push_back(x);
			reverse(a + 1, a + x + 1);
		};

		bool ok = 1;
		rep(i, 1, n + 1)
			if (a[i] % 2 != i % 2) 
				ok = 0;

		if (!ok) {
			cout << -1 << '\n';
			continue;
		}

		for (int i = n; 1 < i; i -= 2) {
			gao(find(a + 1, a + n + 1, i) - a);
			gao(find(a + 1, a + n + 1, i - 1) - a - 1);
			gao(find(a + 1, a + n + 1, i - 1) - a + 1);
			gao(3);
			gao(i);
		}

		cout << moves.size() << '\n';
		for (auto x : moves)
			cout << x << ' ';
		cout << '\n';

		rep(i, 1, n + 1)
			assert(i == a[i]);
	}
	return 0;
}