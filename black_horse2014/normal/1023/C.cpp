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

const int N = 220000;

int prv[N], used[N], nxt[N];
char a[N];

int main() {
	ios_base::sync_with_stdio(0);
	int n, k; cin >> n >> k >> a;
	for (int i = 0; i < n; i++) prv[i] = i-1, nxt[i] = i+1;
	set<int> S;
	for (int i = 0; i < n-1; i++) if (a[i] == '(' && a[i+1] == ')') S.insert(i);
	for (int times = 0; times < (n-k)/2; times++) {
		auto it = S.begin();
		int mid = *it;
		int l = prv[mid], r = nxt[mid];
		S.erase(it);
		used[mid] = used[r] = 1;
		r = nxt[r];
		if (l >= 0 && r < n && a[l] == '(' && a[r] == ')') S.insert(l);
		if (l >= 0) nxt[l] = r;
		if (r < n) prv[r] = l;
	}
	for (int i = 0; i < n; i++) if (!used[i]) putchar(a[i]);
	return 0;
}