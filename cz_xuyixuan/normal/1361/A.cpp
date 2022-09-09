#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
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
bool vis[MAXN];
int n, m, s[MAXN], p[MAXN];
vector <int> a[MAXN];
int main() {
	read(n), read(m);
	for (int i = 1; i <= m; i++) {
		int x, y; read(x), read(y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
		read(s[i]), p[i] = i;
	sort(p + 1, p + n + 1, [&] (int x, int y) {
		return s[x] < s[y];
	});
	for (int i = 1; i <= n; i++) {
		int pos = p[i];
		static int mark[MAXN];
		for (auto x : a[pos])
			if (vis[x]) mark[s[x]] = pos;
		int res = 1;
		while (mark[res] == pos) res++;
		if (res != s[pos]) {
			puts("-1");
			return 0;
		}
		vis[pos] = true;
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", p[i]);
	printf("\n");
	return 0;
}