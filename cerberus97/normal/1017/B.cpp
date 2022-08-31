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

int main() {
	int n; cin >> n;
	string s1, s2;
	cin >> s1 >> s2;
	vector<int> a1(n), a2(n);
	for (int i = 0; i < n; ++i) {
		a1[i] = s1[i] - '0';
		a2[i] = s2[i] - '0';
	}
	ll ans = 0, c[2][2] = {0};
	for (int i = n - 1; i >= 0; --i) {
		for (int j1 = 0; j1 < 2; ++j1) {
			for (int j2 = 0; j2 < 2; ++j2) {
				int cur = ((a1[i] or a2[i]) << 1) + (j1 or j2);
				int nxt = ((j1 or a2[i]) << 1) + (a1[i] or j2);
				if (cur != nxt) {
					ans += c[j1][j2];
				}
			}
		}
		++c[a1[i]][a2[i]];
	}
	cout << ans << endl;
}