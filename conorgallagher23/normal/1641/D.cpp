#include <bits/stdc++.h>
#pragma GCC optimize("Ofast","-funroll-loops")
#pragma GCC target("sse4.1","sse4.2","ssse3","sse3","sse2","sse","avx2","avx","popcnt","tune=native")
using namespace std;
const int N = 100005;

int n, m, num[N * 5], tot, ans = 2e9 + 5;
vector< int > pos[N * 5];
bitset< N > cur, b[10005];
struct obj {
	int b[5], w;
} a[N];
inline int val(int x) { return lower_bound(num + 1, num + tot + 1, x) - num; }

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++)
			scanf("%d", &a[i].b[j]), num[++tot] = a[i].b[j];
		scanf("%d", &a[i].w);	
	}
	sort(num + 1, num + tot + 1);
	tot = unique(num + 1, num + tot + 1) - num - 1;;
	sort(a + 1, a + n + 1, [&] (obj a, obj b) { return a.w < b.w; });
	
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < m; j++) a[i].b[j] = val(a[i].b[j]), pos[a[i].b[j]].push_back(i);
	for (int l = 1, r; l <= n; l = r + 1) {
		r = min(l + 10000, n);
		for (int i = l; i <= r; i++) b[i - l].set();
		for (int i = 1; i <= tot; i++) {
			for (auto j : pos[i]) cur[j] = 0;
			for (auto j : pos[i]) if (j >= l && j <= r) b[j - l] &= cur;
			for (auto j : pos[i]) cur[j] = 1;
		}
		for (int i = l; i <= r; i++) {
			int tmp = b[i - l]._Find_first();
//			cout << tmp << '\n';
			if (tmp <= n) ans = min(ans, a[i].w + a[tmp].w);
		}
	}
	if (ans > 2e9) puts("-1");
	else printf("%d\n", ans);
	return 0;
}