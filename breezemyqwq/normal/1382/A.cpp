#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int a[1005], b[1005];
bool a_hve[1005], b_hve[1005];

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		memset(a_hve, false, sizeof a_hve);
		memset(b_hve, false, sizeof b_hve);
		for (int i = 1; i <= n; i++) scanf("%d", a + i), a_hve[a[i]] = true;
		for (int i = 1; i <= m; i++) scanf("%d", b + i), b_hve[b[i]] = true;
		int c = -1;
		for (int i = 1; i <= 1000; i++) {
			if (a_hve[i] && b_hve[i]) {
				c = i;	
				break;
			}
		}
		if (c == -1) puts("NO");
		else {
			puts("YES");
			printf("1 %d\n", c);
		}
	}
	return 0;
}