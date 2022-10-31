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

char ans[1100];

int query(int r1, int c1, int r2, int c2) {
	cout << "? " << r1 << ' ' << c1 << ' ' << r2 << ' ' << c2 << endl;
	cout.flush();
	string ret; cin >> ret;
	return !strcmp(ret.c_str(), "YES");
}

int main() {
	ios_base::sync_with_stdio(0);
	int n; cin >> n;
	{
		int r = 1, c = 1;
		for (int i = 0; i < n-1; i++) {
			if (query(r + 1, c, n, n)) {
				ans[i] = 'D';
				r++;
			} else {
				ans[i] = 'R';
				c++;
			}
		}
	}
	{
		int r = n, c = n;
		for (int i = 0; i < n-1; i++) {
			if (query(1, 1, r, c - 1)) {
				ans[i + n - 1] = 'R';
				c--;
			} else {
				ans[i + n - 1] = 'D';
				r--;
			}
		}
		reverse(ans + n - 1, ans + n + n - 2);
	}
	cout << "! " << ans << endl;
	cout.flush();
	return 0;
}