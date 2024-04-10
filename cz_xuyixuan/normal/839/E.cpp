#include<bits/stdc++.h>
using namespace std;
#define MAXN	105
#define MAXV	1200005
int n, m, k, ans;
bool mp[MAXN][MAXN];
int rec[MAXV], value[MAXN];
bool visited[MAXN];
void work(int depth, int curr, int cnt) {
	if (depth > m) {
		rec[curr] = cnt;
		return;
	}
	work(depth + 1, curr, cnt);
	for (int i = 1; i < depth; i++)
		if (visited[i] && !mp[i][depth]) return;
	visited[depth] = true;
	work(depth + 1, curr | (1 << depth - 1), cnt + 1);
	visited[depth] = false;
}
void work(int depth, int cnt) {
	if (depth > n) {
		int curr = 0;
		for (int i = 1; i <= m; i++)
			if (value[i] == 0) curr |= 1 << i - 1;
		ans = max(ans, cnt + rec[curr]);
		return;
	}
	work(depth + 1, cnt);
	for (int i = m + 1; i < depth; i++)
		if (visited[i] && !mp[i][depth]) return;
	visited[depth] = true;
	for (int i = 1; i <= m; i++)
		if (!mp[depth][i]) value[i]--;
	work(depth + 1, cnt + 1);
	visited[depth] = false;
	for (int i = 1; i <= m; i++)
		if (!mp[depth][i]) value[i]++;
}
int main() {
	scanf("%d%d", &n, &k);
	m = n / 2;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &mp[i][j]);
	work(1, 0, 0);
	for (int i = 1; i < (1 << m); i++)
		for (int j = 1; j <= m; j++)
			if (i & (1 << j - 1)) rec[i] = max(rec[i], rec[i ^ (1 << j - 1)]);
	work(m + 1, 0);
	printf("%.12lf\n", 0.5 * (ans - 1) / ans * k * k);
	return 0;
}