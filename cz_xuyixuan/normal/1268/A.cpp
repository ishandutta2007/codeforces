#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
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
char s[MAXN], t[MAXN];
int main() {
	int n, k; read(n), read(k);
	scanf("\n%s", s + 1);
	for (int i = 1; i <= k; i++)
	for (int j = i; j <= n; j += k)
		t[j] = s[i];
	bool flg = true;
	for (int i = 1; i <= n; i++) {
		if (t[i] > s[i]) {
			flg = true;
			break;
		}
		if (t[i] < s[i]) {
			flg = false;
			break;
		}
	}
	cout << n << endl;
	if (flg) printf("%s\n", t + 1);
	else {
		s[k]++; int tmp = k;
		while (s[tmp] > '9') {
			s[tmp] = '0';
			tmp--;
			s[tmp]++;
		}
		for (int i = 1; i <= k; i++)
		for (int j = i; j <= n; j += k)
			t[j] = s[i];
		printf("%s\n", t + 1);
	}
	return 0;
}