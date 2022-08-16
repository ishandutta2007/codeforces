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
	int n, m, p;
	cin >> n >> m >> p;
	vector<int> a(n), b(m);
	for (auto& i : a) {
		cin >> i;
	}
	for (auto& i : b) {
		cin >> i;
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] % p) {
			ans = i;
			break;
		}
	}
	for (int i = 0; i < m; ++i) {
		if (b[i] % p) {
			ans += i;
			break;
		}
	}
	cout << ans << endl;
}