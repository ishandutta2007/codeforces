#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int x; scanf("%d", &x);
		int s = 0, n = 0;
		while(s < x) {
			n++;
			s += n;
		}
		int d = s - x;
		if(d == 1) printf("%d\n", n + 1);
		else printf("%d\n", n);
	}
	return 0;
}