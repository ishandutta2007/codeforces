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

int main() {
	fast_cin();
	int n; cin >> n;
	if (n % 2 == 1) {
		cout << "YES\n";
		int l = 1, r = 2;
		vector<int> ans(2 * n + 1);
		for (int i = 1, j = n + 1; i <= n; ++i, ++j) {
			ans[i] = l;
			ans[j] = r;
			l += 2; r += 2;
			swap(l, r);
		}
		for (int i = 1; i <= 2 * n; ++i) {
			cout << ans[i] << ' ';
		}
		cout << endl;
	} else {
		cout << "NO\n";
	}
}