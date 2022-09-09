#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
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
char s[MAXN]; ull bit[MAXN], h[MAXN];
int n, q, pre[MAXN], sum[MAXN];
int rnk[MAXN], home[MAXN];
ull cal(int x, int cnt) {
	return h[x] - h[x - cnt] * bit[cnt];
}
bool cmp(int x, int y, int cnt) {
	return cal(rnk[x], cnt) == cal(rnk[y], cnt);
}
int main() {
	read(n), bit[0] = 1;
	scanf("\n%s", s + 1);
	for (int i = 1; i <= n; i++) {
		bit[i] = bit[i - 1] * 37;
		sum[i] = sum[i - 1] + (s[i] == '0');
		pre[i] = pre[i - 1];
		if (s[i] == '0') {
			pre[i] = i;
			rnk[i] = sum[i];
			home[sum[i]] = i;
			h[sum[i]] = h[sum[i] - 1] * 37;
			if ((i - pre[i - 1]) % 2) h[sum[i]] += 5;
			else h[sum[i]] += 19;
		}
	}
	read(q);
	while (q--) {
		int x, y, len;
		read(x), read(y), read(len);
		x += len - 1, y += len - 1;
		if (sum[x] - sum[x - len] != sum[y] - sum[y - len]) puts("No");
		else {
			int cnt = sum[x] - sum[x - len];
			if (cnt == 0) puts("Yes");
			else if ((x - pre[x]) % 2 != (y - pre[y]) % 2) puts("No");
			else if (cmp(pre[x], pre[y], cnt - 1)) puts("Yes");
			else puts("No");
		}
	}
	return 0;
}