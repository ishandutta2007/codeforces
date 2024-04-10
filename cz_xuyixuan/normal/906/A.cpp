#include<bits/stdc++.h>
using namespace std;
#define MAXN	100005
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T> void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> void writeln(T x) {
	write(x);
	puts("");
}
char s[MAXN], opt;
bool now[26], imp[26];
int main() {
	int n; read(n);
	for (int i = 1; i <= n; i++) {
		scanf("\n%c %s", &opt, s + 1);
		int len = strlen(s + 1);
		if (opt == '?') imp[s[1] - 'a'] = true;
		if (opt == '.') {
			for (int j = 1; j <= len; j++)
				imp[s[j] - 'a'] = true;
		}
		if (opt == '!') {
			memset(now, 0, sizeof(now));
			for (int j = 1; j <= len; j++)
				now[s[j] - 'a'] = true;
			for (int j = 0; j <= 25; j++)
				if (now[j] == false) imp[j] = true;
		}
		int cnt = 0;
		for (int j = 0; j <= 25; j++)
			cnt += imp[j];
		if (cnt == 25) {
			int ans = -1;
			for (int j = i + 1; j <= n; j++) {
				scanf("\n%c %s", &opt, s + 1);
				if (opt != '.') ans++;
			}
			printf("%d\n", ans);
			return 0;
		}
	}
	printf("%d\n", 0);
	return 0;
}