#include <bits/stdc++.h>

using namespace std;
const int MX = 300000;

int X[303030];

int main() {
	for(int i = 1; i <= MX; i++) X[i] = X[i - 1] ^ i;

	int tc; scanf("%d", &tc);
	while(tc--) {
		int a, b; scanf("%d%d", &a, &b);
		if(X[a - 1] == b) printf("%d\n", a);
		else if(X[a] == b) printf("%d\n", a + 2);
		else printf("%d\n", a + 1);
	}
	return 0;
}