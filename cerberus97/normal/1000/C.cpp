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

const int N = 2e5 + 10;

ll ans[N];

int main() {
	int n; cin >> n;
	map<ll, int> events;
	for (int i = 0; i < n; ++i) {
		ll l, r;
		cin >> l >> r;
		++events[l];
		--events[r + 1];
	}
	ll cur = 0, pos = 0;
	for (auto &i : events) {
		ans[cur] += i.first - pos;
		pos = i.first;
		cur += i.second;
	}
	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << ' ';
	}
}