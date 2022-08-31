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
#include <numeric>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;

int main() {
	fast_cin();
	int n; cin >> n;
	vector<pii> pts(n);
	for (auto& p : pts) {
		cin >> p.first >> p.second;
	}
	if (n % 2 == 1) {
		cout << "No\n";
		return 0;
	}
	set<pii> midpts;
	for (int i = 0; i < n / 2; ++i) {
		int j = i + n / 2;
		midpts.insert({pts[i].first + pts[j].first, pts[i].second + pts[j].second});
	}
	if (midpts.size() == 1) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
}