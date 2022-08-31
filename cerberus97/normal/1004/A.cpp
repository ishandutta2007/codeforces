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

const int N = 1e3 + 10;

ll x[N];

int main() {
	int n; ll d;
	cin >> n >> d;
	set<ll> points;
	for (int i = 1; i <= n; ++i) {
		cin >> x[i];
		points.insert(x[i] - d);
		points.insert(x[i] + d);
	}
	int ans = 0;
	for (auto &i : points) {
		ll res = d + 1;
		for (int j = 1; j <= n; ++j) {
			res = min(res, abs(x[j] - i));
		}
		if (res == d) {
			++ans;
		}
	}
	cout << ans;
}