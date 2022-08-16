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

const int N = 1e3 + 10;

bool a[N], b[N];

int main() {
	fast_cin();
	int n, s;
	cin >> n >> s;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
	}
	if (!a[1]) {
		cout << "NO\n";
	} else if (!a[s] and !b[s]) {
		cout << "NO\n";
	} else if (a[s]) {
		cout << "YES\n";
	} else {
		bool path = false;
		for (int i = s + 1; i <= n; ++i) {
			if (a[i] and b[i]) {
				path = true;
				break;
			}
		}
		if (path) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}