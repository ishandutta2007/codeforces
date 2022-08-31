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

const int N = 1e5 + 10, inf = 1e9 + 42;

int main() {
	fast_cin();
	int n; cin >> n;
	set<int> free;
	vector<int> sell(n + 1);
	vector<int> ops(2 * n);
	for (int i = 0; i < 2 * n; ++i) {
		char c; cin >> c;
		if (c == '+') {
			free.insert(i);
		} else {
			int b; cin >> b;
			sell[b] = i;
			ops[i] = -b;
		}
	}
	for (int v = 1; v <= n; ++v) {
		int i = sell[v];
		auto it = free.lower_bound(i);
		if (it != free.begin()) {
			int j = *(prev(it));
			ops[j] = v;
			free.erase(j);
		} else {
			cout << "NO\n";
			return 0;
		}
	}
	priority_queue<int, vector<int>, greater<int>> q;
	q.push(inf);
	for (auto& op : ops) {
		if (op < 0) {
			if (q.top() != -op) {
				cout << "NO\n";
				return 0;
			}
			q.pop();
		} else {
			q.push(op);
		}
	}
	cout << "YES\n";
	for (auto& op : ops) {
		if (op > 0) {
			cout << op << ' ';
		}
	}
	cout << '\n';
}