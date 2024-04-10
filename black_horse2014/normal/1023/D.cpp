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

int f[N], L[N], R[N], ans[N], a[N];

int find_set(int u) {
	return f[u] == u ? u : f[u] = find_set(f[u]);
}

void merge(int u, int v) {
	u = find_set(u);
	v = find_set(v);
	if (u == v) return;
	f[u] = v;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= q; i++) L[i] = n + 1, R[i] = 0;
	for (int i = 1; i <= n; i++) R[a[i]] = i;
	for (int i = n; i > 0; i--) L[a[i]] = i;
	for (int i = 1; i <= n + 1; i++) f[i] = i;
	long long sum = 0;
	for (int i = 1; i <= n; i++) sum += a[i];
	if (sum == 0) {
		puts("YES");
		for (int i = 1; i <= n; i++) printf("%d ", q);
		puts("");
		return 0;
	}
	set<int> S;
	for (int i = q; i > 0; i--) {
		if (L[i] <= n) {
			int u = L[i];
			while (u <= R[i]) {
				if (!a[u]) {
					if (!S.empty()) {
						ans[u] = *S.begin();
						S.erase(S.begin());
					} else {
						ans[u] = i;
					}
				} else {
					if (a[u] < i) {
						return puts("NO"), 0;
					}
					ans[u] = i;
				}
				merge(u, u + 1);
				u = find_set(u);
			}
		} else {
			S.insert(i);
		}
	}
	int maxa = *max_element(a + 1, a + n + 1);
	if (maxa != q && S.count(q)) {
		bool found = 0;
		for (int i = 1; i <= n; i++) if (!ans[i]) {
			ans[i] = q;
			found = 1;
			break;
		}
		if (!found) {
			return puts("NO"), 0;
		}
	}
	puts("YES");
	for (int i = 1; i <= n; i++) printf("%d%c", max(ans[i], 1), i < n ? ' ' : '\n');
	return 0;
}