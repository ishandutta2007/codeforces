#include<bits/stdc++.h>
using namespace std;
#define MAXN	2505
#define MAXM	5005
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
int n, m, cnt[256], now[256];
int diff[MAXN];
char a[MAXN][MAXM];
bool multiexist;
bool check(int x, int y) {
	for (int i = 2; i <= n; i++) {
		int tmp = diff[i];
		tmp -= a[1][x] != a[i][x];
		tmp -= a[1][y] != a[i][y];
		tmp += a[1][x] != a[i][y];
		tmp += a[1][y] != a[i][x];
		if (tmp > 2 || (tmp == 0 && !multiexist)) return false;
	}
	return true;
}
bool invalid() {
	for (int i = 1; i <= m; i++)
		cnt[a[1][i]]++;
	for (int i = 2; i <= n; i++) {
		memset(now, 0, sizeof(now));
		for (int j = 1; j <= m; j++)
			now[a[i][j]]++;
		for (int j = 'a'; j <= 'z'; j++)
			if (now[j] != cnt[j]) return true;
	}
	for (int i = 'a'; i <= 'z'; i++)
		if (cnt[i] >= 2) multiexist = true;
	return false;
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		scanf("\n%s", a[i] + 1);
	if (invalid()) {
		printf("-1\n");
		return 0;
	}
	for (int i = 2; i <= n; i++)
	for (int j = 1; j <= m; j++)
		diff[i] += a[1][j] != a[i][j];
	for (int i = 1; i <= m; i++)
	for (int j = i + 1; j <= m; j++)
		if (check(i, j)) {
			swap(a[1][i], a[1][j]);
			printf("%s\n", a[1] + 1);
			return 0;
		}
	printf("-1\n");
	return 0;
}