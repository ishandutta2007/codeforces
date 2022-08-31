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

ll a[N];
bool b[N];

int main() {
	fast_cin();
	int n, m, l;
	cin >> n >> m >> l;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		b[i] = (a[i] > l);
	}
	a[n + 1] = l;
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (b[i] and !b[i + 1]) {
			++ans;
		}
	}
	while (m--) {
		int type; cin >> type;
		if (type == 0) {
			cout << ans << '\n';
		} else {
			int p, d;
			cin >> p >> d;
			a[p] += d;
			if (!b[p] and a[p] > l) {
				b[p] = 1;
				if (b[p - 1] and b[p + 1]) {
					--ans;
				} else if (!b[p - 1] and !b[p + 1]) {
					++ans;
				}
			}
		}
	}
}