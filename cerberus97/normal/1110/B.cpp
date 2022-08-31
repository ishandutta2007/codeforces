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

ll b[N];

int main() {
	fast_cin();
	int n, m, k;
	cin >> n >> m >> k;
	ll cost = n;
	vector<ll> v;
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
	}
	for (int i = 2; i <= n; ++i) {
		v.pb(b[i] - b[i - 1] - 1);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n - k; ++i) {
		cost += v[i];
	}
	cout << cost << endl;
}