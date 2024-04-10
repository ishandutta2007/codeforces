#include <bits/stdc++.h>
 
const int MAXN = 300010;
typedef long long LL;
 
int A[MAXN], n, oa[MAXN];
LL mask[MAXN];
 
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);
	std::cin >> n;
	LL tv = 0, ans = 0;
	for (int i = 1; i <= n; ++i) std::cin >> A[i] >> mask[i], tv += A[i]; // , oa[i] = A[i];
	for (int i = 0; i < 62; ++i) {
		LL tx = 0;
		for (int j = 1; j <= n; ++j)
			if ((mask[j] >> i) == 1)
				tx += A[j];
		// std::cout << tx << " " << tv << std::endl;
		if (tx && (~(tx ^ tv) >> 63)) {
			for (int j = 1; j <= n; ++j)
				if (mask[j] >> i & 1)
					A[j] = -A[j];
			ans |= 1ll << i;
		}
	}
	std::cout << ans << std::endl;
//	LL vv = 0;
//	for (int i = 1; i <= n; ++i) vv += __builtin_popcountll(mask[i] & ans)  & 1 ? -oa[i] : oa[i];
//	std::cout << tv << " " << vv << std::endl;
	return 0;
}