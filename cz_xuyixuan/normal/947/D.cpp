#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
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
char s[MAXN], t[MAXN], ans[MAXN];
int sa[MAXN], sb[MAXN], sp[MAXN];
int ta[MAXN], tb[MAXN], tp[MAXN];
int main() {
	scanf("\n%s\n%s", s + 1, t + 1);
	int ls = strlen(s + 1);
	int lt = strlen(t + 1);
	for (int i = 1; i <= ls; i++) {
		sa[i] = sa[i - 1] + (s[i] == 'A');
		sb[i] = sb[i - 1] + (s[i] != 'A');
		if (s[i] != 'A') sp[i] = i;
		else sp[i] = sp[i - 1];
	}
	for (int i = 1; i <= lt; i++) {
		ta[i] = ta[i - 1] + (t[i] == 'A');
		tb[i] = tb[i - 1] + (t[i] != 'A');
		if (t[i] != 'A') tp[i] = i;
		else tp[i] = tp[i - 1];
	}
	int q; read(q);
	for (int i = 1; i <= q; i++) {
		int a, b, c, d;
		read(a), read(b), read(c), read(d);
		int suma = sa[b] - sa[max(sp[b], a - 1)];
		int sumb = sb[b] - sb[a - 1];
		int tuma = ta[d] - ta[max(tp[d], c - 1)];
		int tumb = tb[d] - tb[c - 1];
		if (suma < tuma || (sumb + tumb) % 2 == 1) ans[i] = '0';
		else if (suma % 3 == tuma % 3) {
			if (sumb > tumb) ans[i] = '0';
			else {
				if (sumb == 0 && tumb != 0 && suma == tuma) ans[i] = '0';
				else ans[i] = '1';
			}
		} else {
			sumb += 2;
			if (sumb > tumb) ans[i] = '0';
			else ans[i] = '1';
		}
	}
	printf("%s\n", ans + 1);
	return 0;
}