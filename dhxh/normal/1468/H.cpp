#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#define left ksdhfdskjfhksd
#define right sdhfsdkjfhskdjsfhkj
using namespace std;
const int maxn = 410000;
int vis[maxn], left[maxn], right[maxn];
int main() {
	//freopen("in.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, k, m;
		scanf("%d %d %d", &n, &k, &m);
		for (int i = 0; i <= n + 1; ++i)
			vis[i] = true;
		vector<int> a(m);
		for (int i = 0; i < m; ++i)
			scanf("%d", &a[i]);
		for (int i = 0; i < m; ++i)
			vis[a[i]] = false;
		for (int i = 1; i <= n; ++i)
			left[i] = left[i - 1] + vis[i];
		for (int i = n; i >= 1; --i)
			right[i] = right[i + 1] + vis[i];
		if ((n - m) % (k - 1)) {
			puts("NO");
			continue;
		}
		bool ok = false;
		for (int i = 0; i < m; ++i) {
			if (left[a[i]] >= k / 2 && right[a[i]] >= k / 2)
				ok = true;
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}