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
int a[MAXN], b[MAXN];
int main() {
	int T; read(T);
	while (T--) {
		int n; read(n);
		for (int i = 1; i <= n; i++)
			read(a[i]);
		for (int i = 1; i <= n; i++)
			read(b[i]);
		sort(a + 1, a + n + 1);
		sort(b + 1, b + n + 1);
		for (int i = 1; i <= n; i++)
			printf("%d ", a[i]);
		printf("\n");
		for (int i = 1; i <= n; i++)
			printf("%d ", b[i]);
		printf("\n");
	}
	return 0;
}