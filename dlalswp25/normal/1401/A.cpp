#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int a, k; scanf("%d%d", &a, &k);
		if(a < k) printf("%d\n", k - a);
		else printf("%d\n", !(k % 2 == a % 2));
	}
	return 0;
}