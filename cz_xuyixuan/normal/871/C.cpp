#include<bits/stdc++.h>
using namespace std;
#define MAXN	100005
#define P	1000000007
#define INF	2e9
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
int n, x[MAXN], y[MAXN];
int ax[MAXN], ay[MAXN], cnt;
bool visited[MAXN][2], circle;
vector <int> a[MAXN], b[MAXN];
void visit(int pos, int type, int fa) {
	cnt++; visited[pos][type] = true;
	if (type) {
		for (unsigned i = 0; i < b[pos].size(); i++) {
			if (b[pos][i] == fa) continue;
			if (visited[b[pos][i]][0]) circle = true;
			else visit(b[pos][i], 0, pos);
		}
	} else {
		for (unsigned i = 0; i < a[pos].size(); i++) {
			if (a[pos][i] == fa) continue;
			if (visited[a[pos][i]][1]) circle = true;
			else visit(a[pos][i], 1, pos);
		}
	}
}
bool cmpx(int a, int b) {
	return x[a] < x[b];
}
bool cmpy(int a, int b) {
	return y[a] < y[b];
}
int main() {
	read(n);
	for (int i = 1; i <= n; i++)
		read(x[i]), read(y[i]);
	for (int i = 1; i <= n; i++)
		ax[i] = i, ay[i] = i;
	sort(ax + 1, ax + n + 1, cmpx);
	sort(ay + 1, ay + n + 1, cmpy);
	int now = 0, last = -INF;
	for (int i = 1; i <= n; i++) {
		if (last != x[ax[i]]) now++, last = x[ax[i]];
		x[ax[i]] = now;
	}
	now = 0, last = -INF;
	for (int i = 1; i <= n; i++) {
		if (last != y[ay[i]]) now++, last = y[ay[i]];
		y[ay[i]] = now;
	}
	for (int i = 1; i <= n; i++) {
		a[x[i]].push_back(y[i]);
		b[y[i]].push_back(x[i]);
	}
	long long ans = 1;
	for (int i = 1; i <= now; i++) {
		if (visited[i][1]) continue;
		circle = false;
		cnt = 0; visit(i, 1, 0);
		long long now = 1;
		if (circle) {
			for (int i = 1; i <= cnt; i++)
				now = now * 2 % P;
		} else {
			for (int i = 1; i <= cnt; i++)
				now = now * 2 % P;
			now = (now - 1 + P) % P;
		}
		ans = ans * now % P;
	}
	cout << ans << endl;
	return 0;
}