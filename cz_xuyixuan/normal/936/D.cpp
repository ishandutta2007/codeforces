#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2000005;
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
int n, m1, m2, m, t;
int x1[MAXN], x2[MAXN];
int mid1[MAXN], mid2[MAXN];
int pos1[MAXN], pos2[MAXN];
int dp[3][MAXN], path[3][MAXN], pos[MAXN];
int main() {
	read(n), read(m1), read(m2), read(t);
	for (int i = 1; i <= m1; i++)
		read(x1[i]);
	for (int i = 1; i <= m2; i++)
		read(x2[i]);
	pos[++m] = 0;
	int p1 = 1, p2 = 1;
	while (p1 <= m1 || p2 <= m2) {
		if (p1 > m1) pos[++m] = x2[p2++] + 1;
		else if (p2 > m2) pos[++m] = x1[p1++] + 1;
		else {
			int Min = min(x1[p1], x2[p2]);
			pos[++m] = Min + 1;
			if (Min == x1[p1]) p1++;
			if (Min == x2[p2]) p2++;
		}
	}
	if (pos[m] != n + 1) pos[++m] = n + 1;
	p1 = 1;
	for (int i = 1; i <= m1; i++) {
		while (x1[i] > pos[p1]) p1++;
		if (pos[p1] > x1[i]) mid1[p1] = x1[i];
		pos1[p1] += x1[i] == pos[p1];
	}
	p2 = 1;
	for (int i = 1; i <= m2; i++) {
		while (x2[i] > pos[p2]) p2++;
		if (pos[p2] > x2[i]) mid2[p2] = x2[i];
		pos2[p2] += x2[i] == pos[p2];
	}
	memset(dp, -1, sizeof(dp));
	dp[1][1] = 0;
	for (int i = 1; i <= m - 1; i++) {
		if (dp[1][i] != -1 && pos2[i] == 0) {
			int tmp = min(dp[1][i], t);
			if (tmp > dp[2][i]) {
				dp[2][i] = tmp;
				path[2][i] = 1;
			}
		}
		if (dp[2][i] != -1 && pos1[i] == 0) {
			int tmp = min(dp[2][i], t);
			if (tmp > dp[1][i]) {
				dp[1][i] = tmp;
				path[1][i] = 1;
			}
		}
		if (dp[1][i] != -1) {
			int tmp = dp[1][i];
			if (pos1[i + 1] == 0 && mid1[i + 1] == 0) tmp += pos[i + 1] - pos[i];
			if (pos1[i + 1] == 0 && mid1[i + 1] != 0) {
				tmp += mid1[i + 1] - pos[i] - 1;
				if (tmp < t) tmp = -1;
				else tmp -= t;
				if (tmp != -1) tmp += pos[i + 1] - mid1[i + 1] + 1;
			}
			if (pos1[i + 1] != 0 && mid1[i + 1] == 0) {
				tmp += pos[i + 1] - pos[i] - 1;
				if (tmp < t) tmp = -1;
				else tmp -= t;
				if (tmp != -1) tmp += 1;
			}
			if (pos1[i + 1] != 0 && mid1[i + 1] != 0) {
				tmp += mid1[i + 1] - pos[i] - 1;
				if (tmp < t) tmp = -1;
				else tmp -= t;
				if (tmp != -1) tmp += pos[i + 1] - mid1[i + 1];
				if (tmp < t) tmp = -1;
				else tmp -= t;
				if (tmp != -1) tmp += 1;
			}
			dp[1][i + 1] = tmp;
		}
		if (dp[2][i] != -1) {
			int tmp = dp[2][i];
			if (pos2[i + 1] == 0 && mid2[i + 1] == 0) tmp += pos[i + 1] - pos[i];
			if (pos2[i + 1] == 0 && mid2[i + 1] != 0) {
				tmp += mid2[i + 1] - pos[i] - 1;
				if (tmp < t) tmp = -1;
				else tmp -= t;
				if (tmp != -1) tmp += pos[i + 1] - mid2[i + 1] + 1;
			}
			if (pos2[i + 1] != 0 && mid2[i + 1] == 0) {
				tmp += pos[i + 1] - pos[i] - 1;
				if (tmp < t) tmp = -1;
				else tmp -= t;
				if (tmp != -1) tmp += 1;
			}
			if (pos2[i + 1] != 0 && mid2[i + 1] != 0) {
				tmp += mid2[i + 1] - pos[i] - 1;
				if (tmp < t) tmp = -1;
				else tmp -= t;
				if (tmp != -1) tmp += pos[i + 1] - mid2[i + 1];
				if (tmp < t) tmp = -1;
				else tmp -= t;
				if (tmp != -1) tmp += 1;
			}
			dp[2][i + 1] = tmp;
		}
	}
	if (dp[1][m] == -1 && dp[2][m] == -1) {
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	int px, py;
	if (dp[1][m] == -1) py = 2, px = m;
	else py = 1, px = m;
	static int shifts[MAXN], cnts = 0;
	static int x[MAXN], y[MAXN], cnt = 0;
	int now = 0;
	while (px != 1 || py != 1) {
		if (path[py][px]) {
			cnt += now;
			int tx = pos[px] - dp[py][px];
			for (int i = 1; i <= now; i++) {
				tx += t;
				x[cnt - i + 1] = tx;
				y[cnt - i + 1] = py;
			}
			py = 3 - py; now = 0;
			shifts[++cnts] = pos[px];
		} else {
			if (py == 1) now += mid1[px] != 0, now += pos1[px] != 0;
			else now += mid2[px] != 0, now += pos2[px] != 0;
			px = px - 1;
		}
	}
	cnt += now;
	int tx = 0;
	for (int i = 1; i <= now; i++) {
		tx += t;
		x[cnt - i + 1] = tx;
		y[cnt - i + 1] = py;
	}
	writeln(cnts);
	reverse(shifts + 1, shifts + cnts + 1);
	for (int i = 1; i <= cnts; i++)
		printf("%d ", shifts[i]);
	printf("\n");
	writeln(cnt);
	reverse(x + 1, x + cnt + 1);
	reverse(y + 1, y + cnt + 1);
	for (int i = 1; i <= cnt; i++)
		printf("%d %d\n", x[i], y[i]);
	return 0;
}