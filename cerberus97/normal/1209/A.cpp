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

const int N = 1e2 + 10;

int a[N];
bool seen[N];

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (!seen[i]) {
			++ans;
			for (int j = i + 1; j <= n; ++j) {
				if (a[j] % a[i] == 0) {
					seen[j] = true;
				}
			}
		}
	}
	cout << ans << endl;
}