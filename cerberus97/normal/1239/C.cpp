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

struct event_t {
	ll t; int type, id;
	bool operator<(const event_t &o) const {
		return tie(t, type, id) > tie(o.t, o.type, o.id);
	}
};

ll a[N], ans[N];

int main() {
	fast_cin();
	int n, p;
	set<int> active, in_queue;
	priority_queue<event_t> events;
	ll queue_free_at = 0;
	cin >> n >> p;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		events.push({a[i], 0, i});
	}
	while (!events.empty()) {
		auto cur = events.top();
		events.pop();
		if (cur.type == 0) {
			active.insert(cur.id);
		} else {
			in_queue.erase(cur.id);
		}
		while (!active.empty()) {
			int id = *active.begin();
			if (in_queue.empty() or id < *in_queue.begin()) {
				queue_free_at = max(queue_free_at, a[id]) + p;
				ans[id] = queue_free_at;
				active.erase(id);
				in_queue.insert(id);
				events.push({ans[id], 1, id});
			} else {
				break;
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << ' ';
	}
	cout << endl;
}