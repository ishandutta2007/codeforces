#include<bits/stdc++.h>
using namespace std;
#define MAXN	5005
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
map <int, int> a;
int main() {
	int n, ans = 0;
	read(n);
	for (int i = 1; i <= n; i++) {
		int x; read(x);
		int tmp = ++a[x];
		ans = max(ans, tmp);
	}
	cout << ans << endl;
	return 0;
}