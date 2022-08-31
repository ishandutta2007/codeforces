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

ll p[N];

int main() {
	fast_cin();
	ll n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) {
		cin >> p[i];
		--p[i];
	}
	int ans = 0;
	for (int i = 1; i <= m;) {
		int page = (p[i] - (i - 1)) / k;
		int r = i + 1;
		while (r <= m) {
			if ((p[r] - (i - 1)) / k == page) {
				++r;
			} else {
				break;
			}
		}
		++ans;
		i = r;
	}
	cout << ans << endl;
}