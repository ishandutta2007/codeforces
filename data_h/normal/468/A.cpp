#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

int n;

int main() {
	scanf("%d", &n);
	if (n < 4) {
		puts("NO");
	} else if (n % 2 == 0) {
		int cnt = 0;
		puts("YES");
		for(int i = n; i > 4; i -= 2) {
			printf("%d - %d = 1\n", i, i - 1);
			cnt++;
		}
		for(int i = 1; i <= cnt; i++) {
			printf("%d * %d = 1\n", 1, 1, 1);
		}
		puts("2 * 3 = 6");
		puts("6 * 4 = 24");
		puts("24 * 1 = 24");
	} else {
		int cnt = 0;
		puts("YES");
		for(int i = n; i > 5; i -= 2) {
			printf("%d - %d = 1\n", i, i - 1);
			cnt++;
		}
		for(int i = 1; i <= cnt; i++) {
			printf("%d * %d = 1\n", 1, 1, 1);
		}
		puts("4 * 5 = 20");
		puts("20 + 2 = 22");
		puts("22 + 3 = 25");
		puts("25 - 1 = 24");
	}
	return 0;
}