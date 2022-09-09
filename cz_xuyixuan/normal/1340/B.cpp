#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e3 + 5;
const string value[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
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
bool dp[MAXN][MAXN];
int req[10], cur[MAXN], bits[MAXN];
int main() {
	int n, k; read(n), read(k);
	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 6; j++)
			req[i] = req[i] * 2 + value[i][j] - '0';
	}
	for (int i = 1; i <= 1023; i++)
		bits[i] = bits[i / 2] + i % 2;
	for (int i = 1; i <= n; i++) {
		char s[10]; scanf("\n%s", s);
		for (int j = 0; j <= 6; j++)
			cur[i] = cur[i] * 2 + s[j] - '0';
	}
	dp[n + 1][0] = true;
	for (int i = n; i >= 1; i--)
	for (int j = 0; j <= k; j++) {
		if (dp[i + 1][j]) {
			for (int l = 0; l <= 9; l++)
				if ((req[l] | cur[i]) == req[l]) {
					int tmp = j + bits[req[l] ^ cur[i]];
					if (tmp <= k) dp[i][tmp] = true;
				}
		}
	}
	if (!dp[1][k]) puts("-1");
	else {
		for (int i = 1; i <= n; i++)
		for (int l = 9; l >= 0; l--) {
			if ((req[l] | cur[i]) == req[l]) {
				int tmp = k - bits[req[l] ^ cur[i]];
				if (tmp >= 0 && dp[i + 1][tmp]) {
					k = tmp;
					putchar(l + '0');
					break;
				}
			}
		}
		puts("");
	}
	return 0;
}