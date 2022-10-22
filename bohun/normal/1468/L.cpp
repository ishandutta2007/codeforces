#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;

const int N = 1000100;

int n, k, s[N];
long long a[1010];
map<int, vector<int>> m;
vector<int> primes, res;
vector<pair<int, int>> e;
set<int> good;
set<int> fact[1010];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	rep(i, 2, N) {
		if (!s[i]) {
			primes.push_back(i);
			rep(j, 2, (N - 1) / i + 1)
				s[i * j] = 1;
		}
	}

	cin >> n >> k;
	rep(i, 0, n) {
		cin >> a[i];
		long long x = a[i];
		for (auto p : primes) {
			if (x % p == 0) {
				while (x % p == 0)
					x /= p;
				if (x == 1) 
					m[p].push_back(i);
				break;
			}
		}
		if (x == a[i]) {
			long long y = sqrt(x);
			if (y * y == x) {
				m[y].push_back(i);
			}
			else if (x <= 1000000000)
				m[x].push_back(i);
		}
	}
	
	int s = 0;
	for (auto [a, b] : m) {
		if (b.size() > 1) {
			e.emplace_back(b.size(), a);
			good.insert(a);
			s += b.size();
		}
	}
	sort(e.rbegin(), e.rend());

	if (k == 1 || s == 0) {
		cout << 0 << "\n";
		return 0;
	}

	rep(i, 0, n) {
		long long x = a[i];
		for (auto p : good) {
			if (x % p == 0) {
				fact[i].insert(p);
				while (x % p == 0)
					x /= p;
			}
		}
		if (x > 1)
			fact[i].clear();
	}

	if (k >= s || (k % 2 == 0 && e[0].first == 2)) {
		for (auto p : good) {
			if (k > 0) {
				res.push_back(m[p][0]);
				res.push_back(m[p][1]);
				k -= 2;
			}
		}
		for (auto p : good)
			rep(i, 2, m[p].size()) 
				if (k > 0) {
					res.push_back(m[p][i]);
					k -= 1;
				}
		rep(i, 0, n)
			if (int(fact[i].size()) > 1 && k > 0) {
				res.push_back(i);
				k -= 1;
			}
	}
	else if (e[0].first > 2) {
		for (auto [cnt, p] : e) {
			int need = min(cnt, k);
			if (need > 1) {
				rep(i, 0, need)
					res.push_back(m[p][i]);
			}
			if (need == 1) {
				res.erase(res.begin());
				res.push_back(m[p][0]);
				res.push_back(m[p][1]);
			}
			k -= need;
		}
		assert(k == 0);
	}
	else {
		assert(e[0].first == 2);
		assert(k % 2 == 1);
		int id = n;
		rep(i, 0, n) {
			int f = int(fact[i].size());
			if (f > 1 && (id == n || f < int(fact[id].size())))
				id = i;
		}
		if (id < n && 2 * int(fact[id].size()) + 1 <= k) {
			res.push_back(id);
			k--;
			for (auto p : fact[id]) {
				res.push_back(m[p][0]);
				res.push_back(m[p][1]);
				k -= 2;
			}
			for (auto p : good)
				if (fact[id].find(p) == fact[id].end() && k > 0) {
					res.push_back(m[p][0]);
					res.push_back(m[p][1]);
					k -= 2;
				}
			assert(k == 0);
		}
	}

	if (k > 0) {
		cout << "0\n";
		return 0;
	}
	for (auto x : res)
		cout << a[x] << " ";
	cout << "\n";

	return 0;
}