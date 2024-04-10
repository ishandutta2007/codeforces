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
int n, P, a[MAXN];
int main() {
	read(n), read(P);
	if (n > P) puts("0");
	else {
		int ans = 1;
		for (int i = 1; i <= n; i++)
			read(a[i]);
		sort(a + 1, a + n + 1);
		for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			ans = 1ll * ans * (a[j] - a[i]) % P;
		cout << ans << endl;
	}
	return 0;
}