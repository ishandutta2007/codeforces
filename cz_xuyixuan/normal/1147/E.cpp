#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
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
bool f[MAXN], g[MAXN];
int n, m, a[MAXN], ans[MAXN];
int main() {
	int T; read(T);
	while (T--) {
		read(n), m = 0;
		memset(f, false, sizeof(f));
		memset(g, false, sizeof(g));
		memset(ans, 0, sizeof(ans));
		if (n >= 2) {
			printf("Q %d", n / 2);
			for (int i = 2; i <= n; i += 2)
				printf(" %d %d", i - 1, i);
			cout << endl; string s; cin >> s;
			for (int i = 2, j = 0; i <= n; i += 2, j++)
				f[i] = s[j] == '1';
		}
		if (n >= 3) {
			printf("Q %d", (n - 1) / 2);
			for (int i = 3; i <= n; i += 2)
				printf(" %d %d", i - 1, i);
			cout << endl; string s; cin >> s;
			for (int i = 3, j = 0; i <= n; i += 2, j++)
				f[i] = s[j] == '1';
		}
		for (int i = 1; i <= n; i++)
			if (!f[i]) a[++m] = i;
		if (m >= 3) {
			int cnt = 0;
			for (int i = 3; i <= m; i += 4)
				cnt += 1 + (i != m);
			printf("Q %d", cnt);
			for (int i = 3; i <= m; i += 4) {
				printf(" %d %d", a[i], a[i - 2]);
				if (i != m) printf(" %d %d", a[i + 1], a[i - 1]);
			}
			cout << endl; string s; cin >> s;
			for (int i = 3, j = 0; i <= m; i += 4, j += 2) {
				g[a[i]] = s[j] == '1';
				if (i != m) g[a[i + 1]] = s[j + 1] == '1';
			}
		}
		if (m >= 5) {
			int cnt = 0;
			for (int i = 5; i <= m; i += 4)
				cnt += 1 + (i != m);
			printf("Q %d", cnt);
			for (int i = 5; i <= m; i += 4) {
				printf(" %d %d", a[i], a[i - 2]);
				if (i != m) printf(" %d %d", a[i + 1], a[i - 1]);
			}
			cout << endl; string s; cin >> s;
			for (int i = 5, j = 0; i <= m; i += 4, j += 2) {
				g[a[i]] = s[j] == '1';
				if (i != m) g[a[i + 1]] = s[j + 1] == '1';
			}
		}
		ans[a[1]] = 0; if (m >= 2) ans[a[2]] = 1;
		for (int i = 3; i <= m; i++) {
			if (g[a[i]]) ans[a[i]] = ans[a[i - 2]];
			else while (ans[a[i]] == ans[a[i - 1]] || ans[a[i]] == ans[a[i - 2]]) ans[a[i]]++;
		}
		for (int i = 1; i <= n; i++)
			if (f[i]) ans[i] = ans[i - 1];
		int cnt[3] = {0, 0, 0};
		for (int i = 1; i <= n; i++)
			cnt[ans[i]]++;
		printf("A %d %d %d\n", cnt[0], cnt[1], cnt[2]);
		for (int t = 0; t <= 2; t++) {
			for (int i = 1; i <= n; i++)
				if (ans[i] == t) printf("%d ", i);
			cout << endl;
		}
	}
	return 0;
}