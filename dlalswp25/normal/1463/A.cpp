#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int A, B, C; scanf("%d%d%d", &A, &B, &C);
		if((A + B + C) % 9) { puts("NO"); continue; }
		int t = (A + B + C) / 9;
		if(min(A, min(B, C)) < t) puts("NO");
		else puts("YES");
	}
	return 0;
}