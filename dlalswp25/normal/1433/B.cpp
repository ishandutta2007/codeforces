#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		int l = 0, r = 0, c = 0;
		for(int i = 1; i <= N; i++) {
			int x; scanf("%d", &x);
			if(x) {
				if(!l) l = i;
				r = i;
				c++;
			}
		}
		printf("%d\n", r - l + 1 - c);
	}
	return 0;
}