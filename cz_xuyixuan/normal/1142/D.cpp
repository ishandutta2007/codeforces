#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int MAXS = 105;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
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
int tot, num[11][11][11];
int trans[MAXS][10];
void dfs(int rnk, int lst, int cur) {
	if (num[rnk][lst][cur]) return;
	num[rnk][lst][cur] = ++tot;
	int from = (lst + cur) % 11;
	for (int i = (lst + 1) % 11; i != rnk; i = (i + 1) % 11)
		from = (from + i) % 11;
	int nxt = 0;
	for (int i = lst; i != (lst + cur) % 11; i = (i + 1) % 11)
		nxt = (nxt + i + 1) % 11;
	for (int i = 1; i <= rnk; i++) {
		dfs((from + i) % 11, (lst + cur) % 11, nxt);
		trans[num[rnk][lst][cur]][i - 1] = num[(from + i) % 11][(lst + cur) % 11][nxt];
	}
}
void initstates() {
	for (int i = 1; i <= 9; i++)
		dfs(i, 0, 9);
	//cerr << tot << endl;
}
char s[MAXN]; int n;
int dp[MAXN][MAXS];
int main() {
	initstates();
	scanf("%s", s + 1);
	n = strlen(s + 1);
	ll ans = 0;
	for (int i = n; i >= 1; i--) {
		if (i == n) {
			for (int j = 1; j <= tot; j++)
				dp[i][j] = i;
		} else {
			for (int j = 1; j <= tot; j++) {
				if (trans[j][s[i + 1] - '0']) dp[i][j] = dp[i + 1][trans[j][s[i + 1] - '0']];
				else dp[i][j] = i;
			}
		}
		if (s[i] != '0') {
			int now = dp[i][num[s[i] - '0'][0][9]];
			ans += now - i + 1;
		}
	}
	writeln(ans);
	return 0;
}