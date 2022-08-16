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

const int N = 1e5 + 10;

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<pii> edges(m);
		for (auto &e : edges) {
			cin >> e.first >> e.second;
		}
		vector<bool> done(3 * n + 1, 0);
		vector<int> matching;
		int id = 0;
		for (auto &e : edges) {
			++id;
			if (done[e.first] or done[e.second]) {
				continue;
			} else {
				done[e.first] = true;
				done[e.second] = true;
				matching.pb(id);
			}
		}
		if (matching.size() >= n) {
			cout << "Matching\n";
			for (int i = 0; i < n; ++i) {
				cout << matching[i] << ' ';
			}
		} else {
			cout << "IndSet\n";
			for (int i = 1, ctr = 0; ctr < n; ++i) {
				if (!done[i]) {
					cout << i << ' ';
					++ctr;
				}
			}
		}
		cout << '\n';
	}
}