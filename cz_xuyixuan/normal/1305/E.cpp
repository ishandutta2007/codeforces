#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
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
int n, m, a[MAXN];
int main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		a[i] = 5e8 + 2e4 * i;
	for (int i = 1; i <= n; i++) {
		if ((i - 1) / 2 <= m) {
			a[i] = i;
			m -= (i - 1) / 2;
		} else {
			a[i] = i - 1 + (i - 2 * m);
			m = 0;
			break;
		}
	}
	if (m > 0) {
		puts("-1");
		return 0;
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}