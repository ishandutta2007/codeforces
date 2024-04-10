#include<bits/stdc++.h>
using namespace std;
const int MAXN = 17;
const int MAXS = 1 << 16;
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
int a[MAXN]; char s[MAXN];
long long dp[MAXN][MAXN][MAXS];
long long work(bool flg, int pos, int Max, int s) {
	if (pos == 0) {
		return ((1 << Max) & s) != 0;
	}
	if (flg) {
		long long ans = 0;
		for (int i = 0; i <= a[pos]; i++)
			if (pos <= 4) ans += work(i == a[pos], pos - 1, max(Max, i), s ^ (i << (pos - 1) * 4));
			else ans += work(i == a[pos], pos - 1, max(Max, i), s);
		return ans;
	} else {
		if (dp[pos][Max][s] != -1) return dp[pos][Max][s];
		long long ans = 0;
		for (int i = 0; i <= 15; i++)
			if (pos <= 4) ans += work(false, pos - 1, max(Max, i), s ^ (i << (pos - 1) * 4));
			else ans += work(false, pos - 1, max(Max, i), s);
		return dp[pos][Max][s] = ans;
	}
}
long long solve() {
	return work(true, 16, 0, 0);
}
int main() {
	int T; read(T);
	memset(dp, -1, sizeof(dp));
	while (T--) {
		scanf("%s", s + 1);
		int len = strlen(s + 1);
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= len; i++) {
			int now = s[i] - '0';
			if (s[i] >= 'a') now = s[i] - 'a' + 10;
			a[len - i + 1] = now;
		}
		if (len == 1 && a[1] == 0) a[1]++;
		for (int i = 1; true; i++)
			if (a[i]) {
				a[i]--;
				break;
			} else a[i] = 15;
		long long ans = -solve();
		scanf("%s", s + 1);
		len = strlen(s + 1);
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= len; i++) {
			int now = s[i] - '0';
			if (s[i] >= 'a') now = s[i] - 'a' + 10;
			a[len - i + 1] = now;
		}
		ans += solve();
		writeln(ans);
	}
	return 0;
}