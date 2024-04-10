#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
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
int n, a[MAXN];
int main() {
	int T; read(T);
	while (T--) {
		read(n);
		for (int i = 1; i <= n; i++)
			read(a[i]);
		bool draw = true;
		for (int i = 30; i >= 0; i--) {
			int p = 1 << i, x = 0, y = 0;
			for (int j = 1; j <= n; j++)
				if (a[j] & p) x++;
				else y++;
			if (x & 1) {
				if (y % 2 == 0 && x % 4 == 3) puts("LOSE");
				else puts("WIN");
				draw = false;
				break;
			}
		}
		if (draw) puts("DRAW");
	}
	return 0;
}