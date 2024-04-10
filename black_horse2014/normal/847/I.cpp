#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;

const int N = 255;
char s[N][N];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int q[N * N];
int chk[N * N], d[N * N];
long long value[N][N];
int n, m, Q, p;
vector<PII> vec;

bool valid(int x, int y) {
	return (0 <= x && x < n && 0 <= y && y < m);
}

void bfs(int f) {
	int st = 0, en = 0;
	memset(chk, 0, sizeof chk);
	memset(d, 0, sizeof d);
	vec.clear();
	q[en++] = f;
	d[f] = 0;
	chk[f] = 1;
	vec.push_back(PII(f, 0));
	while (st < en) {
		int now = q[st++];
		int x = now >> 8, y = now & 255;
		if (d[now] > 30) continue;
		for (int i = 0; i < 4; i++) {
			if (valid(x + dx[i], y + dy[i]) && s[x+dx[i]][y+dy[i]] != '*') {
				int j = now + dy[i] + (dx[i] * 256);
				if (!chk[j]) {
					d[j] = d[now] + 1;
					q[en++] = j;
					chk[j] = 1;
					vec.push_back(PII(j, d[j]));
				}
			}
		}
	}
}

int main() {
	scanf("%d%d%d%d", &n, &m, &Q, &p);
	for (int i = 0; i < n; i ++) {
		scanf("%s", s[i]);
	}
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			if (s[i][j] == '*') continue;
			if (s[i][j] == '.') continue;
			int pw = Q * (s[i][j] - 'A' + 1);
			int now = (i << 8) + j;
			int cur = 0;
			bfs(now);
			for (int k = 0; k < vec.size(); k ++) {
				int pos = vec[k].first, dd = vec[k].second;
				value[pos>>8][pos&255] += (pw >> dd);
			}
		} 
	} 
	int ans = 0;
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			if (value[i][j] > p) ans++;
		}
	}
	cout << ans << endl;
	return 0;
}