#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string s;
const ll mod = 998244353;
hash<size_t> ha;

map<tuple<size_t, size_t, bool>, size_t> hash_data;
ll hashes_taken = 2;
ll my_hash(size_t a, size_t b, bool c) {
	if (a > b)
		swap(a, b);
	auto x = make_tuple(a, b, c);
	if (hash_data.count(x))
		return hash_data[x];
	return hash_data[x] = hashes_taken++;
}

pair<ll, size_t> solve(int v, int n) {
	if (n == 1) {
		return make_pair(1, s[v] == 'B');
	} else {
		auto p1 = solve(v * 2, n - 1);
		auto p2 = solve(v * 2 + 1, n - 1);
		ll ways = 0;
		if (p1.second == p2.second) {
			ways = p1.first * p2.first % mod;
		} else {
			ways = 2 * p1.first * p2.first % mod;
		}
		ll h = my_hash(p1.second, p2.second, s[v] == 'B');
		return make_pair(ways, h);
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n >> s;
	s = "x" + s;
	cout << solve(1, n).first << endl;
}