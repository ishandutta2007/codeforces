#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e6 + 5;
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
int n, len[MAXN];
int main() {
	int T; read(T);
	while (T--) {
		scanf("%s", s + 1);
		n = strlen(s + 1);
		int Match = 0;
		while (Match < n && s[Match + 1] == s[n - Match]) Match++;
		for (int i = n; i >= 1; i--) {
			s[i * 2] = s[i];
			s[i * 2 + 1] = '#';
		}
		s[n * 2 + 2] = '$', s[1] = '#';
		int pos = 0, Max = 0;
		for (int i = 1; i <= n * 2 + 1; i++) {
			if (i <= Max) len[i] = min(Max - i, len[pos * 2 - i]);
			else len[i] = 0;
			while (s[i - len[i]] == s[i + len[i]]) len[i]++;
			if (i + len[i] - 1 > Max) {
				Max = i + len[i] - 1;
				pos = i;
			}
		}
		int ans = 0, ql = 0, qr = 0;
		for (int i = 2; i <= n * 2; i++) {
			int l = (i - len[i] + 2) / 2, r = (i + len[i] - 2) / 2;
			if (min(l - 1, n - r) <= Match) {
				int tmp = r - l + 1 + min(l - 1, n - r) * 2;
				if (tmp > ans) {
					ans = tmp;
					ql = l, qr = r;
				}
			}
		}
		int now = 0; char res[MAXN];
		for (int i = 1; i <= min(ql - 1, n - qr); i++)
			res[++now] = s[i * 2];
		for (int i = ql; i <= qr; i++)
			res[++now] = s[i * 2];
		for (int i = min(ql - 1, n - qr); i >= 1; i--)
			res[++now] = s[(n - i + 1) * 2];
		res[now + 1] = 0;
		printf("%s\n", res + 1);
	}
	return 0;
}