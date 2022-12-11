#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

const int MAXN = 200010;
int tree[MAXN], a[MAXN], n;
typedef long long LL;
LL ans;
std::vector<int> qs[MAXN];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		a[i] = std::min(a[i], n);
		qs[a[i]].push_back(i);
		if (a[i] >= i) --ans;
	}
	for (int i = 1; i <= n; ++i) {
		for (int x = a[i]; x; x -= x & -x) ++tree[x];
		const std::vector<int> & vec = qs[i];
		const int SZ = vec.size();
		for (int j = 0; j != SZ; ++j) 
			for (int x = vec[j]; x <= n; x += x & -x) ans += tree[x];
	}
	printf("%lld\n", ans >> 1);
	return 0;
}