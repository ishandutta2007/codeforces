#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;

const int N = 200200;

int n, m, k[N], res[N], p[N], l[N];
long long a[N];
set<pair<long long, int>> s;

int find(int x) {
	return x == p[x] ? x : p[x] = find(p[x]);
}

void join(int x, int y) {
	x = find(x);
	y = find(y);
	p[x] = y;
	l[y] = l[x];
}

long long f(int l, int r) {
	long long s = a[r] - a[l - 1];
	long long mod = r - l + 1;
	return s / mod - (s % mod == 0);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> m;
	rep(i, 1, n + 1) {
		cin >> a[i];
		a[i] += a[i - 1];
		p[i] = i;
		l[i] = i;
		if (i < n)
			s.insert({f(i, i), i});
	}
	rep(i, 0, m)
		cin >> k[i];

	int q = m - 1;
	int maxLen = 0;
	while (!s.empty()) {
		auto [cur, x] = *s.rbegin();
		s.erase(prev(s.end()));
		while (q >= 0 && k[q] > cur)
			res[q--] = maxLen;
		while (x < n && a[x] - a[l[x] - 1] > cur * (x - l[x] + 1)) {
			int h = find(x + 1);
			s.erase({f(l[h], h), h});
			join(x, x + 1);
			x = find(x);
		}
		maxLen = max(maxLen, x - l[x]);
		if (x < n) 
			s.insert({f(l[x], x), x});
	}

	while (q >= 0) 
		res[q--] = maxLen;
	rep(i, 0, m)
		cout << res[i] << " ";
	cout << "\n";
	return 0;
}