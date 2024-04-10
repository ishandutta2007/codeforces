#include<bits/stdc++.h>
using namespace std;
const int MAXN = 205;
typedef long long ll;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
bool mp[MAXN][MAXN];
bool ask(int x, int y) {
	if (mp[x][y] || mp[y][x]) return mp[x][y];
	cout << '?' << ' ' << x << ' ' << y << endl;
	char res; scanf("\n%c", &res);
	if (res == '>') mp[x][y] = true;
	else mp[y][x] = true;
	return mp[x][y];
}
int tot, b[MAXN];
pair <int, int> a[MAXN];
int main() {
	int T; read(T);
	while (T--) {
		int n; read(n);
		for (int i = 1; i <= n * 2; i++)
		for (int j = 1; j <= n * 2; j++)
			mp[i][j] = false;
		for (int i = 1; i <= n; i++)
			if (ask(i, i + n)) a[i] = make_pair(i, i + n);
			else a[i] = make_pair(i + n, i);
		sort(a + 1, a + n + 1, [&] (pair <int, int> x, pair <int, int> y) {
			return ask(x.second, y.second);
		}); tot = 0;
		for (int i = 2; i <= n; i++) {
			b[++tot] = a[i].first;
			b[++tot] = a[i].second;
		}
		sort(b + 1, b + tot + 1, [&] (int x, int y) {return ask(x, y); });
		ask(a[1].second, b[n - 1]);
		cout << '!' << endl;
	}
	return 0;
}