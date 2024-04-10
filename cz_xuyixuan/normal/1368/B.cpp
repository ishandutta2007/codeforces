#include<bits/stdc++.h>
using namespace std;
const int MAXN = 15;
const char c[11] = {'#', 'c', 'o', 'd', 'e', 'f', 'o', 'r', 'c', 'e', 's'};
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
ll n, a[MAXN];
int main() {
	int m = 10; read(n);
	while (true) {
		for (int i = 1; i <= m; i++) {
			a[i]++;
			ll cur = 1;
			for (int j = 1; j <= m; j++)
				cur *= a[j];
			if (cur >= n) {
				for (int j = 1; j <= m; j++)
					while (a[j]--) putchar(c[j]);
				putchar('\n');
				return 0;
			}
		}
	}
	return 0;
}