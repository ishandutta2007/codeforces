#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
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
int n, m; bool key[MAXN], ans[MAXN];
vector <int> a[MAXN], b[MAXN];
int main() {
	int T; read(T);
	while (T--) {
		read(n), read(m);
		for (int i = 1; i <= n; i++) {
			a[i].clear();
			b[i].clear();
			key[i] = ans[i] = false;
		}
		for (int i = 1; i <= m; i++) {
			int x, y; read(x), read(y);
			a[x].push_back(y);
			b[y].push_back(x);
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			bool res = true;
			for (auto x : b[i]) res &= !key[x];
			if (res) {
				ans[i] = true;
				for (auto x : b[i]) key[i] |= ans[x];
			} else cnt++;
		}
		printf("%d\n", cnt);
		for (int i = 1; i <= n; i++)
			if (!ans[i]) printf("%d ", i);
		printf("\n");
	}
	return 0;
}