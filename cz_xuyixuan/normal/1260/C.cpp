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
int gcd(int x, int y) {
	while (y != 0) {
		x %= y;
		swap(x, y);
	}
	return x;
}
int main() {
	int T; read(T);
	while (T--) {
		int x, y, z; read(x), read(y), read(z);
		if (z == 1) puts("REBEL");
		else {
			int g = gcd(x, y);
			x /= g, y /= g;
			if (x > y) swap(x, y);
			if (x == y) puts("OBEY");
			else {
				int Max = 1 + (y - 2) / x;
				if (Max < z) puts("OBEY");
				else puts("REBEL");
			}
		}
	}
	return 0;
}