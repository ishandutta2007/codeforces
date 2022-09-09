#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
typedef long long ll;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
int main() {
	int T; read(T);
	while (T--) {
		int n; read(n);
		if (n == 1) puts("-1");
		else {
			putchar('2');
			for (int i = 1; i <= n - 1; i++)
				putchar('3');
			putchar('\n');
		}
	}
	return 0;
}