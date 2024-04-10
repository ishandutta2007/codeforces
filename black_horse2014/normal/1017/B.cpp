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

const int N = 110000;

char a[N], b[N];
int c[N], cnt[N];

int main() {
	ios_base::sync_with_stdio(0);
	int n; cin >> n >> a >> b;
	for (int i = 0; i < n; i++) {
		int x = a[i] - '0';
		int y = b[i] - '0';
		if (y == 0) c[x]++;
		cnt[x]++;
	}
	cout << c[0] * 1LL * cnt[1] + c[1] * 1LL * cnt[0] - c[0] * 1LL * c[1] << endl;
	return 0;
}