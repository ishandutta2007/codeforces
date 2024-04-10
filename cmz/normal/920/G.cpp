#include <bits/stdc++.h>
using namespace std;
vector<int> a[1000020];
int t, x, p, k;
int S(int x, int p) { // i <= x   (i, g) == 1
	int z = 0;
	for (int i = 0; i < 1 << a[p].size(); i++) {
		int s = 1, c = 0;
		for (int j = 0; j < a[p].size(); j++) {
			if (i >> j & 1) {
				s *= a[p][j];
				c++;
			}
		}
		if (c % 2 == 0) {
			z += x / s;
		} else {
			z -= x / s;
		}
	}
	return z;
}
int main() {
	for (int i = 2; i <= 1000000; i++) {
		if (a[i].size() > 0) {
			continue;
		}
		for (int j = i; j <= 1000000; j += i) {
			a[j].push_back(i);
		}
	}
	int cases;
	scanf("%d", &cases);
	for (int tt = 0; tt < cases; tt++) {
		scanf("%d%d%d", &x, &p, &k);
		k += S(x, p);
		int L = 0;
		int R = 1e9;
		while (L < R - 1) {
			int M = (L + R) / 2;
			if (S(M, p) < k) {
				L = M;
			} else {
				R = M;
			}
		}
		printf("%d\n", R);
	}
}