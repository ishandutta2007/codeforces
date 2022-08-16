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
	int n, s;
	cin >> n >> s;
	if (s < 2 * n) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		for (int i = 0; i < n - 1; ++i) {
			cout << 2 << ' ';
		}
		cout << s - 2 * (n - 1) << '\n';
		cout << 1 << '\n';
	}
}