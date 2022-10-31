#include <bits/stdc++.h>
using namespace std;

const int N = 11000;
vector<int> vec[N];
bitset<N> b[110], dp, ret;
int main() {
	int n, q; scanf("%d%d", &n, &q);
	int sn = int(sqrt(n));
	for (int i = 1; i <= n / sn; i++) b[i][0] = 1;
	while (q--) {
		int l, r, x; scanf("%d%d%d", &l, &r, &x);
		int R = r / sn, L = (l - 1 + sn - 1) / sn + 1;
		if (L > R) {
			for (int i = l; i <= r; i++) vec[i].push_back(x);
			continue;
		}
		for (int i = L; i <= R; i++) b[i] |= (b[i] << x);
		for (int i = l; i <= (L - 1) * sn; i++) vec[i].push_back(x);
		for (int i = R * sn + 1; i <= r; i++) vec[i].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		dp = b[(i + sn - 1) / sn];
		for (int j = 0; j < vec[i].size(); j++) dp |= (dp << vec[i][j]);
		ret |= dp;
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) cnt += ret[i];
	printf("%d\n", cnt);
	for (int i = 1; i <= n; i++) if (ret[i]) printf("%d ", i);
	return 0;
}