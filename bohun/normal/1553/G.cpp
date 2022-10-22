#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 1 << 20;
int n, q, p[N], a[N], r[N];

int find(int x) {
	return x == p[x] ? x : p[x] = find(p[x]);
}

void join(int x, int y) {
	p[find(x)] = find(y);
}

int main() {
	ios_base::sync_with_stdio(0);
	auto fact = [&](int x) {
		vector<int> res;
		for (int i = 2; i * i <= x; i++) {
			if (x % i == 0) {
				res.push_back(i);
				while (x % i == 0)
					x /= i;
			}
		}
		if (x > 1)
			res.push_back(x);
		return res;
	};
	iota(p, p + N, 0);
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		auto f = fact(a[i]);
		for (int j = 0; j + 1 < f.size(); j++)
			join(f[j], f[j + 1]);
		r[i] = f[0];
	}
	set<pair<int, int>> S;
	for (int i = 0; i < n; i++) {
		auto f = fact(a[i] + 1);
		vector<int> v = {r[i]};
		for (auto p : f)
			v.push_back(p);
		for (auto a : v)
			for (auto b : v)
				S.insert(make_pair(find(a), find(b)));
	}
	while (q--) {
		int a, b;
		cin >> a >> b;
		a = find(r[--a]);
		b = find(r[--b]);
		if (a == b)
			cout << 0 << endl;
		else if (S.count(make_pair(a, b)))
			cout << 1 << endl;
		else
			cout << 2 << endl;
	}
	return 0;
}