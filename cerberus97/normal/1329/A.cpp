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
#include <numeric>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	vector<int> l(m), p(m);
	for (auto& i : l) {
		cin >> i;
	}
	ll sum = 0;
	for (int i = 0; i < m; ++i) {
		if (l[i] > n - i) {
			cout << "-1\n";
			return 0;
		}
		sum += l[i];
		p[i] = i + 1;
	}
	if (sum < n) {
		cout << "-1\n";
		return 0;
	}
	p.pb(n + 1);
	for (int i = m - 1; i >= 0; --i) {
		if (p[i] + l[i] - 1 < p[i + 1] - 1) {
			p[i] = p[i + 1] - l[i];
		}
	}
	for (int i = 0; i < m; ++i) {
		cout << p[i] << ' ';
	}
	cout << endl;
}