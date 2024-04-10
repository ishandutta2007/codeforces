#include<bits/stdc++.h>
using namespace std;
const int MAXN = 55;
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
int n, m, P, dp[MAXN], limit[MAXN], cnt[MAXN];
void update(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}
int main() {
	m = 30, limit[1] = 1;
	for (int i = 2; i <= m; i++)
		limit[i] = limit[i - 1] * 2 + 1;
	int T; read(T);
	while (T--) {
		read(n), read(P);
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= m; i++)
			if (n <= limit[i - 1]) cnt[i] = 0;
			else if (n <= limit[i]) cnt[i] = n - limit[i - 1];
			else cnt[i] = limit[i] - limit[i - 1];
		int sum = 1;
		for (int i = 1; i <= m; i++) {
			dp[i] = 1ll * cnt[i] * sum % P;
			update(sum, dp[i]);
		}
		update(sum, P - 1);
		printf("%d\n", sum);
	}
	return 0;
}