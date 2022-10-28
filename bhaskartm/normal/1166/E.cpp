#include <bits/stdc++.h>
 
using namespace std;
 
int n, m;
bitset<10001> bm[55];
 
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		int si;
		scanf("%d", &si);
		while (si--) {
			int tmp;
			scanf("%d", &tmp);
			bm[i].set(tmp);
		}
		for (int j = 0; j < i; j++)
			if ((bm[i] & bm[j]).none()) {
				puts("impossible");
				return 0;
			}
	}
	puts("possible");
}