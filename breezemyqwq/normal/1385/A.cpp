#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b, c, x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		if (x != y && y != z && x != z) {
			puts("NO");
			continue;
		}
		if (x == y && y == z) a = b = c = x;
		else if (x == y) {
			if (x < z) {
				puts("NO");
				continue;
			}
			a = x, b = z, c = 1;
		}
		else if (y == z) {
			if(y < x) {
				puts("NO");
				continue;
			}
			c = y, a = x, b = 1;
		}
		else if (x == z) {
			if(x < y) {
				puts("NO");
				continue;
			}
			b = x, a = y, c = 1;
		}
		puts("YES");
		printf("%d %d %d\n", a, b, c);
	}
	return 0;
}