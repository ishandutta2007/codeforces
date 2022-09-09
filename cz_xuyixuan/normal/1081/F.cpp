#include<bits/stdc++.h>
using namespace std;
const int MAXN = 305;
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
char ans[MAXN];
int n, t, p;
int main() {
	cin >> n >> t;
	int last = t;
	for (int i = 1; i <= n - 1; i++) {
		int va = -1, vb = last, p = last - t;
		bool solved = false;
		for (int j = 1; j <= 16; j++) {
			cout << '?' << ' ' << i + 1 << ' ' << n << endl;
			int x; cin >> x;
			cout << '?' << ' ' << i + 1 << ' ' << n << endl;
			int y; cin >> y;
			last = y;
			if (va == -1) va = x;
			if (vb == -1) vb = y;
			if (va != x) {
				assert((va + x - i) % 2 == 0);
				int nt = (n - i) - (va + x - i) / 2;
				ans[i] = '0' + (t - nt), t = nt;
				solved = true;
				break;
			}
			if (vb != y) {
				assert((vb + y - i) % 2 == 0);
				int nt = (vb + y - i) / 2;
				ans[i] = '0' + (t - nt), t = nt;
				solved = true;
				break;
			}
		}
		if (!solved) {
			assert(i % 2 == 0);
			ans[i] = i / 2 - p + '0';
			t -= ans[i] - '0';
		}
	}
	ans[n] = '0' + t;
	printf("! %s", ans + 1);
	cout << endl;
	return 0;
}