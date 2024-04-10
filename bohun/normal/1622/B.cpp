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
		vector<int> p(n);
		for (auto &x : p)
			cin >> x;
		string s;
		cin >> s;

		vector<int> ord(n);
		iota(ord.begin(), ord.end(), 0);
		sort(ord.begin(), ord.end(), [&](int a, int b) {
			if (s[a] != s[b])
				return s[b] == '1';
			return p[a] < p[b];
		});

		vector<int> res(n);
		for (int i = 0; i < n; i++)
			res[ord[i]] = i;
		for (auto x : res)
			cout << x + 1 << ' ';
		cout << '\n';
	}

	return 0;
}