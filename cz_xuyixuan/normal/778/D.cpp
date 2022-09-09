#include<bits/stdc++.h>
using namespace std;
const int MAXN = 55;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
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
int n, m;
char s[MAXN][MAXN];
vector <int> ansx[2], ansy[2];
void getplan(vector <int> &ansx, vector <int> &ansy) {
	if (n % 2 == 0) {
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cnt += s[i][j] == 'L';
		while (cnt != 0) {
			int px = 0, py = 0, qx = 0, qy = 0;
			for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (s[i][j] == 'L') {
					bool flg = false;
					for (int k = i + 1; k <= n; k++)
						if (s[k][j] == 'L') {
							flg = true;
							qx = k, qy = j;
							break;
						} else if (s[k][j] == 'R' || s[k][j + 1] == 'L') break;
					if (flg) px = i, py = j;
				}
			if (px == 0) {
				printf("Error!\n");
				exit(0);
			}
			for (int i = px + 1; i <= qx - 1; i += 2) {
				ansx.push_back(i);
				ansy.push_back(py);
			}
			for (int i = px; i <= qx; i += 2) {
				ansx.push_back(i);
				ansy.push_back(py);
				s[i][py] = s[i][py + 1] = 'U';
				s[i + 1][py] = s[i + 1][py + 1] = 'D';
			}
			cnt -= 2;
		}
	} else {
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cnt += s[i][j] == 'U';
		while (cnt != 0) {
			int px = 0, py = 0, qx = 0, qy = 0;
			for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (s[i][j] == 'U') {
					bool flg = false;
					for (int k = j + 1; k <= m; k++)
						if (s[i][k] == 'U') {
							flg = true;
							qx = i, qy = k;
							break;
						} else if (s[i][k] == 'D' || s[i + 1][k] == 'U') break;
					if (flg) px = i, py = j;
				}
			if (px == 0) {
				printf("Error!\n");
				exit(0);
			}
			for (int i = py + 1; i <= qy - 1; i += 2) {
				ansx.push_back(px);
				ansy.push_back(i);
			}
			for (int i = py; i <= qy; i += 2) {
				ansx.push_back(px);
				ansy.push_back(i);
				s[px][i] = s[px + 1][i] = 'L';
				s[px][i + 1] = s[px + 1][i + 1] = 'R';
			}
			cnt -= 2;
		}
	}
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		scanf("\n%s", s[i] + 1);
	getplan(ansx[0], ansy[0]);
	for (int i = 1; i <= n; i++)
		scanf("\n%s", s[i] + 1);
	getplan(ansx[1], ansy[1]);
	writeln(ansx[0].size() + ansx[1].size());
	for (unsigned i = 0; i < ansx[0].size(); i++)
		printf("%d %d\n", ansx[0][i], ansy[0][i]);
	reverse(ansx[1].begin(), ansx[1].end());
	reverse(ansy[1].begin(), ansy[1].end());
	for (unsigned i = 0; i < ansx[1].size(); i++)
		printf("%d %d\n", ansx[1][i], ansy[1][i]);
	return 0;
}