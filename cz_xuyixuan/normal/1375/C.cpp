#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
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
int main() {
	int T; read(T);
	while (T--) {
		int n; read(n);
		int x = 0, y = 0;
		for (int i = 1; i <= n; i++) {
			int z; read(z);
			if (i == 1) x = z;
			else y = z;
		}
		if (x < y) puts("YES");
		else puts("NO");
	}
	return 0;
}