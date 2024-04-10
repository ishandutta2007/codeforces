#include <bits/stdc++.h>
using namespace std;

const int N = 1100;
char S[N][N];
int a[N], b[N], c[N];
int n;

void print(int k) {
	printf("%d\n", k);
	for (int i = 0; i < n; i++) printf("%s\n", S[i]);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		--a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) S[i][j] = '.';
	}
	for (int i = 0; i < n; i++) b[a[i]] = i;
	int flg = 0;
	for (int i = 0; i < n; i++) {
		if (b[i] != i) {
			flg = 1;
			break;
		}
	}
	if (!flg) return print(n), 0;
	set<int> se;
	for (int i = 0; i < n; i++) se.insert(i);
	int now = n - 1;
	while (se.size()) {
		int c = *se.rbegin();
		int p = c;
		deque<int> dq;
		do {
			se.erase(p);
			dq.push_back(p);
			p = b[p];
		} while (p != c);
		if (dq.size() == 1) continue;
		int ma = -1;
		for (int x : dq) ma = max(ma, x);
		while (dq.back() != ma) {
			int fr = dq[0];
			dq.pop_front();
			dq.push_back(fr);
		}
		int dn = dq.size();
		now -= dq.size() - 1;
		for (int i = 0; i + 1 < dn; i++) {
			int x = dq[i], y = dq[i+1];
			int level = now + dn - i - 2;
			if (x < y) {
				S[level][x] = S[level][y] = '\\';
			} else {
				S[level][x] = S[level][y] = '/';
			}
		}
		if (dq.back() < n-1) {
			S[now][dq.back()] = '\\';
			S[now][n-1] = '\\';
			S[now+dn-1][n-1] = '/';
			S[now+dn-1][dq[0]] = '/';
		}
		now--;
	}
	print(n-1);
	for (int i = 0; i < n; i++) {
		int cx = 0, cy = i, d = 0;
		int dx[] = {1, 0, -1, 0};
		int dy[] = {0, -1, 0, 1};
		auto valid = [&] (int x, int y) {
			return 0 <= x && x < n && 0 <= y && y < n;
		};
		do {
			if (S[cx][cy] == '/') {
				d ^= 1;
			} else if (S[cx][cy] == '\\') {
				d = 3 - d;
			}
			cx += dx[d], cy += dy[d];
		} while (valid(cx, cy));
		if (cx == n) {
			c[i] = cy;
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (c[i] == b[i]) cnt++;
	}
}