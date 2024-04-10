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
bool ans[MAXN];
vector <int> a[MAXN], b[MAXN], c[MAXN];
int main() {
	int n, k; read(n), read(k);
	if (k == 1) {
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			bool res = true;
			for (int j = 1; j <= i - 1; j++) {
				char c;
				cout << '?' << ' ' << i << endl;
				scanf("\n%c", &c);
				cout << '?' << ' ' << j << endl;
				scanf("\n%c", &c);
				cout << 'R' << endl;
				if (c == 'Y') res = false;
			}
			ans += res;
		}
		cout << '!' << ' ' << ans << endl;
	} else {
		for (int i = 1; i <= n; i++)
			ans[i] = true;
		int m = n / (k / 2);
		for (int i = 1, j = 1; i <= m; i++, j += k / 2)
		for (int l = 1; l <= k / 2; l++)
			a[i].push_back(j + l - 1);
		int cnt = 0;
		for (int i = 1; i <= m; i++)
		for (int j = 1; j <= i - 1; j++) {
			if (b[j].size()) {
				int tmp = b[j].back();
				b[j].pop_back();
				c[tmp].push_back(i);
				b[i].push_back(tmp);
			} else {
				cnt++;
				c[cnt].push_back(j);
				c[cnt].push_back(i);
				b[i].push_back(cnt);
			}
		}
		for (int i = 1; i <= cnt; i++) {
			for (auto y : c[i])
			for (auto x : a[y]) {
				char t;
				cout << '?' << ' ' << x << endl;
				scanf("\n%c", &t);
				if (t == 'Y') ans[x] = false;
			}
			cout << 'R' << endl;
		}
		int final = 0;
		for (int i = 1; i <= n; i++)
			final += ans[i];
		cout << '!' << ' ' << final << endl;
	}
	return 0;
}