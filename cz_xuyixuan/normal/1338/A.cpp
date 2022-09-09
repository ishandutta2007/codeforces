#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
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
int n, Max, ans;
int main() {
	int T; read(T);
	while (T--) {
		read(n), Max = -INF, ans = 0;
		for (int i = 1; i <= n; i++) {
			int x; read(x);
			chkmax(Max, x);
			chkmax(ans, Max - x);
		}
		int res = 0;
		while (ans) {
			res++;
			ans >>= 1;
		}
		printf("%d\n", res);
	}
	return 0;
}