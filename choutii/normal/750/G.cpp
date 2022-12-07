#include <bits/stdc++.h>

#define fir first
#define sec second
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

LL n, ans, f[2][150][2];

LL dp(int c, int a, int b, LL v) {
	int i, j, k, x, y;
	memset(f, 0, sizeof(f));
	f[1][0][0] = 1;
	for(i = 0; (1ll << i) <= v; i++) {
		memset(f[i & 1], 0, sizeof(f[i & 1]));
		for(k = 0; k <= c; k++)
			for(x = 0; !x || (x < 2 && a > i); x ++)
				for(y = 0; !y || (y < 2 && b > i); y++) {
					int z = (v >> i & 1) ^ x ^ y;
					f[i & 1][k + x + y][z + x + y >> 1] += f[~i & 1][k][z];
				}
	} 
	return f[~i & 1][c][0];
}

int main() {
	int i;
	cin >> n;
	for(int a = 0; a < 60; a++)
		for(int b = 0; b < 60; b++) {
			LL s = (1ll << a + 1) + (1ll << b + 1) - 3;
			if(s > n) continue;
			LL r = n % s - (1ll << b) + 1;
			for(int c = 0; c <= a + b; c++)
				if(r + c >= 0 && !(r + c & 1))
					ans += dp(c, a - 1, b - 1, r + c >> 1);
		}
	cout << ans << endl; 
	return 0;
}