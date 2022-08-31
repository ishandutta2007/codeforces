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

const int N = 5e4 + 10, K = 12, inf = 1e8;

int n, k;

struct Group {
	int mn[K], mx[K], size = 1;

	bool operator<(const Group &other) const {
		for (int i = 1; i <= k; ++i) {
			if (mx[i] >= other.mn[i]) {
				return false;
			}
		}

		return true;
	}

	void merge(const Group &other) {
		size += other.size;
		for (int i = 1; i <= k; ++i) {
			mn[i] = min(mn[i], other.mn[i]);
			mx[i] = max(mx[i], other.mx[i]);
		}
	}
};

int main() {
	set <Group> st;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		Group g;
		for (int j = 1; j <= k; ++j) {
			int s;
			scanf("%d", &s);
			g.mn[j] = g.mx[j] = s;
		}

		auto it = st.lower_bound(g);
		while (it != st.end() and !(g < *it)) {
			g.merge(*it);
			st.erase(it);
			it = st.lower_bound(g);
		}

		st.insert(g);
		printf("%d\n", st.rbegin() -> size);
	}	
}