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

vector<int> v;

int a[155000];
int b[155000];

void factor(int x) {
	for (int i = 2; 1LL * i * i <= x; i++) if (x % i == 0) {
		while (x % i == 0) x /= i;
		v.push_back(i);
	}
	if (x > 1) v.push_back(x);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
	factor(a[1]);
	factor(b[1]);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int x : v) {
		bool flg = 1;
		for (int i = 1; i <= n; i++) {
			if (a[i] % x == 0 || b[i] % x == 0) continue;
			flg = 0;
		}
		if (flg) return printf("%d\n", x), 0;
	}
	puts("-1");
	return 0;
}