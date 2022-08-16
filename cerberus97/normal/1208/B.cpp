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

const int N = 2e3 + 10;

int a[N];

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	set<int> s1, s2;
	int ans = n;
	a[0] = 0;
	for (int i = 0; i <= n; ++i) {
		if (s1.count(a[i])) {
			break;
		} else {
			s1.insert(a[i]);
		}
		s2.clear();
		for (int j = n; j >= i; --j) {
			if (s1.count(a[j]) or s2.count(a[j])) {
				ans = min(ans, j - i);
				break;
			} else {
				s2.insert(a[j]);
			}
		}
	}
	cout << ans << endl;
}