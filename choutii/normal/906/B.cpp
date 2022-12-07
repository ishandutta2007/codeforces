#include <bits/stdc++.h>

#define fir first
#define sec second
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long LL;
typedef unsigned long long u64;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}
int read() {
	int x = 0, f = 1;char ch;
	for(ch = getchar(); !isdigit(ch); ch = getchar())
		if(ch == '-') f = -1;
	for(; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return x * f;
}

int n, m, ans[101234], vis[101234];

bool chk(int x, int y) {
	return !(x + m == y || x - m == y || (x % m != 1 && x - 1 == y) || (x % m && x + 1 == y));
}

bool dfs(int x, int y) {
	if(x > n) 
		return 1;
	int z = (x - 1) * m + y;
	for(int p = max(z - 10, 1); p <= min(n * m, z + 10); p++) {
		if(vis[p] || (x > 1 && !chk(ans[z - m], p)) || (y > 1 && !chk(ans[z - 1], p))) continue; 
		ans[z] = p; vis[p] = 1;
		if(dfs(x + y / m, y % m + 1))
			return 1;
		vis[p] = 0;
	}
	return 0;
}
int main() {
	int i, j, k;
	n = read(); m = read();
	if(dfs(1, 1)) {
		puts("YES");
		for(k = 1; k <= n * m; k++)
			printf("%d%c", ans[k], " \n"[k % m == 0]);
	}else puts("NO");
	return 0;
}