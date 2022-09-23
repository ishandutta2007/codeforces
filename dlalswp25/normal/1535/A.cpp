#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d);
		if(max(a, b) < min(c, d)) puts("NO");
		else if(min(a, b) > max(c, d)) puts("NO");
		else puts("YES");
	}
	return 0;
}