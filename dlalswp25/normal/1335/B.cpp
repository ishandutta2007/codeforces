#include <bits/stdc++.h>

using namespace std;

char ans[2020];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int n, a, b; scanf("%d%d%d", &n, &a, &b);
		for(int i = 0; i < a - b + 1; i++) ans[i] = 'a';
		char c = 'a';
		for(int i = a - b + 1; i < a; i++) {
			c++; ans[i] = c;
		}

		for(int i = 0; i < n; i++) printf("%c", ans[i % a]); puts("");
	}
	return 0;
}