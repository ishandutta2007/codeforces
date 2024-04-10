#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; a <= i; i--)
#define cat(x) cerr << #x << " = " << x << '\n';
using ll = long long;
using namespace std;

// [0, n)
template<class T>
struct Fenwick {
	int n;
	vector<T> f;
	Fenwick(int n) : n(n), f(n + 1) {}
	void add(int i, T x) {
		for (i++; i <= n; i += i & -i)
			f[i] += x;
	}
	T sum(int i) {
		T res = 0;
		for (i++; i > 0; i -= i & -i)
			res += f[i];
		return res;
	}
	T rangeSum(int a, int b) {
		return sum(b) - sum(a - 1);
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s, t;
		cin >> s >> t;

		deque<int> q[26];
		for (int i = 0; i < n; i++)
			q[s[i] - 'a'].push_back(i);

		Fenwick<int> f(n);
		long long res = 1e18;
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			int x = t[i] - 'a';

			for (int c = 0; c < x; c++)
				if (!q[c].empty()) {
					int p = q[c].front();
					res = min(res, sum + p + f.rangeSum(p + 1, n - 1) - i);
				}

			if (q[x].empty()) 
				break;

			int p = q[x].front();
			q[x].pop_front();
			sum += p + f.rangeSum(p + 1, n - 1) - i;
			f.add(p, 1);
		}

		cout << (res < 1e18 ? res : -1) << '\n';
	}
	return 0;
}