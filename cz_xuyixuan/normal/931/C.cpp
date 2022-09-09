#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
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
int Min, Max, a[MAXN], cnt[10], ant[10];
int main() {
	int n; read(n);
	for (int i = 1; i <= n; i++) {
		read(a[i]);
		if (i == 1) Min = Max = a[i];
		else Min = min(Min, a[i]), Max = max(Max, a[i]);
	}
	if (Max - Min <= 1) {
		printf("%d\n", n);
		for (int i = 1; i <= n; i++)
			printf("%d ", a[i]);
		return 0;
	}
	for (int i = 1; i <= n; i++)
		cnt[a[i] - Min]++;
	int ans = -1;
	for (int i = -n; i <= n; i++) {
		if (cnt[1] - 2 * i < 0) continue;
		if (cnt[2] + i < 0 || cnt[0] + i < 0) continue;
		int now = 0;
		now += max(cnt[1], cnt[1] - 2 * i) - cnt[1];
		now += max(cnt[0], cnt[0] + i) - cnt[0];
		now += max(cnt[2], cnt[2] + i) - cnt[2];
		if (now > ans) {
			ans = now;
			ant[0] = cnt[0] + i;
			ant[1] = cnt[1] - 2 * i;
			ant[2] = cnt[2] + i;
		}
	}
	writeln(n - ans);
	for (int i = 1; i <= ant[0]; i++)
		printf("%d ", Min);
	for (int i = 1; i <= ant[1]; i++)
		printf("%d ", Min + 1);
	for (int i = 1; i <= ant[2]; i++)
		printf("%d ", Min + 2);
	return 0;
}