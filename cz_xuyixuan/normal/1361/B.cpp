#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
const int P = 1e9 + 7;
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
int n, k, a[MAXN];
int power(int x, int y) {
	if (y == 0) return 1;
	int tmp = power(x, y / 2);
	if (y % 2 == 0) return 1ll * tmp * tmp % P;
	else return 1ll * tmp * tmp % P * x % P;
}
int func(int x, int y) {
	if (x == 0 || k == 1) return x;
	while (y-- && x < P) {
		if (1ll * x * k >= P) x = P;
		else x *= k;
	}
	return x;
}
void update(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}
int main() {
	int T; read(T);
	while (T--) {
		read(n), read(k);
		for (int i = 1; i <= n; i++)
			read(a[i]);
		sort(a + 1, a + n + 1);
		reverse(a + 1, a + n + 1);
		int ans = 0, cur = 0;
		for (int i = 1; i <= n; i++) {
			if (i != 1) cur = func(cur, a[i - 1] - a[i]);
			if (cur == 0) update(ans, power(k, a[i])), cur++;
			else update(ans, P - power(k, a[i])), cur--;
		}
		printf("%d\n", ans);
	}
	return 0;
}