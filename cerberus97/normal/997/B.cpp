/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
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
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;

ll brute_force(ll n);

int main() {
	ll n; cin >> n;
	if (n <= 15) {
		cout << brute_force(n);
	} else {
		cout << brute_force(15) + 49 * (n - 15);
	}
	// int prev = 0;
	// for (int i = 1; i <= 20; ++i) {
	// 	int cur = brute_force(i);
	// 	cout << i << ' ' << cur - prev << endl;
	// 	prev = cur;
	// }
}

ll brute_force(ll n) {
	set<ll> s;
	for (int a = 0; a <= n; ++a) {
		for (int b = 0; b <= n; ++b) {
			for (int c = 0; c <= n; ++c) {
				int d = n - a - b - c;
				if (0 <= d and d <= n) {
					s.insert(a + 5*b + 10*c + 50*d);
				}
			}
		}
	}
	return s.size();
}