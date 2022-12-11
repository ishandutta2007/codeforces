#include <stdio.h>
#include <ctype.h>
#include <string.h>
bool vis[26];
int n, c, cnt, ans;
int main() {
	scanf("%d\n", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%c", &c);
		if (isupper(c)) {
			memset(vis, 0, sizeof vis);
			cnt = 0;
		} else if (!vis[c - 97]) cnt++, vis[c - 97] = 1;
		if (ans < cnt) ans = cnt;
	}
	printf("%d\n", ans);
	return 0;
}