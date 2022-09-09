#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
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
map <string, int> mp, fb, home;
string a[MAXN], b[MAXN], ans[MAXN];
int main() {
	int n; read(n);
	for (int i = 1; i <= n; i++) {
		string x, y;
		cin >> x >> y;
		a[i] = x[0];
		a[i] += x[1];
		a[i] += x[2];
		b[i] = x[0];
		b[i] += x[1];
		b[i] += y[0];
		mp[a[i]]++;
	}
	static int q[MAXN];
	int l = 0, r = -1;
	for (int i = 1; i <= n; i++)
		if (mp[a[i]] == 1) home[a[i]] = i;
		else q[++r] = i;
	while (l <= r) {
		int tmp = q[l++];
		if (fb[b[tmp]]) {
			printf("NO\n");
			return 0;
		}
		fb[b[tmp]]++;
		ans[tmp] = b[tmp];
		if (home[b[tmp]]) q[++r] = home[b[tmp]];
	}
	printf("YES\n");
	for (int i = 1; i <= n; i++)
		if (ans[i] == "") cout << a[i] << endl;
		else cout << ans[i] << endl;
	return 0;
}