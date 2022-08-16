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

const int N = 100;

char st[N][N];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> st[i];
	}
	set<ll> s;
	for (int i = 1; i <= n; ++i) {
		ll mask = 0;
		for (ll j = 0; j < m; ++j) {
			if (st[i][j] == '#') {
				mask |= (1ll << j);
			}
		}
		s.insert(mask);
	}
	vector<ll> v;
	int x = s.size();
	for (auto &i : s) {
		v.pb(i);
	}
	for (int i = 0; i < x; ++i) {
		for (int j = i + 1; j < x; ++j) {
			if (v[i] & v[j]) {
				cout << "No";
				return 0;
			}
		}
	}
	cout << "Yes";
}