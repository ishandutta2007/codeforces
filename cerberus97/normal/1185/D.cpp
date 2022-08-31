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

const int N = 2e5 + 10;

pll a[N];
ll d[N];

void check(multiset<ll> &diff, int id);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a + 1, a + 1 + n);
	multiset<ll> diff;
	for (int i = 2; i <= n; ++i) {
		d[i] = a[i].first - a[i - 1].first;
		diff.insert(d[i]);
	}
	for (int i = 1; i <= n; ++i) {
		if (i == 1) {
			diff.erase(diff.find(d[2]));
			check(diff, a[i].second);
			diff.insert(d[2]);
		} else if (i == n) {
			diff.erase(diff.find(d[n]));
			check(diff, a[i].second);
			diff.insert(d[n]);
		} else {
			diff.erase(diff.find(d[i]));
			diff.erase(diff.find(d[i + 1]));
			diff.insert(a[i + 1].first - a[i - 1].first);
			check(diff, a[i].second);
			diff.insert(d[i]);
			diff.insert(d[i + 1]);
			diff.erase(diff.find(a[i + 1].first - a[i - 1].first));
		}
	}
	cout << -1 << '\n';
}

void check(multiset<ll> &diff, int id) {
	if (diff.empty() or *diff.begin() == *diff.rbegin()) {
		cout << id << '\n';
		exit(0);
	}
}