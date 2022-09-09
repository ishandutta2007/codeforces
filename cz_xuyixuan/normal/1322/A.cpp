#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
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
char s[MAXN];
int main() {
	int n; read(n);
	scanf("%s", s + 1);
	int cur = 0, ans = 0, last = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] == '(') {
			cur += 1;
			if (cur == 0) ans += i - last;
		} else {
			cur -= 1;
			if (cur == -1) last = i - 1;
		}
	}
	if (cur != 0) puts("-1");
	else cout << ans << endl;
	return 0;
}