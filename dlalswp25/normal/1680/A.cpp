#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int l1, r1, l2, r2; scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
		if(r1 < l2 || r2 < l1) printf("%d\n", l1 + l2);
		else printf("%d\n", max(l1, l2));
	}
	return 0;
}