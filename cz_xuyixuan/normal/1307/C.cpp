#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
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
char s[MAXN];
int pre[MAXN][26]; ll cnt[26][26];
int main() {
	scanf("\n%s", s + 1);
	int n = strlen(s + 1);
	for (int i = 1; i <= n; i++) {
		memcpy(pre[i], pre[i - 1], sizeof(pre[i - 1]));
		for (int j = 0; j <= 25; j++)
			cnt[j][s[i] - 'a'] += pre[i][j];
		pre[i][s[i] - 'a']++;
	}
	ll ans = 0;
	for (int i = 0; i <= 25; i++)
		chkmax(ans, 0ll + pre[n][i]);
	for (int i = 0; i <= 25; i++)
	for (int j = 0; j <= 25; j++)
		chkmax(ans, cnt[i][j]);
	cout << ans << endl;
	return 0;
}