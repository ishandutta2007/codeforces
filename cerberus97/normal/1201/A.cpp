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

string s[N];
int a[N];

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> a[i];
	}
	int ans = 0;
	for (int i = 0; i < m; ++i) {
		map<char, int> mp;
		for (int j = 0; j < n; ++j) {
			++mp[s[j][i]];
		}
		int mx = 0;
		for (auto &p : mp) {
			mx = max(mx, p.second);
		}
		ans += mx * a[i];
	}
	cout << ans << '\n';
}