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

int a[N];

vector <int> normal = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vector <int> leap   = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
	vector <int> v;
	for (int i = 0; i < 3; ++i) {
		for (auto &j : normal) {
			v.pb(j);
		}
	}

	for (auto &j : leap) {
		v.pb(j);
	}

	for (int i = 0; i < 3; ++i) {
		for (auto &j : normal) {
			v.pb(j);
		}
	}

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	int x = v.size();
	bool ans = false;
	for (int i = 0; i + n - 1 < x; ++i) {
		ans = true;
		for (int j = i, k = 1; k <= n; ++j, ++k) {
			if (v[j] != a[k]) {
				ans = false;
				break;
			}
		}

		if (ans) {
			break;
		}
	}

	if (ans) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
}