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

const int N = 512;

vector<int> s1[2 * N], s2[2 * N];

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			int a; cin >> a;
			s1[i + j].pb(a);
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			int a; cin >> a;
			s2[i + j].pb(a);
		}
	}
	for (int i = 2; i <= n + m; ++i) {
		sort(s1[i].begin(), s1[i].end());
		sort(s2[i].begin(), s2[i].end());
		if (s1[i] != s2[i]) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
}