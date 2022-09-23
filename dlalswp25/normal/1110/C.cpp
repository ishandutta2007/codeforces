#include <bits/stdc++.h>

using namespace std;

map<int, int> mp;
int ans[30];

int main() {
	for(int i = 1; i <= 25; i++) {
		mp[(1 << i) - 1]++;
	}

	for(int i = 2; i <= 25; i++) {
		int x = (1 << i) - 1;
		for(int j = 2; j * j <= x; j++) {
			if(x % j == 0) {
				ans[i] = x / j;
				break;
			}
		}
		if(!ans[i]) ans[i] = 1;
	}
	int Q; scanf("%d", &Q);
	while(Q--) {
		int x; scanf("%d", &x);
		if(mp[x]) {
			for(int i = 24; i >= 0; i--) {
				if(x & (1 << i)) {
					printf("%d\n", ans[i + 1]);
					break;
				}
			}
		}
		else {
			for(int i = 24; i >= 0; i--) {
				if(x & (1 << i)) {
					printf("%d\n", (1 << (i + 1)) - 1);
					break;
				}
			}
		}
	}
	return 0;
}