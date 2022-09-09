#include<bits/stdc++.h>
using namespace std;
const int MAXN = 105;
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
int n, d, a[MAXN];
int main() {
	int T; read(T);
	while (T--) {
		read(n), read(d);
		for (int i = 1; i <= n; i++)
			read(a[i]);
		for (int i = 2; i <= n; i++) {
			while (a[i] && d >= i - 1) {
				d -= i - 1;
				a[i]--, a[1]++;
			}
		}
		cout << a[1] << endl;
	}
	return 0;
}