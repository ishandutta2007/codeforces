#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; a <= i; i--)
#define cat(x) cerr << #x << " = " << x << '\n';
using ll = long long;
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		set<int> s;
		while (n--) {
			int x;
			cin >> x;
			s.insert(s.count(x) ? -x : x);
		}

		cout << s.size() << '\n';
	}
	return 0;
}