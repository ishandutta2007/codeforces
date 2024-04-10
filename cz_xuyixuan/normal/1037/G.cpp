#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int MAXP = 5200005;
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
struct info {int l, r, len; } b[MAXP];
char s[MAXN]; int n, q, tot, a[MAXN];
int sg[MAXN][27][2], sum[MAXN][27], last;
int pre[MAXN][27], suf[MAXN][27];
bool cmp(info a, info b) {
	if (a.r == b.r) return a.len < b.len;
	else return a.r < b.r;
}
int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1), read(q);
	for (int i = 1; i <= n; i++)
		a[i] = s[i] - 'a';
	a[0] = a[n + 1] = 26;
	b[tot = 1] = (info) {1, n, n};
	for (int c = 0; c <= 25; c++) {
		int pos = 1;
		for (int i = 1; i <= n; i++)
			if (a[i] == c) {
				if (i != pos) {
					b[++tot] = (info) {pos, i - 1, i - pos};
					static int tmp[26];
					memset(tmp, 0, sizeof(tmp));
					for (int j = pos; j <= i - 1; j++)
						tmp[a[j]] = j;
					for (int j = 0; j <= 25; j++)
						if (tmp[j] != 0 && tmp[j] != i - 1) b[++tot] = (info) {tmp[j] + 1, i - 1, i - (tmp[j] + 1)};
				}
				pos = i + 1;
			}
		if (pos <= n) b[++tot] = (info) {pos, n, n - pos + 1};
	}
	sort(b + 1, b + tot + 1, cmp);
	for (int i = 1; i <= tot; i++) {
		static int Min[26], Max[26];
		memset(Min, 0, sizeof(Min));
		memset(Max, 0, sizeof(Max));
		for (int j = b[i].l; j <= b[i].r; j++) {
			if (Min[a[j]] == 0) Min[a[j]] = j;
			Max[a[j]] = j;
			static bool tmp[32];
			memset(tmp, false, sizeof(tmp));
			for (int k = 0; k <= 25; k++) {
				if (Min[k] == 0) continue;
				tmp[sum[Min[k]][k] ^ sum[Max[k]][k] ^ sg[b[i].l][k][1] ^ sg[j][k][0]] = true;
			}
			int ans = 0;
			while (tmp[ans] == true) ans++;
			sg[j][a[b[i].l - 1]][0] = ans;
		}
		memset(Min, 0, sizeof(Min));
		memset(Max, 0, sizeof(Max));
		for (int j = b[i].r; j >= b[i].l; j--) {
			if (Max[a[j]] == 0) Max[a[j]] = j;
			Min[a[j]] = j;
			static bool tmp[32];
			memset(tmp, false, sizeof(tmp));
			for (int k = 0; k <= 25; k++) {
				if (Min[k] == 0) continue;
				tmp[sum[Min[k]][k] ^ sum[Max[k]][k] ^ sg[j][k][1] ^ sg[b[i].r][k][0]] = true;
			}
			int ans = 0;
			while (tmp[ans] == true) ans++;
			sg[j][a[b[i].r + 1]][1] = ans;
		}
		while (last < b[i].r) {
			last++;
			for (int j = 0; j <= 25; j++)
				sum[last][j] = sum[last - 1][j];
		}
		if (a[b[i].l - 1] == a[b[i].r + 1]) {
			int tmp = a[b[i].l - 1];
			sum[b[i].r][tmp] ^= sg[b[i].l][a[b[i].r + 1]][1];
		}
	}
	for (int i = 1; i <= n; i++) {
		memcpy(pre[i], pre[i - 1], sizeof(pre[i - 1]));
		pre[i][a[i]] = i;
	}
	for (int i = 0; i <= 25; i++)
		suf[n + 1][i] = n + 1;
	for (int i = n; i >= 1; i--) {
		memcpy(suf[i], suf[i + 1], sizeof(suf[i + 1]));
		suf[i][a[i]] = i;
	}
	for (int i = 1; i <= q; i++) {
		static bool tmp[32];
		memset(tmp, false, sizeof(tmp));
		int l, r; read(l), read(r);
		for (int j = 0; j <= 25; j++) {
			if (suf[l][j] > pre[r][j]) continue;
			tmp[sum[suf[l][j]][j] ^ sum[pre[r][j]][j] ^ sg[l][j][1] ^ sg[r][j][0]] = true;
		}
		if (tmp[0]) printf("Alice\n");
		else printf("Bob\n");
	}
	return 0;
}