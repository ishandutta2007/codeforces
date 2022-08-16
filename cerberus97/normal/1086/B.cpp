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
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;

int deg[N];

int main() {
	int n; ll s;
	cin >> n >> s;
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		++deg[u]; ++deg[v];
	}
	int leaves = 0;
	for (int i = 1; i <= n; ++i) {
		if (deg[i] == 1) {
			++leaves;
		}
	}
	// cout << s << endl;
	// cout << leaves << endl;
	ld ans = ld(2 * s) / leaves;
	cout << fixed << setprecision(10) << ans << endl;
}