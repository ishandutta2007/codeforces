#include <bits/stdc++.h>

using namespace std;

int ans = 0;

int main() {
	printf("? "); for(int i = 1; i <= 100; i++) printf("%d ", i); puts("");
	fflush(stdout);
	int t1; scanf("%d", &t1);
	t1 = (t1 & (128 * 127));
	ans += t1;
	printf("? "); for(int i = 1; i <= 100; i++) printf("%d ", 128 * i); puts("");
	fflush(stdout);
	int t2; scanf("%d", &t2);
	t2 = (t2 & 127);
	ans += t2;
	printf("! %d\n", ans);
	fflush(stdout);

	return 0;
}