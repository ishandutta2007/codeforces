/* cerberus97 - Hanit Banga */

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;

vector<int> segments[N];
int s[2 * N];

vector<int> compute_Z(int *s, int n);

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int a, b;
		cin >> a >> b;
		segments[a].push_back((b >= a ? b - a + 1 : n - a + 1 + b));
		swap(a, b);
		segments[a].push_back((b >= a ? b - a + 1 : n - a + 1 + b));
	}
	map<vector<int>, int> mp;
	for (int i = 1; i <= n; ++i) {
		sort(segments[i].begin(), segments[i].end());
		mp[segments[i]];
	}
	int nxt_id = 0;
	for (auto &i : mp) {
		i.second = ++nxt_id;
	}
	for (int i = 0; i < n; ++i) {
		s[i] = mp[segments[i + 1]];
		// cout << s[i] << ' ';
	}
	for (int i = n; i < 2 * n; ++i) {
		s[i] = s[i - n];
	}
	vector<int> z = compute_Z(s, 2 * n);
	for (int i = 1; i < n; ++i) {
		if (z[i] >= n) {
			cout << "Yes\n";
			return 0;
		}
	}
	cout << "No\n";
}

vector<int> compute_Z(int *s, int n) {
	// int n = s.length();
	vector<int> z(n, 0);
	z[0] = n;
	int l = 0, r = 0;
	for (int i = 1; i < n; ++i) {
		if (r >= i) {
			z[i] = min(z[i - l], r - i + 1);
		}
		while (i + z[i] < n and s[i + z[i]] == s[z[i]]) {
			++z[i];
		}
		if (i + z[i] - 1 > r) {
			r = i + z[i] - 1;
			l = i;
		}
	}
	return z;
}