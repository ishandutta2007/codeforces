#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5005;
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
char s[MAXN];
double Max[26];
int cnt[26], now[26], num[26][26];
int main() {
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	for (int i = 1; i <= n; i++)
		cnt[s[i] - 'a']++;
	for (int i = 1; i <= n - 1; i++) {
		memset(num, 0, sizeof(num));
		memset(now, 0, sizeof(now));
		int k = i + 1;
		for (int j = 1; j <= n; j++) {
			int tmp = ++num[s[j] - 'a'][s[k] - 'a'];
			if (tmp == 1) now[s[j] - 'a']++;
			if (tmp == 2) now[s[j] - 'a']--;
			if (k++ == n) k = 1;
		}
		for (int j = 0; j <= 25; j++)
			Max[j] = max(Max[j], 1.0 * now[j] / n);
	}
	double ans = 0;
	for (int i = 0; i <= 25; i++)
		ans += Max[i];
	printf("%.10lf\n", ans);
	return 0;
}