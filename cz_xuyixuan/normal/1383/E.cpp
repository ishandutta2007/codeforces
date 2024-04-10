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
void update(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}
char s[MAXN]; int m, a[MAXN];
int n, sum, dp[MAXN], aux[MAXN];
int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	int last = 0;
	for (int i = 1; i <= n; i++)
		if (s[i] == '1') {
			a[++m] = i - last - 1;
			last = i;
		}
	if (last == 0) {
		cout << n << endl;
		return 0;
	}
	for (int i = m; i >= 1; i--) {
		dp[i] = (sum + n - last + 1) % P;
		for (int j = 0; j <= a[i]; j++) {
			update(sum, P - aux[j]);
			update(sum, dp[i]);
			aux[j] = dp[i];
		}
	}
	int ans = 0;
	for (int i = 0; s[i] != '1'; i++)
		update(ans, aux[i]);
	cout << ans << endl;
	return 0;
}