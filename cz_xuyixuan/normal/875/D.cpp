#include<bits/stdc++.h>
using namespace std;
#define MAXN	200005
#define MAXLOG	31
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
struct info {int x, y, z; };
int n, a[MAXN], t[MAXN];
info ans[MAXN];
int pre[MAXN][MAXLOG], nxt[MAXN][MAXLOG];
long long func(long long x) {
	return x * (x - 1) / 2;
}
bool cmp(info a, info b) {
	if (a.x == b.x) return a.y < b.y;
	else return a.x < b.x;
}
int main() {
	read(n);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	for (int i = 2; i <= n; i++) {
		int tmp = a[i - 1];
		for (int j = 0; j < MAXLOG; j++, tmp >>= 1)
			if (tmp & 1) pre[i][j] = i - 1;
			else pre[i][j] = pre[i - 1][j];
	}
	for (int i = 0; i < MAXLOG; i++)
		nxt[n][i] = n + 1;
	for (int i = n - 1; i >= 1; i--) {
		int tmp = a[i + 1];
		for (int j = 0; j < MAXLOG; j++, tmp >>= 1)
			if (tmp & 1) nxt[i][j] = i + 1;
			else nxt[i][j] = nxt[i + 1][j];
	}
	for (int i = 1; i <= n; i++) {
		int tx = 1, ty = n, tmp = a[i];
		for (int j = 0; j < MAXLOG; j++, tmp >>= 1)
			if ((tmp & 1) == 0) {
				tx = max(tx, pre[i][j] + 1);
				ty = min(ty, nxt[i][j] - 1);
			}
		ans[i] = (info) {tx, ty, i};
	}
	sort(ans + 1, ans + n + 1, cmp);
	long long finalans = func(n);
	int pos = 1;
	while (pos <= n) {
		int tmp = pos;
		while (pos <= n && ans[pos].x == ans[tmp].x && ans[pos].y == ans[tmp].y) pos++;
		finalans -= func(ans[tmp].y - ans[tmp].x + 1);
		int tot = 0;
		t[0] = ans[tmp].x - 1;
		for (int i = tmp; i < pos; i++)
			t[++tot] = ans[i].z;
		sort(t + 1, t + tot + 1);
		t[tot + 1] = ans[tmp].y + 1;
		for (int i = 1; i <= tot + 1; i++)
			finalans += func(t[i] - t[i - 1] - 1);	
	}
	cout << finalans << endl;
	return 0;
}