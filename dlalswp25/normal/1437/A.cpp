#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int l, r; scanf("%d%d", &l, &r);
		if(l * 2 >= r + 1) puts("YES");
		else puts("NO");
	}
	return 0;
}