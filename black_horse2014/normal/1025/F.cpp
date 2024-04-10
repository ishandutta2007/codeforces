//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 2200;

struct PT {
	int x, y;
	PT(int x = 0, int y = 0) : x(x), y(y) {}
} P[N], Q[N];

long long cross(PT a, PT b) {
	return 1LL * a.x * b.y - 1LL * a.y * b.x;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> P[i].x >> P[i].y;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j == i) continue;
			Q[j - (j > i)] = PT(P[j].x - P[i].x, P[j].y - P[i].y);
		}
		sort(Q, Q + n - 1, [&](PT a, PT b) {
			if (a.y < 0) {
				if (b.y >= 0) return 1;
				if (cross(a, b) > 0) return 1;
				return 0;
			}
			if (b.y < 0) return 0;
			if (cross(a, b) > 0) return 1;
			return 0;
		});
		for (int j = 0, k = 0; j < n - 1; j++) {
			while (k < j + n - 1 && cross(Q[j], Q[k % (n - 1)]) >= 0) k++;
			int upper = k - j - 1;
			int lower = n - 2 - (k - j - 1);
			ans += 1LL * upper * (upper - 1) / 2 * lower * (lower - 1) / 2;
		}
	}
	cout << ans / 2 << endl;
	return 0;
}