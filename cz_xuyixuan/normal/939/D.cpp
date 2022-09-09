#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int MAXC = 30;
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
int n, ans, cnt;
char s[MAXN], t[MAXN];
char x[MAXC], y[MAXC], q[MAXC];
bool used[MAXC], mp[MAXC][MAXC];
void work(int pos) {
	used[pos] = false;
	q[++cnt] = pos + 'a';
	for (int i = 0; i <= 25; i++)
		if (used[i] && mp[pos][i]) work(i);
}
int main() {
	read(n);
	scanf("\n%s", s + 1);
	scanf("\n%s", t + 1);
	for (int i = 1; i <= n; i++)
		if (s[i] != t[i]) {
			mp[s[i] - 'a'][t[i] - 'a'] = mp[t[i] - 'a'][s[i] - 'a'] = true;
			used[s[i] - 'a'] = used[t[i] - 'a'] = true;
		}
	for (int i = 0; i <= 25; i++)
		if (used[i]) {
			cnt = 0;
			work(i);
			for (int j = 2; j <= cnt; j++) {
				ans++;
				x[ans] = q[j - 1];
				y[ans] = q[j];
			}
		}
	writeln(ans);
	for (int i = 1; i <= ans; i++)
		printf("%c %c\n", x[i], y[i]);
	return 0;
}