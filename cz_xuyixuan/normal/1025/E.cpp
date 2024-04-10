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
struct point {int x, y; };
point a[MAXN], b[MAXN];
int n, m, homea[MAXN], homeb[MAXN];
bool vis[MAXN];
vector <point> ansx, ansy, bnsx, bnsy;
void getans() {
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= m; i++) {
		//pos -> (1, i);
		int pos = 0, val = 1e9;
		for (int j = 1; j <= m; j++)
			if (!vis[j]) {
				int tmp = abs(a[j].x - 1) + abs(a[j].y - i);
				if (tmp < val) {
					val = tmp;
					pos = j;
				}
			}
		vis[pos] = true;
		homea[pos] = i;
		while (a[pos].y < i) {
			ansx.push_back(a[pos]);
			a[pos].y++;
			ansy.push_back(a[pos]);
		}
		while (a[pos].y > i) {
			ansx.push_back(a[pos]);
			a[pos].y--;
			ansy.push_back(a[pos]);
		}
		while (a[pos].x > 1) {
			ansx.push_back(a[pos]);
			a[pos].x--;
			ansy.push_back(a[pos]);
		}
	}
}
void getbns() {
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= m; i++) {
		//pos -> (1, n);
		int pos = 0, val = 1e9;
		for (int j = 1; j <= m; j++)
			if (!vis[j]) {
				int tmp = abs(b[j].x - n) + abs(b[j].y - i);
				if (tmp < val) {
					val = tmp;
					pos = j;
				}
			}
		vis[pos] = true;
		homeb[pos] = i;
		while (b[pos].y < i) {
			bnsy.push_back(b[pos]);
			b[pos].y++;
			bnsx.push_back(b[pos]);
		}
		while (b[pos].y > i) {
			bnsy.push_back(b[pos]);
			b[pos].y--;
			bnsx.push_back(b[pos]);
		}
		while (b[pos].x < n) {
			bnsy.push_back(b[pos]);
			b[pos].x++;
			bnsx.push_back(b[pos]);
		}
	}
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= m; i++)
		read(a[i].x), read(a[i].y);
	for (int i = 1; i <= m; i++)
		read(b[i].x), read(b[i].y);
	if (n == 1) {
		printf("0\n");
		return 0;
	}
	getans();
	getbns();
	if (n == 2 && homea[1] != homeb[1]) {
		ansx.push_back((point) {1, 1});
		ansy.push_back((point) {2, 1});
		ansx.push_back((point) {2, 1});
		ansy.push_back((point) {2, 2});
		ansx.push_back((point) {1, 2});
		ansy.push_back((point) {1, 1});
		ansx.push_back((point) {1, 1});
		ansy.push_back((point) {2, 1});
	} else {
		for (int i = 1; i <= m; i++) {
			ansx.push_back(a[i]);
			a[i].x++;
			ansy.push_back(a[i]);
			while (a[i].y < b[i].y) {
				ansx.push_back(a[i]);
				a[i].y++;
				ansy.push_back(a[i]);
			}
			while (a[i].y > b[i].y) {
				ansx.push_back(a[i]);
				a[i].y--;
				ansy.push_back(a[i]);
			}
			while (a[i].x < n) {
				ansx.push_back(a[i]);
				a[i].x++;
				ansy.push_back(a[i]);
			}
		}
	}
	writeln(ansx.size() + bnsx.size());
	for (unsigned i = 0; i < ansx.size(); i++)
		printf("%d %d %d %d\n", ansx[i].x, ansx[i].y, ansy[i].x, ansy[i].y);
	reverse(bnsx.begin(), bnsx.end());
	reverse(bnsy.begin(), bnsy.end());
	for (unsigned i = 0; i < bnsx.size(); i++)
		printf("%d %d %d %d\n", bnsx[i].x, bnsx[i].y, bnsy[i].x, bnsy[i].y);
	return 0;
}