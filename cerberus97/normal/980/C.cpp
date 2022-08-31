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

int p[N];
map<int, int> groups;

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
	}
	groups.insert({0, 0});
	for (int i = 1; i <= n; ++i) {
		auto g = groups.upper_bound(p[i]);
		--g;
		int l = g->first, r = g->second;
		if (p[i] <= l + k - 1) {
			groups.erase(g);
			groups.insert({l, max(r, p[i])});
		} else {
			l = max(r + 1, p[i] - k + 1);
			groups.insert({l, p[i]});
		}
		cout << l << ' ';
	}
}