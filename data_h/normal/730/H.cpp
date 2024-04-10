#include <bits/stdc++.h>
using namespace std;
const int N = 105;
char s[N][N], ans[N];
bool del[N];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++ i) scanf("%s", s[i]);
	bool flag = 1;
	int len = 0;
	for (int i = 1; i <= m; ++ i) {
		int ban;
		scanf("%d", &ban);
		del[ban] = 1;
		if (i == 1) {
			len = (int) strlen(s[ban]);
			for (int j = 0; j < len; ++ j) ans[j] = s[ban][j];
		}
		if ((int) strlen(s[ban]) != len) flag = 0;
		for (int j = 0; j < len; ++ j) if (s[ban][j] != ans[j] && ans[j] != '?') ans[j] = '?';
	}
	for (int i = 1; i <= n; ++ i) {
		if (del[i]) continue;
		if ((int) strlen(s[i]) != len) continue;
		bool tmp = 1;
		for (int j = 0; j < len; ++ j) {
			if (s[i][j] != ans[j] && ans[j] != '?') tmp = 0;
		}
		if (tmp) flag = 0;
	}
	if (flag) {
		puts("Yes");
		puts(ans);
	}
	else puts("No");
}