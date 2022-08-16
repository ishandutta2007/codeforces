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
	int t; cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		set<int> seen;
		for (auto& i : a) {
			cin >> i;
			seen.insert(i);
		}
		if (seen.size() > k) {
			cout << -1 << '\n';
			continue;
		}
		for (int i = 1; i <= n and seen.size() < k; ++i) {
			seen.insert(i);
		}
		cout << k * n << '\n';
		for (int i = 0; i < n; ++i) {
			for (auto& v : seen) {
				cout << v << ' ';
			}
		}
		cout << '\n';
	}
}