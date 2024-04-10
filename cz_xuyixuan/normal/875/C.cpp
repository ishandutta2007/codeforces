#include<bits/stdc++.h>
using namespace std;
#define MAXN	100005
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
vector <int> a[MAXN], b[MAXN];
int len[MAXN];
bool ans[MAXN];
int main() {
	int n, m;
	read(n), read(m);
	for (int i = 1; i <= n; i++) {
		read(len[i]);
		for (int j = 1; j <= len[i]; j++) {
			int x; read(x);
			a[i].push_back(x);
		}
	}
	for (int i = 2; i <= n; i++) {
		bool flg = true;
		int goal = min(len[i - 1], len[i]);
		for (int j = 0; j < goal; j++) {
			if (a[i - 1][j] == a[i][j]) continue;
			if (a[i - 1][j] < a[i][j]) b[a[i][j]].push_back(a[i - 1][j]);
			else ans[a[i - 1][j]] = true;
			flg = false; break;
		}
		if (flg && len[i - 1] > len[i]) {
			printf("No\n");
			return 0;
		}
	}
	for (int i = m; i >= 1; i--)
	for (unsigned j = 0; j < b[i].size(); j++)
		ans[b[i][j]] |= ans[i];
	for (int i = 2; i <= n; i++) {
		bool flg = true;
		int goal = min(len[i - 1], len[i]);
		for (int j = 0; j < goal; j++) {
			if (a[i - 1][j] == a[i][j]) continue;
			if (a[i - 1][j] > a[i][j] && ans[a[i][j]]) {
				printf("No\n");
				return 0;
			}
			flg = false; break;
		}
		if (flg && len[i - 1] > len[i]) {
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	static int tot = 0, finalans[MAXN];
	for (int i = 1; i <= m; i++)
		if (ans[i]) finalans[++tot] = i;
	printf("%d\n", tot);
	for (int i = 1; i <= tot; i++)
		printf("%d ", finalans[i]);
	return 0;
}