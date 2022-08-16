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
	ll n; cin >> n;
	ll sum = (n * (n + 1)) / 2;
	for (int p = 2; p <= n; ++p) {
		if (sum % p == 0) {
			cout << "Yes\n";
			cout << "1 " << p << '\n';
			cout << n - 1 << ' ';
			for (int j = 1; j <= n; ++j) {
				if (j != p) {
					cout << j << ' ';
				}
			}
			cout << '\n';
			return 0;
		}
	}
	cout << "No\n";
}