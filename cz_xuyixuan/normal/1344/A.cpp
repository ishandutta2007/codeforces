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
int n, a[MAXN], b[MAXN];
int main() {
	int T; read(T);
	while (T--) {
		read(n);
		for (int i = 0; i <= n - 1; i++) {
			read(a[i]), b[i] = 0;
			a[i] = (a[i] % n + n) % n;
		}
		for (int i = 0; i <= n - 1; i++)
			b[(i + a[i]) % n]++;
		bool ans = true;
		for (int i = 0; i <= n - 1; i++)
			ans &= b[i] == 1;
		if (ans) puts("Yes");
		else puts("No");
	}
	return 0;
}