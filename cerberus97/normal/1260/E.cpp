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

const int N = (1 << 18) + 10;

int a[N];

int main() {
	fast_cin();
	int n; cin >> n;
	int p = -1;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] == -1) {
			p = i;
		}
	}
	ll ans = 0;
	int sz = n / 2, free = 0;
	priority_queue<int, vector<int>, greater<int>> avail;
	for (int i = n; i > p; --i) {
		if (free) {
			avail.push(a[i]);
			--free;
		} else {
			avail.push(a[i]);
			ans += avail.top();
			avail.pop();
			free += sz - 1;
			sz /= 2;
		}
	}
	cout << ans << '\n';
}