#include <bits/stdc++.h>

using namespace std;

int N;
bool t;

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		int x; scanf("%d", &x);
		if(abs(x) & 1) {
			if(t) {
				printf("%d\n", (x - 1) / 2);
			}
			else {
				printf("%d\n", (x + 1) / 2);
			}
			t = !t;
		}
		else printf("%d\n", x / 2);
	}

	return 0;
}