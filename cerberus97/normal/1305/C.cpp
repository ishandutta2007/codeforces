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
	if (n > m) {
		cout << 0 << endl;
		return 0;
	} else {
		vector<ll> a(n);
		for (auto& i : a) {
			cin >> i;
		}
		ll prod = 1;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				ll cand = abs(a[i] - a[j]) % m;
				prod *= cand;
				prod %= m;
			}
		}
		cout << prod << '\n';
	}
}