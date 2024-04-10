#include <bits/stdc++.h>

using namespace std;

int T[10];

int main() {
	T[0] = 1;
	for(int i = 1; i <= 9; i++) T[i] = T[i - 1] * 10;
	int tc; scanf("%d", &tc);
	while(tc--) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		if(a < b) printf("%d %d\n", T[a - 1], T[b - 1] + T[c - 1]);
		else printf("%d %d\n", T[a - 1] + T[c - 1], T[b - 1]);
	}
	return 0;
}