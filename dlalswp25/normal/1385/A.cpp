#include <bits/stdc++.h>

using namespace std;

int a[3];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		for(int i = 0; i < 3; i++) scanf("%d", &a[i]);
		swap(a[0], a[2]);

		int mx = 0, c = 0;
		int mn = 1010101010;
		for(int i = 0; i < 3; i++) {
			if(mx == a[i]) c++;
			else if(mx < a[i]) {
				mx = a[i]; c = 1;
			}
			mn = min(mn, a[i]);
		}
		if(c < 2) { puts("NO"); continue; }
		puts("YES");
		for(int i = 0; i < 3; i++) printf("%d ", a[i] == mn ? mx : mn); puts("");
	}
	return 0;
}